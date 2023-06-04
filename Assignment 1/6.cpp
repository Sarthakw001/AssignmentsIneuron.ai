/*

💡  Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**
Input: nums = [1,2,3,1]

Output: true

*/

#include <bits/stdc++.h>
using namespace std;

bool atLeastTwice(vector<int> &nums)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
        st.insert(nums[i]);

    return !(nums.size() == st.size());
}