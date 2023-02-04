#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

int lengthOfLongestSubstring(char* s) {
    int last_occurrence[MAX_CHARS];
    int start = 0;
    int max_len = 0;

    memset(last_occurrence, -1, sizeof(last_occurrence));

    for (int i = 0; s[i]; i++) {
        if (last_occurrence[s[i]] >= start) { //check for that letter readed before
            start = last_occurrence[s[i]] + 1;  //if it is slide start point to one right of that point abcd+c =>  dc is new substring
        }
        last_occurrence[s[i]] = i;  //update last occurence of that letter
        max_len = (i - start + 1 > max_len) ? (i - start + 1) : max_len;  //check current is longest or not 
    }

    return max_len;
}

int main() {
    char s[] = "abcdabcdfbbd";
    printf("Length of the longest substring without repeating characters: %d\n", lengthOfLongestSubstring(s));
    return 0;
}