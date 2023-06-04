/*
💡 You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.

Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
#include <bits/stdc++.h>
using namespace std;

//  brute force approach;
vector<int> largerInt(vector<int> &nums)
{

    int num = 0, n = nums.size() - 1;
    int idx = 0;
    for (int i = n; i >= 0; i--)
    {
        num = num + nums[i] * pow(10, idx++);
    }
    num++;
    vector<int> ans;
    while (num != 0)
    {
        ans.push_back(num % 10);
        num = num / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// optimized App;

vector<int> largerInt(vector<int> &nums)
{
    int n = nums.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (nums[i] == 9)
        {
            nums[i] = 0;
        }
        else
        {
            nums[i] += 1;
            return nums;
        }
    }
    nums.push_back(0);
    nums[0] = 1;
    return nums;
}
