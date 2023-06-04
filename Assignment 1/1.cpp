/*
💡 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example:**
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> targetSum(vector<int> arr, int target)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = i;
    }

    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(target - arr[i]) != mp.end() && mp[target - arr[i]] != i)
        {
            ans.push_back(i);
            ans.push_back(mp[target - arr[i]]);
            break;
        }
    }
    return ans;
}