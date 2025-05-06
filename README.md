# Longest Balanced String Task (cs helwan 2025).

## psudo code
Function solve:
    Input: string s
    n ← length of s

    ans ← 0 // initialize variable answer to minmum possible value can be answer.
    // As we will maximize the length with the variable ans.

    For j from 1 to n - 1: // loop from 1 to n, to try all possible windows from 1, 2, ... to n
        l ← 0, r ← j // init two variable l.(left) and r.(right) they form the length of the window.

        While r < n:
            // loop to move the window step by step. (from left to right).
            // in each step we will loop inside the window.

            Initialize array freq[256] with zeros

            // init array to memorize each letter with its frequency.
            For i from l to r:
                // loop inside the window to memorize. .
                freq[s[i]] += 1

            // Check window status.
            count ← 0, val1 ← 0, val2 ← 0

            For i from 0 to 255:
                // loop on frequency array to count unique letters.
                If freq[i] ≠ 0:
                    count += 1
                    If count == 1: // here we get first char
                        val1 ← freq[i] // save his frequency.
                    Else if count == 2: // here we get second char
                        val2 ← freq[i] // save his frequency.
                    Else:
                        Break // here we find more than two char !

            If count == 2:
                // this means that it contains only two different letters,
                // perhaps with different frequencies.
                If val1 == val2:
                    // this means that it contains two different letters with the quale frequency,
                    // and it's valid window.
                    ans ← max(ans, r - l + 1)
                    // here, we maximize the length of the valid windows.

            r += 1, l += 1 // here, we increament l and r to move the window by one.

    Output ans // print the ans, it contains the maximum length of Balanced String.

