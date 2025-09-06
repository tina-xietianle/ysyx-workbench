#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while (*s != '\0') {
    len++;
    s++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  int cursor=0;
  while(cursor<=strlen(src)){
    dst[cursor]=src[cursor];
    cursor++;
  }
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  int cursor=0;
  while(cursor<=strlen(src)){
    if(cursor==n){
      dst[n]='\0';
      return dst;
    }
    dst[cursor]=src[cursor];
    cursor++;
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  size_t len_dst = 0, len_src = 0;
  size_t cursor,i=0;
  len_dst = strlen (dst);
  len_src = strlen (src);
  cursor = len_dst;
  while (i<=len_src)
  {
    dst[cursor+i]=src[i];
    i++;
  }
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  int arrow1 = 0, arrow2 = 0;
  while (s1[arrow1] != '\0' && s2[arrow2] != '\0') {
    if (s1[arrow1] != s2[arrow2]) {
      return s1[arrow1] - s2[arrow2];
    }
    arrow1++;
    arrow2++;
  }
  return s1[arrow1] - s2[arrow2];
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int arrow1 = 0, arrow2 = 0;
  while (s1[arrow1] != '\0' && s2[arrow2] !='\0' && arrow1<n && arrow2<n){
    if(s1[arrow1] != s2[arrow2]) {
      return s1[arrow1] -s2[arrow2];
    }
    arrow1++;
    arrow2++;
  }
  if(arrow1==n && arrow2==n)
    return 0;
  else
    return s1[arrow1] - s2[arrow2];
    
}

void *memset(void *s, int c, size_t n) {
  unsigned char *str = s ;
  size_t i=0;
  while(i<n){
    str[i]=c;
    i++;
  }
  return s;
}

void *memcpy(void *out, const void *in, size_t n) {
  char *dst = (char *) out;
  const char *src = (const char *) in;
  
  while (n--) {
    *dst++ = *src++;
  }
  
  return out;
}
void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = dst;
  const unsigned char *s = src;
  if (d == s || n == 0) return dst;
  if (d < s) {
    // 正向拷贝
    for (size_t i = 0; i < n; i++)
      d[i] = s[i];
  } else {
    // 反向拷贝，防止重叠覆盖
    for (size_t i = n; i > 0; i--)
      d[i-1] = s[i-1];
  }
  return dst;
}
int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *str1 = s1;
  const unsigned char *str2 = s2;
  while(n>0 && *str1 != '\0' && *str2 != '\0')
  {
    if(*str1 != *str2)
      return *str1 - *str2;
    str1++;
    str2++;
    --n;
  }
  if (n==0)
    return 0;
  else
    return *str1 - *str2;
}

#endif
