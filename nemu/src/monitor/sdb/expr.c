/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/vaddr.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NUM, TK_NUM16, TK_REG, TK_NOTEQ, TK_LESST, TK_GREATT, TK_LESSE, TK_GREATE, TK_AND, TK_OR, TK_DEREF
	
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal
  {"\\(", '('},         // 左括号
  {"\\)", ')'},         // 右括号
  {"\\-", '-'},         // 减法
  {"\\*", '*'},         // 乘法
  {"\\/", '/'},         // 除法
  {"0[xX][0-9A-Fa-f]+", TK_NUM16},//16进制,不能和下面换
  {"[0-9]+", TK_NUM},  //数字串
  //{"<", TK_LESST},
  //{"<=", TK_LESSE},
  //{">",TK_GREATT},
  //{">=",TK_GREATE},
  {"!=",TK_NOTEQ},
  {"&&",TK_AND},
  {"\\|\\|",TK_OR},
  {"\\${1,2}\\w+",TK_REG}, 

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {//编译正则表达式
  int i;
  char error_msg[128];//用于存储错误信息的字符数组
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}
//编译一组正则表达式，存储在re数组中，用于后续的匹配
typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[6536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
	int position = 0;
	int i,last=0;
	int media;
	uint32_t temp=0;
	regmatch_t pmatch;
	bool success=true;
	nr_token = 0;
	tokens[0].type=TK_NOTYPE;
	while (e[position] != '\0') {  //如果位置的地方为字符串的末尾\0，则停止循环
    /* Try all rules one by one. */
		for (i = 0; i < NR_REGEX; i ++) {  //与rule数组进行匹配
			if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
				char *substr_start = e + position;//记录此次循环扫描的起始地址
				int substr_len = pmatch.rm_eo;//特殊符号，长度都为1,像TK_NUM类型，就需要记住长度，不然不知道，下一循环的起始。

//				Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",i, rules[i].regex, position,  substr_len, substr_len,substr_start);
				media=0;
				position += substr_len;//增加步长，为下一循环提供起始位置。

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
				if(rules[i].token_type==256) //如果是空格，则直接读下一个字符
					break;
				tokens[nr_token].type= rules[i].token_type; 	//将读取的字符类型，记录到tokens数组的type成员里
				if(tokens[nr_token].type==TK_NUM &&tokens[nr_token-1].type==TK_NUM)	
				{
					nr_token--;
					media=1;
				}
				switch (rules[i].token_type) {    
					case TK_NUM: case TK_REG: case TK_NUM16:	//将，num,reg的内容记录到tokens数组的str成员中
						
						if(media==1){
							strncpy(&tokens[nr_token].str[last],substr_start,substr_len);		
							tokens[nr_token].str[substr_len+last]= '\0';  //为字符串结束
						}
						else{
							strncpy(tokens[nr_token].str,substr_start,substr_len);
							tokens[nr_token].str[substr_len]= '\0';  //为字符串结束
						}
						//printf("%d: %d %s\n",nr_token,tokens[nr_token].type,tokens[nr_token].str);
                        //tokens[nr_token].str[substr_len]= '\0';  //为字符串结束
						last=strlen(tokens[nr_token].str);
						if(rules[i].token_type==TK_NUM16)//将16进制转换为10进制数，再写回去，就可以将16进制转换为10进制
						{
							
							sscanf(tokens[nr_token].str,"%x",&temp);
							
							sprintf(tokens[nr_token].str,"%u",temp);
							tokens[nr_token].type=TK_NUM;
						}
						if(rules[i].token_type==TK_REG)//传入数组除去$符号的给isa函数，然后得到寄存器数值，之后也以TK_NUM型存在
						{
							temp=isa_reg_str2val(&tokens[nr_token].str[1],&success);
							if(!success){
								printf("can't find register\n");
								return false;
							}
							sprintf(tokens[nr_token].str,"%u",temp);
							tokens[nr_token].type=TK_NUM;
						}
						
						break;
					case TK_AND: case TK_OR: case '+': case '-': case '/': case '(': case ')': case TK_EQ: case TK_NOTEQ:
						break;
					case '*':
						if(nr_token==0||((tokens[nr_token-1].type!=TK_NUM)&&(tokens[nr_token-1].type!=')')))
							tokens[nr_token].type=TK_DEREF;
						break;
					default:
							printf("erro: match fail\n");
							return false;
				}
				nr_token++;
				break;
			}
		}

		if (i == NR_REGEX) {
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
			return false;
		}
	}

	return true;
}
int find_master(int p,int q)
{
	int i,op=p,num=0;
	for(i=p;i<=q;++i)
	{
		switch(tokens[i].type){
			case TK_DEREF:
				if(tokens[op].type!='*' &&tokens[op].type!='/' &&tokens[op].type!='-' &&tokens[op].type!='+' &&tokens[op].type!=TK_EQ &&tokens[op].type!=TK_NOTEQ &&tokens[op].type!=TK_AND &&tokens[op].type!=TK_OR &&num==0)
					op=i;
				break;

			case '*': case '/':
				if(tokens[op].type!='-' &&tokens[op].type!='+' &&tokens[op].type!=TK_EQ &&tokens[op].type!=TK_NOTEQ &&tokens[op].type!=TK_AND &&tokens[op].type!=TK_OR &&num==0)
					op=i;
				break;
			case '+': case '-':
				if(num==0 &&tokens[op].type!=TK_EQ &&tokens[op].type!=TK_NOTEQ &&tokens[op].type!=TK_AND &&tokens[op].type!=TK_OR)
					op=i;
				break;
			case '(':
				num++;
				break;
			case ')':
				num--;
				break;
			case TK_EQ: case TK_NOTEQ:
				if(num==0 && tokens[op].type!=TK_AND &&tokens[op].type!=TK_OR)
					op=i;
				break;
			case TK_AND: case TK_OR:
				if(num==0)
					op=i;
				break;
			case TK_NUM:
				break;
			default: 
				printf("erro,type fault\n");
				return 0;
		}
	}
		return op;
}
bool check_parentheses (int p, int q )
{
	if(tokens[p].type=='(' && tokens[q].type==')')
	{
		int num=0,i;
		for(i=p;i<=q;++i)
		{
			if(tokens[i].type=='(')
				num++;
			if(tokens[i].type==')')
				num--;
			if(num==0 && i==q)
				return true;
			else if (num==0 && i!=q)
				return false;
		}
	}
	return false;
}
word_t eval(int p, int q,bool *success) {
	int x,op,op_type;
	word_t val1,val2;
	bool success1=true,success2=true;
	
  if (p > q) {
		*success=false;
    /* Bad expression */
		printf("erro: head position greater than tail position.\n");
		return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
	if(tokens[p].type==TK_NUM ){
		sscanf(tokens[p].str , "%d" , &x);
		//printf("%d",x);
		return x;
	}
	else{
		*success=false;
		printf("erro ,the single token isn't a number.\n");
		return 0;
	}
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1,success);
  }
  else {
    op = find_master(p,q);
	//printf("%c %d\n",tokens[op].type,op);
	if(op==p)
		val1=0;
	else
		val1 = eval(p, op - 1,&success1);
    val2 = eval(op + 1, q,&success2);
	if(!success1 || !success2){
		*success=false;
		return 0;
	}

	op_type=tokens[op].type;
    switch (op_type) {
		case TK_DEREF: 
			if(val2<2147483648 ||val2>2281701375)
			{
				printf("It is not in range\n");
				*success=false;
				return 0;
			}
			else	
				return vaddr_read(val2,4);//这个函数会调用src/memory/paddr.c里面的paddr_read函数然后读取模拟内存数组pmem
		case TK_EQ: return val1 == val2;
		case TK_NOTEQ: return val1 != val2;
		case '+': return val1 + val2;
		case '-': return val1 - val2;
		case '*': return val1 * val2;
		case TK_AND: return val1 && val2;
		case TK_OR: return val1 || val2;
		case '/':
			if(val2==0)
			{
				printf("erro,can't devide 0\n");
				return 0;
			}	
			else
				return val1 / val2;
		
      default: assert(0);
    }
  }
}

