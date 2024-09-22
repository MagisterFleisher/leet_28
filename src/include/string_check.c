#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}

size_t stringLength(char* current_string, bool with_nullchar) {
  size_t len = 0;
  while('\0' != current_string[len]) { len++; }
  if(with_nullchar) { return len + 1; }
  return len;
}
/* 
size_t stringLength2(char* current_string) {
  size_t len = 0;
  while(0 ^ current_string[len]) { 
    len++; }
  return len;
  }
 */

size_t stringLength2(char* current_string) {
  //size_t len = 0;
  char* b = current_string;
  while(0 ^ *b) { 
    b++; }
  //(void) printf("%zu\n", (b - current_string));
  return (b - current_string);
}

bool is_match(char* haystack, char* needle, uint16_t haystack_start, uint16_t needle_length) {
  bool is_same = true;
  for(int index = 0; index < needle_length; index++) {
    if(haystack[haystack_start + index] != needle[index]) {
      is_same = false;
    }
  }
  return is_same;
}

int strStr(char* haystack, char* needle) {
    enum switch_cases {
      WRONG_SIZE = 1,
      SAME_SIZE_NOT_1 = 2,
      NEEDLE_1 = 3,
      BOTH_1 = 4
    };
    int first_occurence = -1;
    /* 
    Trivial Cases: 
      1) Size of haystack == 0 => return -1
      2) size of needle == 0 => return -1
      3) size of haystack < size of needle => return -1
    Basic Cases:
      1) Size of (haystack == 1) && (size of needle == 1)
      2) Size of needle == 1
      3) size of haystack == size of needle
    Non Basic Cases:
      1) Size of haystack > 1 && size of needle > 1
        1.1) Size of haystack not very big
        1.2) Size of haystack very big

    Note:
      The search space is (size of haystack - size of needle)
    
    Parallizable:
      Yes.  If big enough, start seaching by chunking up the search space.
    */
    uint16_t haystack_length = (uint16_t) stringLength(haystack, false);
    uint16_t needle_length = (uint16_t) stringLength(needle, false);
    bool haystack_length_0 = (0 == haystack_length);
    bool needle_length_0 = (0 == needle_length);
    bool needle_length_1 = (1 == needle_length);
    bool haystack_length_1 = (1 == haystack_length);
    bool haystack_less_needle = (haystack_length < needle_length);
    bool haystack_same_needle = (haystack_length == needle_length);

    uint16_t is_wrong_size = (haystack_length_0 || needle_length_0 || haystack_less_needle);
    uint16_t is_same_size_not_1 = 2 * (haystack_same_needle & !needle_length_1);
    uint16_t is_needle_1 = 3 * (needle_length_1 && !haystack_less_needle && !haystack_same_needle);
    uint16_t is_both_1 = 4 * (needle_length_1 && haystack_length_1);
    uint16_t case_value = is_wrong_size + is_same_size_not_1 + is_needle_1 + is_both_1;
/* 
    (void) printf("haystack: %s\tneedle:%s\n", haystack, needle);
    (void) printf("haystack_length: %d\tneedle_length:%d\n", haystack_length, needle_length);

    (void) printf("haystack_length_0: %d\n", haystack_length_0);
    (void) printf("needle_length_0: %d\n", needle_length_0);

    (void) printf("haystack_length_1: %d\n", haystack_length_1);
    (void) printf("needle_length_1: %d\n", needle_length_1);
    
    (void) printf("haystack_length_bigger: %d\n", haystack_length_bigger);
    (void) printf("needle_length_bigger: %d\n", needle_length_bigger);
    
    (void) printf("haystack_less_needle: %d\n", haystack_less_needle);
    (void) printf("haystack_same_needle: %d\n", haystack_same_needle);
    (void) printf("\n\n");
 */
/*     uint16_t case_value = case_value1 + case_value2 + case_value3 + case_value4; */

    switch(case_value) {
      case WRONG_SIZE : {
        (void) printf("%s %d- WRONG SIZE\thaystack: %s\tneedle:%s\n",__func__, __LINE__, haystack, needle);
        break;
      };
      case BOTH_1 : {
        if(haystack[0] == needle[0]) { first_occurence = 0; }
        (void) printf("%s %d- SAME SIZE\thaystack: %s\tneedle:%s\n", __func__, __LINE__, haystack, needle);
        break;
      };
      case SAME_SIZE_NOT_1 : {
        char* tmp_haystack_0 = haystack;
        char* tmp_needle_0 = needle; 
        uint16_t tmp_same = 0;
        while('\0' != *tmp_haystack_0) {
          if(*tmp_haystack_0 != *tmp_needle_0) {
            tmp_same++;} 
          tmp_haystack_0++;
          tmp_needle_0++;
        }
        if(0 == tmp_same) { first_occurence = 0; }
        (void) printf("%s %d- SAME SIZE\thaystack: %s\tneedle:%s\n", __func__, __LINE__, haystack, needle);
        break;
      };
      case NEEDLE_1  : {
        (void) printf("%s %d- NEEDLE 1\thaystack: %s\tneedle:%s\n", __func__, __LINE__, haystack, needle);
        char* tmp_haystack_1 = haystack;
        uint16_t tmp_index = 0;
        while('\0' == *tmp_haystack_1) {
          if(*tmp_haystack_1 == needle[0]) {
            first_occurence = (int) tmp_index;
          } else {
            tmp_haystack_1++;
            tmp_index++;
          }
        }
        break;
      };
      default: {
        (void) printf("%s %d- default\thaystack: %s\tneedle:%s\n", __func__, __LINE__, haystack, needle);
        for(int16_t index = 0; index < (haystack_length - needle_length); index++) {
          //(void) printf("Haystack char %c\tneedle 0 char%c\n", haystack[index], needle[0]);
          if(needle[0] == haystack[index] && (haystack[index + (needle_length -1)], needle[(needle_length-1)])) {
            /* (void) printf("Haystack char %c\tneedle 0 char%c\n", haystack[index], needle[0]);
            (void) printf("Haystack + needle_length char %c\tneedle[needle_length-1] char %c\n", haystack[index + (needle_length -1)], needle[(needle_length-1)]);
            (void) printf("is match? %d\n", is_match(haystack, needle, index, needle_length)); */
            if( is_match(haystack, needle, index, needle_length)) {
              return index;
            }
          }
        }
      }
    }

    return first_occurence;
}