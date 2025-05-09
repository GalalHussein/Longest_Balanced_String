#include <stdio.h>
#include <string.h>

#define MAX_N 100000
#define OFFSET 100000 // To handle negative sums in the array

int max(int a, int b) {
    return a > b ? a : b;
}

void solve() {
    char s[MAX_N + 1];
    scanf("%s", s);
    int n = strlen(s), ans = 0;
    
    // Enumerate all pairs of distinct lowercase letters
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
            int i = 0;
            while (i < n) {
                // Skip chars outside {c1,c2}
                while (i < n && s[i] != c1 && s[i] != c2)
                    ++i;
                
                // Process the segment
                int firstIdx[2 * OFFSET + 1]; // Array to store first occurrence of each sum
                for (int j = 0; j <= 2 * OFFSET; j++) {
                    firstIdx[j] = -1; // Initialize with -1 (not seen)
                }
                firstIdx[OFFSET] = 0; // Sum 0 starts at position 0
                
                int sum = 0, len = 0;
                while (i + len < n && (s[i + len] == c1 || s[i + len] == c2)) {
                    sum += (s[i + len] == c1 ? 1 : -1);
                    ++len;
                    
                    // Check if we've seen this sum before
                    if (firstIdx[sum + OFFSET] == -1) {
                        firstIdx[sum + OFFSET] = len;
                    } else {
                        ans = max(ans, len - firstIdx[sum + OFFSET]);
                    }
                }
                i += len;
            }
        }
    }

    printf("%d", ans);
}

int main() {
    solve();
    return 0;
}