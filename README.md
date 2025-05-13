# Longest Balanced String Task (CS helwan 2025).
## Non-recursive Algorithm
## psudo code 
```
Function LBS:
    Input: string s
    n ← length of s

    algorithm LBS(s, n)
{
    maxLength := 0
    // Initialize maxLength to track the longest valid balanced substring

    for i := 0 to n - 1 step 1 do
        // Try every possible starting point of the substring

        freq[256] := array of zeros
        // Frequency array for characters
        uniqueChars := empty list
        // List to store distinct characters seen in current substring

        for j := i to n - 1 step 1 do
            // Try to extend the substring from i to j

            currentChar := s[j]
            freq[ASCII(currentChar)] := freq[ASCII(currentChar)] + 1

            if freq[ASCII(currentChar)] = 1 then
                // New character encountered
                append currentChar to uniqueChars

            if size of uniqueChars = 2 then
                // Only check when we have exactly 2 unique characters
                a := ASCII(uniqueChars[0])
                b := ASCII(uniqueChars[1])

                if freq[a] = freq[b] then
                    // Frequencies match — it's a balanced substring
                    maxLength := max(maxLength, j - i + 1)

            if size of uniqueChars > 2 then
                // More than 2 unique characters — invalid window
                break

    return maxLength
    // maxLength holds the maximum length of a valid balanced substring
}
```
## Implementation with c++ language.
``` cpp

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int LBS(const string& s) {
    int n = s.length(), maxLength = 0;

    // Try all possible starting positions
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        vector<char> uniqe;

        // Try to extend substring from i
        for (int j = i; j < n; j++) {
            freq[s[j]]++;

            // If this is a new character, add it to distinct
            if (freq[s[j]] == 1) {
                uniqe.push_back(s[j]);
            }

            // If we have exactly 2 distinct characters
            if (uniqe.size() == 2) {
                // Check if frequencies are equal
                if (freq[uniqe[0]] == freq[uniqe[1]]) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }

            // If we have more than 2 distinct characters, break
            if (uniqe.size() > 2) break;
        }
    }
    return maxLength;
}

int main() {
    string s; cin >> s;
    cout << LBS(s);

    return 0;
}
```

## Analysis
Brute force
Time Complexity: O(n²)

We have two nested loops: the outer loop iterates through each starting position (O(n))
For each starting position, the inner loop potentially extends to the end of the string (O(n))
The operations inside these loops (hash map operations, checking frequencies) are O(1) amortized
Overall: O(n²)

Space Complexity: O(1)

The freq map stores character frequencies, but since we're dealing with a limited character set (at most 26 lowercase letters), this is bounded by a constant
The distinct vector stores at most 2 characters before breaking out of the inner loop
Therefore, space usage is independent of the input size: O(1)

## Another Non-recursive Algorithm
## psudo code
```
Function solve:
    Input: string s
    n ← length of s

   algorithm solve(s, n) // s is a string of length n
{
    ans := 0;
    // initialize variable answer to minmum possible value can be answer.
    // As we will maximize the length with the variable ans.

    for j := 1 to n - 1 step 1 do
        // loop from 1 to n, to try all possible windows from 1, 2, ... to n
        l := 0;
        r := j;
        // init two variable l.(left) and r.(right) they form the length of the window.

        while r < n do
            // loop to move the window step by step. (from left to right).
            // in each step we will loop inside the window.
            
            freq[256] := array of zeros;
            // init array to memorize each letter with its frequency.

            for i := l to r step 1 do
                // loop inside the window to memorize. .
                freq[ ASCII(s[i]) ] := freq[ ASCII(s[i]) ] + 1;

            // Check window status.
            count := 0;
            val1 := 0;
            val2 := 0;

            for i := 0 to 255 step 1 do
                // loop on frequency array to count unique letters.
                if freq[i] ≠ 0 then
                    count := count + 1;
                    if count = 1 then
                        val1 := freq[i]; // here we get first char
                    else if count = 2 then
                        val2 := freq[i]; // here we get second char
                    else
                        break; // here we find more than two char !

            if count = 2 then
                // this means that it contains only two different letters,
                // perhaps with different frequencies.
                if val1 = val2 then
                    // this means that it contains two different letters with the quale frequency,
                    // and it's valid window.
                    ans := max(ans, r - l + 1);
                    // here, we maximize the length of the valid windows.

            r := r + 1;
            l := l + 1;
            // here, we increament l and r to move the window by one.

    return ans;
    // print the ans, it contains the maximum length of Balanced String.
} 

```
## Implementation with c language.
```c

int max (int a, int b) {
    return a > b ? a : b;
}

void solve() {
    const int max_size = 1e5;
    char s[max_size]; // init char array.
    scanf("%s", s); // read input string.
    int n = strlen(s); // get the length of the string.

    int ans = 0; // init variable with minimum possible answer.
    for (int j = 1; j < n; j++) { // loop to try all lengthes from 1 to n
        int l = 0, r = j; // l --> (left) r --> (right) boundary of the substring.
        while (r < n) { // Move the window (subString) along the whole string.
            int freq[256] = {0}; // init array with size maximum ASCII Code.

            for (int i = l; i <= r; i++) { // loop inside the current window (subString)
                freq[s[i]]++;
            }

            int count = 0, val1 = 0, val2 = 0;
            // init three var, count to count the unique letters.
            // val1 to save the frequency of first char.
            // val2 to save the frequency of second char.
            for (int i = 0; i < 256; i++) { // loop inside the frequency array.
                if (freq[i]) {
                    count++; // find new char
                    if (count == 1) // first char
                        val1 = freq[i]; // Save character repetition
                    else if (count == 2) // second char
                        val2 = freq[i]; // Save character repetition
                    else // third char, it make the window not valid, break.
                        break;
                }
            }

            if (count == 2) { // this means it contain only two diff letter.
                if (val1 == val2) { // This means that their frequency is equal.
                    ans = max (ans, r - l + 1); // maximuze the answer.
                }
            }
            r++; l++; // increament the left and right to move the window.
        }
    }
    printf("%d\n", ans); // print answer.
}

```

