#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int nsum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size() - 1; i++)
    {
        int start = i + 1;
        int end = nums.size() - 1;

        while (start < end)
        {
            int currSum = nums[i] + nums[start] + nums[end];
            if (abs(currSum - target) < abs(nsum - target))
                nsum = currSum;
            if (currSum < target)
                start++;
            else
                end--;
        }
    }
    return nsum;
}

/*
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
● 0 <= a, b, c, d < n
● a, b, c, and d are distinct.
● nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> op;
    set<vector<int>> st;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                if ((long long)nums[i] + nums[j] + nums[low] + nums[high] < (long long)target)
                {
                    low++;
                }
                else if ((long long)nums[i] + nums[j] + nums[low] + nums[high] > (long long)target)
                {
                    high--;
                }
                else
                {
                    st.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++, high--;
                }
            }
        }
    }
    for (auto it : st)
        op.push_back(it);
    return op;
}

/*
A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.
● For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater
permutation of its integer. More formally, if all the permutations of the array are
sorted in one container according to their lexicographical order, then the next
permutation of that array is the permutation that follows it in the sorted container.
If such an arrangement is not possible, the array must be rearranged as the
lowest possible order (i.e., sorted in ascending order).
● For example, the next permutation of arr = [1,2,3] is [1,3,2].
● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.
Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
*/

void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        int j;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[ind])
            {
                j = i;
                break;
            }
        }
        swap(nums[j], nums[ind]);
        reverse(nums.begin() + ind + 1, nums.end());
    }
}

/*
Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

/*
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
*/

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

/*

You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.
A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.
Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.
Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
*/

vector<vector<int>> missingRanges(vector<int> &nums, int lower, int upper)
{
    vector<vector<int>> ans;

    if (nums.size() == 0)
        return {{lower, upper}};

    // lower
    if (lower < nums[0])
    {
        ans.push_back({lower, nums[0] - 1});
    }

    // middle
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] == nums[i] + 1)
            continue;
        ans.push_back({nums[i] + 1, nums[i + 1] - 1});
    }
    // upper
    if (upper > nums[nums.size() - 1])
        ans.push_back({nums[nums.size() - 1] + 1, upper});
    return ans;
}

/*
Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.
Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
*/
bool comp(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}

bool attendMeetings(vector<vector<int>> &nums)
{
    sort(nums.begin(),nums.end(),comp);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i][1] >= nums[i + 1][0])
            return false;
    }
    return true;
}