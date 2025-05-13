
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// init Glopal variable, to be easy to track.
int ans = 0, n;
string s;

// this function move on the string with fixed size.
void SlidWindow (int l, int len) {
    int r = l + len;     // compute the right boundry.
    if (r >= n) return;  // base Case.

    int freq[256] = {0}; // init frequency array.
    for (int i = l; i <= r; i++) freq[s[i]] ++; // memorize the frequency of each letter.

    int count = 0, val1 = 0, val2 = 0;
    for (int i = 0; i < 256; i++) { // loop on freq array to get info about current segment.
        if (freq[i] > 0) { // some letter here.
            count ++;
            if (count == 1) val1 = freq[i]; // it's fisrt letter.
            else if (count == 2) val2 = freq[i]; // it's a second letter.
            else break; // it's more than two letter (not valid), var count now equal exactly 3.
        }
    }

    if (count == 2 and val1 == val2) { // this is valid substring
        ans = max (ans, len + 1);  // maximize the answer
    }

    SlidWindow(l + 1, len); // recurse for next segment, with the current fixed size.
} 


void scanAllLengths(int len) {
    if (len >= n) return; // Base Case.

    SlidWindow(0, len); // slide the window with size len Over all string s.

    scanAllLengths(len + 1); // recurse to increase the window.
}



int main() {
     cin >> s; // reas input
     n = s.size(); // get the length of string
     scanAllLengths(1); // start generate all windows, start with size 2, note {size = len + 1}
     cout << ans; // print what? anwser.
}
