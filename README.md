# Longest Balanced String Task (cs helwan 2025).

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
} ```
