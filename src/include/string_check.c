#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}

size_t stringLength(char* current_string, bool with_nullchar) {
  if(with_nullchar) { return sizeof(current_string); }
  return (sizeof(current_string) - 1); }

int strStr(char* haystack, char* needle) {
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
    
    return first_occurence;
}