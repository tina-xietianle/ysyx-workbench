#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
 
  const char *temp = fmt;
  int num, i = 0, length = 0;
  const char *str;
  char num_s[1000];
  
  while (*temp != '\0') {
    if (*temp == '%') {
      temp++;
      int width = 0;
      char padding = ' ';
      if (*temp == '0') {
        padding = '0';
        temp++;
      }//前导0填充
      while (*temp >= '0' && *temp <= '9') {
        width = width * 10 + (*temp - '0');
        temp++;
      }//根据ascii码算宽度，10就是10
      switch(*temp) {
        case 'd': {
          num = va_arg(args, int);
          if (num < 0) {
            putch('-');
            length++;
            num = -num;
          }
          i = 0;
          if (num == 0) {
            num_s[i++] = '0';
          } else {
            while (num > 0) {
              num_s[i++] = num % 10 + '0';
              num /= 10;
            }
          }
          int digits = i;
          int pad_len = width > digits ? width - digits : 0;
          for (int j = 0; j < pad_len; j++) {
            putch(padding);
            length++;
          }
            while (i > 0) {
              putch(num_s[--i]);
              length++;
            }
          break;
        } 
        case 'l': { // 处理%ld和%lx
          temp++;
          if (*temp == 'd') {
            long num = va_arg(args, long);
            if (num < 0) {
              putch('-');
              length++;
              num = -num;
            }
            i = 0;
            if (num == 0) {
              num_s[i++] = '0';
            } else {
              while (num > 0) {
                num_s[i++] = num % 10 + '0';
                num /= 10;
              }
            }
            int digits = i;
            int pad_len = width > digits ? width - digits : 0;
            for (int j = 0; j < pad_len; j++) {
              putch(padding);
              length++;
            }
            while (i > 0) {
              putch(num_s[--i]);
              length++;
            }
          } else if (*temp == 'x') {
            unsigned long num = va_arg(args, unsigned long);
            i = 0;
            if (num == 0) {
              num_s[i++] = '0';
            } else {
              while (num > 0) {
                int digit = num % 16;
                num_s[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
                num /= 16;
              }
            }
            int digits = i;
            int pad_len = width > digits ? width - digits : 0;
            for (int j = 0; j < pad_len; j++) {
              putch(padding);
              length++;
            }
            while (i > 0) {
              putch(num_s[--i]);
              length++;
            }
          }
          break;
        }
        case 'p': { // 指针，按十六进制输出
          uintptr_t num = (uintptr_t)va_arg(args, void *);
          putch('0'); putch('x'); length += 2;
          i = 0;
          if (num == 0) {
            num_s[i++] = '0';
          } else {
            while (num > 0) {
              int digit = num % 16;
              num_s[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
              num /= 16;
            }
          }
          while (i > 0) {
            putch(num_s[--i]);
            length++;
          }
          break;
        }
        case 's': {
          str = va_arg(args, const char *);
          i = 0;
          while (str[i] != '\0') {
            putch(str[i]);
            i++;
            length++;
          }
          break;
        }
        case 'x': {
          num = va_arg(args, int);
          i = 0;
          if (num == 0) {
            num_s[i++] = '0';
          } else {
            while (num > 0) {
              int digit = num % 16;
              num_s[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
              num /= 16;
            }
          }
          // 计算填充
          int digits = i;
          int pad_len = width > digits ? width - digits : 0;
          for (int j = 0; j < pad_len; j++) {
            putch(padding);
            length++;
          }
          // 反向输出
          while (i > 0) {
            putch(num_s[--i]);
            length++;
          }
          break;
        }
        default: {
          putch('%');
          putch(*temp);
          length += 2;
          break;
        }
      }
    } else {
      putch(*temp);
      length++;
    }
    temp++;
  }
  
  va_end(args);
  return length;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start (args , fmt);
  const char *temp = fmt;
  int num,sum=0,i=0;
  const char *str;
  char num_s[1000];
  while (*temp!='\0'){
    if(*temp == '%')
    {
      temp++;
      switch(*temp){
        case 'd' :{
          num = va_arg(args, int);
          i=0;
          while(num>=10){
            num_s[i]=num%10;
            i++;
            num=num/10;
          }
          num_s[i]=num;
          num_s[i+1]='\0';
          while(i>=0){
            out[sum]=num_s[i]+'0';
            i--;
            sum++;
          }
          break;
        }      
        case 's' :{
          str = va_arg(args, const char *);
          i=0;
          while(str[i]!='\0'){
            out[sum]=str[i];
            i++;
            sum++;
          }
          break;
        }
        default :{
          out[sum]='%';
          sum++;
          out[sum]=*temp;
          sum++;
          break;
        }
      }
    }
    else{
      out[sum]=*temp;
      sum++;
    }
    temp++;
  }
  out[sum]='\0';
  va_end(args);
  return sum;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
