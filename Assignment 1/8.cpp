/*
💡 You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**
Input: nums = [1,2,2,4]
Output: [2,3]

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> missingFromSet(vector<int> &nums)
{
    unordered_set<int> st;
    int r, m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(nums[i]) != st.end())
            r = nums[i];
        st.insert(nums[i]);
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (st.find(i) == st.end())
            m = i;
    }
    return {r, m};
}