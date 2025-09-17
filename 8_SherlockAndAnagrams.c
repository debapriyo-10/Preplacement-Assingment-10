
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sherlockAndAnagrams(char* s) {
    int n = strlen(s);
    int count = 0;
    for (int len = 1; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int freq1[26] = {0};
            for (int k = 0; k < len; k++) freq1[s[i+k]-'a']++;
            for (int j = i+1; j + len <= n; j++) {
                int freq2[26] = {0};
                for (int k = 0; k < len; k++) freq2[s[j+k]-'a']++;
                int same = 1;
                for (int x = 0; x < 26; x++) if (freq1[x] != freq2[x]) { same = 0; break; }
                if (same) count++;
            }
        }
    }
    return count;
}
