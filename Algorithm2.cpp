#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int max (int a, int b) {
    return a > b ? a : b;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    // Enumerate all pairs of distinct lowercase letters
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
            int i = 0;
            while (i < n) {
                // Skip chars outside {c1,c2}
                while (i < n && s[i] != c1 && s[i] != c2)
                    ++i;
                // Process the segment
                unordered_map<int,int> firstIdx;
                firstIdx[0] = 0;
                int sum = 0, len = 0;
                while (i + len < n && (s[i + len] == c1 || s[i + len] == c2)) {
                    sum += (s[i + len] == c1 ? 1 : -1);
                    ++len;
                    if (!firstIdx.count(sum))
                        firstIdx[sum] = len;
                    else
                        ans = max(ans, len - firstIdx[sum]);
                }
                i += len;
            }
        }
    }

    cout << ans;
}


int main() {
    solve();
    return 0;
}