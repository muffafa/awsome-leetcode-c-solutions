# [C Algorithm: Longest Substring Without Repeating Characters (Sliding Window)](https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/3140512/c-algorithm-longest-substring-without-repeating-characters-sliding-window/)

## Approach
<!-- Describe your approach to solving the problem. -->
The algorithm solves the problem of finding the length of the longest substring without repeating characters by using a sliding window approach. The basic idea is to keep a record of the last occurrence of each character in a hash table, and use this information to determine the start of the current non-repeating substring.

Here's how the algorithm works:

1. Initialize two variables, `start` and `max_len`, to keep track of the start of the current non-repeating substring and the maximum length of a non-repeating substring, respectively.
2. Iterate through the input string `s` and for each character, `c`, check if its last occurrence is greater than or equal to `start`. If it is, update `start` to be one greater than the last occurrence of `c`.
3. Update the last occurrence of `c` in the hash table to the current position in the string.
4. Update `max_len` to be the maximum of the current length of the non-repeating substring (calculated as the difference between the current position and `start`) and `max_len`.
5. Repeat steps 2 to 4 for every character in the string until the end of the string is reached.
6. Return `max_len` as the answer.

This approach has a time complexity of O(n), where n is the length of the input string, since it iterates through the string only once.

## Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$ -->
The time complexity of the algorithm to find the length of the longest substring without repeating characters is $O(n)$, where $n$ is the length of the input string.

This is because the algorithm iterates through the input string only once, and for each character, it takes constant time to look up the last occurrence of that character in the hash table and update the start of the current non-repeating substring and the maximum length if necessary. The hash table operations have a constant time complexity, so the overall time complexity is proportional to the length of the input string.

Therefore, the algorithm has a linear time complexity, making it efficient for finding the longest non-repeating substring in a string of any size.

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$ -->
The space complexity of the algorithm to find the length of the longest substring without repeating characters is $O(k)$, where $k$ is the number of distinct characters in the input string.

This is because the algorithm uses a hash table to store the last occurrence of each character in the string. The size of the hash table is proportional to the number of distinct characters in the input string, so if the input string contains $k$ distinct characters, the hash table will take up $O(k)$ space.

Additionally, the algorithm uses a few variables to keep track of the start of the current non-repeating substring and the maximum length, which take up a constant amount of space.

Therefore, the overall space complexity of the algorithm is $O(k)$, making it efficient for strings with a small number of distinct characters. If the input string contains a large number of distinct characters, the space complexity may become a concern.

## Code

``` c
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
```
