#include <bits/stdc++.h>
using namespace std;

/*
Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.

**Example 1:**
Input: n = 1

Output: true

**Example 2:**
Input: n = 16

Output: true

**Example 3:**
Input: n = 3

Output: false
*/

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (n == 1) || (n % 2 == 0 && isPowerOfTwo(n / 2));
}

/*
Given a number n, find the sum of the first natural numbers.

**Example 1:**

Input: n = 3

Output: 6

**Example 2:**

Input  : 5

Output : 15
*/

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

/*
Given a positive integer, N. Find the factorial of N.

**Example 1:**

Input: N = 5

Output: 120

**Example 2:**

Input: N = 4

Output: 24
*/

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

/*
Given a number N and a power P, the task is to find the exponent of this number raised to the given power, i.e. N^P.

**Example 1 :**

Input: N = 5, P = 2

Output: 25

**Example 2 :**
Input: N = 2, P = 5

Output: 32
*/
int solve(int n, int p)
{
    if (n == 1)
        return n;
    return n * solve(n, p - 1);
}
int pow(int n, int p)
{
    int ans = solve(abs(n), abs(p));
    if (n > 0)
    {
        if (p > 0)
            return ans;
        else
            return 1 / ans;
    }
    else
    {
        if (p > 0)
        {
            if (p % 2 == 0)
                return ans;
            else
                return -ans;
        }
        else
        {
            if (p % 2 == 0)
                return 1 / ans;
            else
                return -1 / ans;
        }
    }
    return 0;
}

/*
Given an array of integers **arr**, the task is to find maximum element of that array using recursion.

**Example 1:**

Input: arr = {1, 4, 3, -5, -4, 8, 6};
Output: 8

**Example 2:**

Input: arr = {1, 4, 45, 6, 10, -8};
Output: 45
*/

void solve(int idx, vector<int> &num, int &ans)
{
    if (idx == num.size())
        return;
    if (num[idx] > ans)
        ans = num[idx];
    solve(idx + 1, num, ans);
}
int maxElement(vector<int> &num)
{
    int ans = INT_MIN;
    solve(0, num, ans);
    return ans;
}

/*
Given first term (a), common difference (d) and a integer N of the Arithmetic Progression series, the task is to find Nth term of the series.

**Example 1:**

Input : a = 2 d = 1 N = 5
Output : 6
The 5th term of the series is : 6

**Example 2:**

Input : a = 5 d = 2 N = 10
Output : 23
The 10th term of the series is : 23
*/

int arithmetic(int a, int d, int n)
{
    if (n == 1)
        return a;
    return d + arithmetic(a, d, n - 1);
}

/*
Given a string S, the task is to write a program to print all permutations of a given string.

**Example 1:**

***Input:***

*S = “ABC”*

***Output:***

*“ABC”, “ACB”, “BAC”, “BCA”, “CBA”, “CAB”*

**Example 2:**

***Input:***

*S = “XY”*

***Output:***

*“XY”, “YX”*
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
Given an array, find a product of all array elements.

**Example 1:**

Input  : arr[] = {1, 2, 3, 4, 5}
Output : 120
**Example 2:**

Input  : arr[] = {1, 6, 3}
Output : 18
*/

int solveP(vector<int> &nums, int idx)
{

    if (idx == nums.size() - 1)
        return nums[idx];
    return nums[idx] * solveP(nums, idx + 1);
}
int product(vector<int> &nums)
{
    return solveP(nums, 0);
}