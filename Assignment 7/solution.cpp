#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, *determine if they are isomorphic*.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

**Input:** s = "egg", t = "add"

**Output:** true
*/

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> s_t;
    unordered_map<char, char> t_s;

    vector<int> ans1;
    vector<int> ans2;

    for (int i = 0; i < s.length(); i++)
    {
        if (s_t.find(s[i]) == s_t.end())
        {
            s_t[s[i]] = i;
            ans1.push_back(i);
        }
        else
        {
            ans1.push_back(s_t[s[i]]);
        }
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (t_s.find(t[i]) == t_s.end())
        {
            t_s[t[i]] = i;
            ans2.push_back(i);
        }
        else
        {
            ans2.push_back(t_s[t[i]]);
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (ans1[i] != ans2[i])
        {
            return false;
        }
    }
    return true;
}

/*

Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.

A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

**Example 1:**

**Input:** num = "69"

**Output:**

true
*/

bool isStrobogrammatic(string num)
{
    unordered_map<char, char> lut{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    for (int l = 0, r = num.size() - 1; l <= r; l++, r--)
    {
        if (lut.find(num[l]) == lut.end() || lut[num[l]] != num[r])
        {
            return false;
        }
    }
    return true;
}

/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**

**Input:** s = "Let's take LeetCode contest"

**Output:** "s'teL ekat edoCteeL tsetnoc"
*/

string reverseWords(string s)
{
    int left = 0, right;
    for (int i = 0; i < s.length() + 1; i++)
    {
        if (i == s.length() || s[i] == ' ')
        {
            right = i - 1;
            while (left < right)
                swap(s[left++], s[right--]);
            left = i + 1;
        }
    }
    return s;
}

/*
<aside>
💡 **Question 5**

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

**Example 1:**

**Input:** s = "abcdefg", k = 2

**Output:**

"bacdfeg"

</aside>
*/

string reverseStr(string s, int k)
{
    int n = s.length();
    for (int start = 0; start < s.length(); start += 2 * k)
    {
        int i = start, j = min(start + k - 1, n - 1);
        while (i < j)
        {
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
    }
    return s;
}

/*
Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of **shifts** on* s.

A **shift** on s consists of moving the leftmost character of s to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

**Example 1:**

**Input:** s = "abcde", goal = "cdeab"

**Output:**

true
*/

bool rotateString(string s, string goal)
{
    if (s == goal)
        return true;
    for (int i = 0; i < s.length(); i++)
    {
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1);
        if (s2 + s1 == goal)
            return true;
    }
    return false;
}

/*
Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

**Example 1:**

**Input:** s = "ab#c", t = "ad#c"

**Output:** true

**Explanation:**

Both s and t become "ac"
*/

bool backspaceCompare(string s, string t)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '#')
            st.push(s[i]);
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
    }
    s.clear();
    while (!st.empty())
    {
        s = s + st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] != '#')
            st.push(t[i]);
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
    }
    t.clear();
    while (!st.empty())
    {
        t = t + st.top();
        st.pop();
    }
    reverse(t.begin(), t.end());
    if (s == t)
        return true;
    return false;
}

/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/

int getYDiff(vector<int> &a, vector<int> &b)
{
    return a[1] - b[1];
}

int getXDiff(vector<int> &a, vector<int> &b)
{
    return a[0] - b[0];
}

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int deltaY = getYDiff(coordinates[1], coordinates[0]);
    int deltaX = getXDiff(coordinates[1], coordinates[0]);

    for (int i = 2; i < coordinates.size(); i++)
    {
        if (deltaY * getXDiff(coordinates[i], coordinates[0]) != deltaX * getYDiff(coordinates[i], coordinates[0]))
        {
            return false;
        }
    }
    return true;
}