word_t expr(char *e, bool *success) {
//	int i=0;
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  if (tokens[0].type==TK_NOTYPE){
	  printf("all notype\n");
	  *success = false;
	  return 0;
  }
//	for( i=0;i<nr_token;i++){
	//	printf("%d",tokens[i].type);
//		switch(tokens[i].type){
//			case TK_NUM:
//				printf("| NUM ");
//				break;
//			case '+':
//				printf("| \'+\' ");
//				break;
//			case '-':
//				printf("| \'-\' ");
//				break;
//			case '*': case TK_DEREF:
//				printf("| \'*\' ");
//				break;
//			case '/':
//				printf("| \'/\' ");
//				break;
//			case '(':
//				printf("| \'(\' ");
//				break;
//			case ')':
//				printf("| \')\' ");
//				break;
//			case TK_EQ:
//				printf("| \'==\' ");
//				break;
//			case TK_AND:
//				printf("| \'&&\' ");
//				break;
//			case TK_OR:
//				printf("| \'||\' ");
//				break;
//			case TK_NOTEQ:
//				printf("| \'!=\' ");
//				break;
//			default:
//				printf("Don't have this symbol\n");
//		}
//	}
//	printf("|\n");
//	 for(i=0;i<nr_token;i++){
//		if(tokens[i].type==TK_NUM)
//			printf("| \"%s\" ",tokens[i].str);
//		else
//		printf("|     ");
//	}
//	printf("|\n");
//	printf("nr:%d\n",nr_token);
  /* TODO: Insert codes to evaluate the expression. */
//  TODO();

	return eval(0,nr_token-1,success);
}

