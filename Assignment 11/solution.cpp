#include <bits/stdc++.h>
using namespace std;

/*
Given a non-negative integer `x`, return *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be **non-negative** as well.

You **must not use** any built-in exponent function or operator.
*/
int mySqrt(int x)
{
    int low = 1, high = x;
    while (low <= high)
    {
        long mid = low + (high - low) / 2;
        if (mid * mid > x)
            high = mid - 1;
        else if (mid * mid < x)
            low = mid + 1;
        else
            return mid;
    }
    return high;
}

/*
A peak element is an element that is strictly greater than its neighbors.

Given a **0-indexed** integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in `O(log n)` time.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

*/

int findPeakElement(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++)
    {
        sum = sum - nums[i];
    }
    return sum;
}

/*
Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return *this repeated number*.

You must solve the problem **without** modifying the array `nums` and uses only constant extra space.
Input: nums = [1,3,4,2,2]
Output: 2

*/

int findDuplicate(vector<int> &nums)
{

    int tortoise = nums[0];
    int hare = nums[0];

    do
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

*/
vector<int> intersection(unordered_set<int> st1, unordered_set<int> st2)
{
    vector<int> ans;
    for (auto it : st1)
    {
        if (st2.find(it) != st2.end())
            ans.push_back(it);
    }
    return ans;
}
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> st1, st2;
    for (int i = 0; i < nums1.size(); i++)
        st1.insert(nums1[i]);
    for (int i = 0; i < nums2.size(); i++)
        st2.insert(nums2[i]);

    if (st1.size() < st2.size())
        return intersection(st1, st2);
    return intersection(st2, st1);
}

/*
Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n) time.`
*/

int minElementInRotatedSortedArray(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int low = 0, high = nums.size() - 1;

    if (nums[0] < nums[high])
        return nums[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (nums[mid - 1] > nums[mid])
            return nums[mid];
        if (nums[mid] > nums[low])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return nums[low];
}

/*
<aside>
💡 **Question 7**

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

</aside>
*/
vector<int> startAndEndOfTarget(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int s = -1, e = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            s = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            e = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    vector<int> ans(2);
    ans[0] = s;
    ans[1] = e;
    return ans;
}

/*
<aside>
💡 **Question 8**

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

</aside>
*/

unordered_map<int, int> makeMap(vector<int> nums)
{
    unordered_map<int, int> ans;
    for (int i = 0; i < nums.size(); i++)
        ans[nums[i]] = 1;
    return ans;
}
vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    unordered_map<int, int> mp;
    if (n <= m)
        mp = makeMap(nums1);
    else
        mp = makeMap(nums2);
    vector<int> ans;
    if (n <= m)
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            if (mp[nums2[i]])
                ans.push_back(nums2[i]);
        }
    }
    else
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mp[nums1[i]])
                ans.push_back(nums1[i]);
        }
    }
    return ans;
}