#include <stdio.h>
#include <string.h>
#include "include/string_check.h"
#define BIGNUM 100000000

 void profileMyStringFunc(char* current_string) {
  uint16_t my_string_length = 0;
  for(uint32_t index = 0; index < BIGNUM; index++) {
    my_string_length = stringLength(current_string, false);
  }
//  (void) printf("1 my_string_length: %d\n", my_string_length);
  return;
}

void profileStdStringFunc(char* current_string) {
  size_t my_string_length = 0;
  for(uint32_t index = 0; index < BIGNUM; index++) {
    my_string_length = strlen(current_string);
  }
  //(void) printf("2 my_string_length: %zu\n", my_string_length);
  return;
}

int main(int argument_count, char** argument_vector) {
  int error = 0;
  // (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  char* haystack = "sadbutsad";
  char* needle = "sad";

  /*
  char* haystack = "leetcode";
  char* needle = "leeto";
  */

  //int first_occurence = strStr(haystack, needle);
  (void) profileMyStringFunc(haystack);
  (void) profileStdStringFunc(haystack);
  
  return error;
}