## Analysis
Brute force
The function `solve()` scans a C‑string `s` (length `n`) and finds the longest substring (“window”) containing **exactly two distinct characters**, each occurring the **same number of times**. It works as follows:

1. **Try every window length** `j = 1…n–1`.  
2. **Slide** a window of length `j+1` from `l=0, r=j` up to `r=n–1`.
    here is a simulation for sliding window.

.
   ![Sliding‑Window Demo](SlidingSimulation.gif)

4. **Count frequencies** inside the current window by:
   - Zeroing out a fixed array `freq[256]`.  
   - Scanning the window (`i = l…r`) and doing `freq[(unsigned char)s[i]]++`.  
5. **Scan** `freq[ ]` (size 256) to check if there are exactly two nonzero entries with equal counts.  
6. **Update** `ans` if the window is “balanced.”

---

### Time Complexity

- **Outer loop** over window lengths `j`: **O(n)**  
- **Sliding loop** for each `j`: **O(n)**  
- **Per-window work**:
  - Counting window characters: **O(j)**
  - Scanning `freq[256]`: **O(1)** (constant)

Sum over j=1..n-1 of [ O(n) * (O(j) + O(1)) ]
  = Sum over j=1..n-1 of O(n*j)
  = O( n * (n(n-1)/2) )
  = O(n^3)


**Time Complexity:** **O(n³)**

---

## Space Complexity

- **Input string** `s`: **O(n)**  
- **Frequency array** `freq[256]`: **O(1)** (constant)  
- **Scalars** (`ans, j, l, r, count, val1, val2, i`): **O(1)**  

**Space Complexity:** **O(n)** (dominated by the input string)  

---

#  Recursive algorithm
## Pseudo code
```
// Global variables
ans ← 0
n ← length(s)
s ← input string

// Examine every substring of fixed length ‘len’ by sliding from left to right
FUNCTION SlideWindow(l, len):
    r ← l + len
    IF r ≥ n THEN
        RETURN

    // Count character frequencies in s[l..r]
    freq ← array[256] of 0
    FOR i FROM l TO r DO
        freq[ s[i] ] ← freq[ s[i] ] + 1

    // Determine how many distinct characters, and their counts
    countDistinct ← 0
    val1 ← 0
    val2 ← 0
    FOR each character c IN 0..255 DO
        IF freq[c] > 0 THEN
            countDistinct ← countDistinct + 1
            IF countDistinct = 1 THEN
                val1 ← freq[c]
            ELSE IF countDistinct = 2 THEN
                val2 ← freq[c]
            ELSE
                BREAK   // more than 2 distinct → invalid
            END IF
        END IF
    END FOR

    // Check validity: exactly two distinct chars with equal counts
    IF countDistinct = 2 AND val1 = val2 THEN
        ans ← max(ans, len + 1)
    END IF

    // Recurse by moving window one position right
    CALL SlideWindow(l + 1, len)
END FUNCTION



// Try every possible window size from 0 up to n−1
FUNCTION scanAllLengths(len):
    IF len ≥ n THEN
        RETURN

    CALL SlideWindow(0, len)
    CALL scanAllLengths(len + 1)
END FUNCTION



// Driver
READ s
n ← length(s)
CALL scanAllLengths(0)
PRINT ans

```

## Implementation with C++ language.
```c++
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
```

## Analysis

Let n be the length of the input string s.
##1. High-level structure
1.  scanAllLengths(len)
  Recursively tries every window size len from 0 up to n–1.
  For each len, it calls SlideWindow(0, len).
2. SlideWindow(l, len)
  Slides a window of fixed size len+1 across the string by recursively incrementing l from 0 up to n–len–1.
  For each window s[l..r], it:
   1. Builds a frequency array freq[256] in O(len+1) time.
   2. Scans the 256-entry array to count distinct characters (up to 3) in O(256) = O(1) time.
   3. Possibly updates the global answer.

## 2.Time Complexity
Inner work per window:
  - Building freq: O(len+1)
  - Scanning freq[256]: O(1)
    =>  O(len) total.
Number of windows of size (len+1):
 Positions l = 0 to l = n–(len+1) → (n–len) windows.    

##Total cost: 
![iteration](https://github.com/user-attachments/assets/1c78d28c-b8db-4838-a9f2-6ecb480d4cad)


## 3. Space Complexity
Frequency array: freq[256] ⇒ O(1) auxiliary space.
Call stack:
  - scanAllLengths recurses to depth ≈ n.
  - SlideWindow recurses to depth ≈ n (in the worst case when len ≈ n).
  => Combined maximum recursion depth O(n).



