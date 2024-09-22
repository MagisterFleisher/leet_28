#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "include/string_check.h"
#define BIGNUM 10000000

 void profileMyStringFunc(char* current_string) {
  size_t my_string_length = 0;
  //uint16_t uint_my_string_length = 0;
  for(uint32_t index = 0; index < 10000; index++) {
    my_string_length = stringLength(current_string, false);
  }
/*   uint_my_string_length = (uint16_t) my_string_length;
  (void) printf("1 my_string_length: %zu\tsize of size_t: %zu\n", my_string_length, sizeof(my_string_length));
  (void) printf("1 my_string_length: %d\tsize of uint16_t: %zu\n", uint_my_string_length, sizeof(uint_my_string_length)); */
  return;
}


 void profileMyStringFunc2(char* current_string) {
  size_t my_string_length = 0;
  //uint16_t uint_my_string_length = 0;
  for(uint32_t index = 0; index < BIGNUM; index++) {
    my_string_length = stringLength2(current_string);//, false);
  }
  // uint_my_string_length = (uint16_t) my_string_length;
  //(void) printf("1 my_string_length: %zu\tsize of size_t: %zu\n", my_string_length, sizeof(my_string_length));
//  (void) printf("1 my_string_length: %d\tsize of uint16_t: %zu\n", uint_my_string_length, sizeof(uint_my_string_length));
  return;
}

void profileStdStringFunc(char* current_string) {
  size_t my_string_length = 0;
  for(uint32_t index = 0; index < BIGNUM; index++) {
    my_string_length = strlen(current_string);
  }
  // (void) printf("2 my_string_length: %zu\n", my_string_length);
  return;
}

void profstr(char* current_string) {
 size_t my_string_length = 0;
for(uint32_t index = 0; index < BIGNUM; index++) {
    my_string_length = stringLength2(current_string);//, false);
  }
  return;
}
int main(int argument_count, char** argument_vector) {
  int error = 0;

  char* current_string = "hello";

  //profileMyStringFunc2(current_string);
  //profileMyStringFunc(current_string);
  profileStdStringFunc(current_string);
  profstr(current_string);
  // (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
/* 
  char* haystack0 = "sadbutsad";
  char* needle0 = "sad";

  char* haystack1 = "s";
  char* needle1 = "sad";

  char* haystack2 = "s";
  char* needle2 = "s";

  char* haystack3 = "s";
  char* needle3 = "d";

  char* haystack4 = "s";
  char* needle4 = "sd";

  char* haystack5 = "sh";
  char* needle5 = "si";

  char* haystack6 = "sit";
  char* needle6 = "sit";

  
  char* haystack = "leetcode";
  char* needle = "leeto";


  // int first_occurence = strStr(haystack, needle);
  //(void) profileMyStringFunc(haystack);
  //(void) profileStdStringFunc(haystack);

  (void) printf("case 0 first occurence: %d\n", strStr(haystack0, needle0));
  (void) printf("case 1 first occurence: %d\n", strStr(haystack1, needle1));
  (void) printf("case 2 first occurence: %d\n", strStr(haystack2, needle2));
  (void) printf("case 3 first occurence: %d\n", strStr(haystack3, needle3));
  (void) printf("case 4 first occurence: %d\n", strStr(haystack4, needle4));
  (void) printf("case 5 first occurence: %d\n", strStr(haystack5, needle5));
  (void) printf("case 6 first occurence: %d\n", strStr(haystack6, needle6));
 */
  return error;
}