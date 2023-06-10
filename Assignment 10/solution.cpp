#include <bits/stdc++.h>
using namespace std;

/*
Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

**Example 1:**

```
Input: n = 27
Output: true
Explanation: 27 = 33
```

**Example 2:**

```
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

```

**Example 3:**
*/

bool powerOf3(int n)
{
    if (n == 0)
        return false;
    return (n == 1) || powerOf3(n / 3);
}

/*
You have a list `arr` of all integers in the range `[1, n]` sorted in a strictly increasing order. Apply the following algorithm on `arr`:

- Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
- Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
- Keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Given the integer `n`, return *the last number that remains in* `arr`.

**Example 1:**

Input: n = 9
Output: 6
Explanation:
arr = [1, 2,3, 4,5, 6,7, 8,9]
arr = [2,4, 6,8]
arr = [2, 6]
arr = [6]
*/

/*
Given a set represented as a string, write a recursive code to print all subsets of it. The subsets can be printed in any order.

**Example 1:**

Input :  set = “abc”

Output : { “”, “a”, “b”, “c”, “ab”, “ac”, “bc”, “abc”}

**Example 2:**

Input : set = “abcd”

Output : { “”, “a” ,”ab” ,”abc” ,”abcd”, “abd” ,”ac” ,”acd”, “ad” ,”b”, “bc” ,”bcd” ,”bd” ,”c” ,”cd” ,”d” }
*/

void subsets(string str, int idx = -1, string curr = "")
{
    if (idx == str.length())
        return;
    cout << curr << endl;
    for (int i = idx + 1; i < str.length(); i++)
    {
        curr += str[i];
        subsets(str, i, curr);
        curr.pop_back();
    }
}

/*
Given a string calculate length of the string using recursion.

**Examples:**
*/

int length(char *str)
{
    if (*str == '\0')
        return 0;
    else
        return 1 + length(str + 1);
}

/*
We are given a string S, we need to find count of all contiguous substrings starting and ending with same character.

**Examples :**
Input  : S = "abcab"
Output : 7
There are 15 substrings of "abcab"
a, ab, abc, abca, abcab, b, bc, bca
bcab, c, ca, cab, a, ab, b
Out of the above substrings, there
are 7 substrings : a, abca, b, bcab,
c, a and b.

Input  : S = "aba"
Output : 4
The substrings are a, b, a and aba
*/

void subsets(string str, int idx = -1, string curr = "", int &count)
{
    if (idx == str.length())
        return;
    if (curr[0] == curr[curr.length() - 1])
        count++;
    for (int i = idx + 1; i < str.length(); i++)
    {
        curr += str[i];
        subsets(str, i, curr);
        curr.pop_back();
    }
}

/*
The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

Input:
N = 2
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
Explanation:For N=2 , steps will be
as follows in the example and total
3 steps will be taken.
*/

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move rod" << n << "from rod" << from_rod << "to rod" << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

/*
Given a string str, the task is to print all the permutations of str. A permutation is an arrangement of all or part of a set of objects, with regard to the order of the arrangement. For instance, the words ‘bat’ and ‘tab’ represents two distinct permutation (or arrangements) of a similar three letter word.
*/

void solve(string &s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[i], s[l]);
            solve(s, l + 1, r);
            swap(s[i], s[l]);
        }
    }
}
void permute(string s)
{
    int n = s.length();
    solve(s, 0, n - 1);
}

/*
Given a string, count total number of consonants in it. A consonant is an English alphabet character that is not vowel (a, e, i, o and u). Examples of constants are b, c, d, f, and g.

**Examples :**
Input : abc de
Output : 3
There are three consonants b, c and d.

Input : geeksforgeeks portal
Output : 12
*/
void solve1(int idx, string s, int &ans)
{
    if (idx == s.length())
        return;
    if (s[idx] != 'a' && s[idx] != 'e' && s[idx] != 'i' && s[idx] != 'o' && s[idx] != 'u')
    {
        ans++;
    }
    solve1(idx + 1, s, ans);
}

int countConsonant(string s)
{
    int ans = 0;
    solve1(0, s, ans);
    return ans;
}