#include <bits/stdc++.h>
using namespace std;

/*
Convert 1D Array Into 2D Array

You are given a **0-indexed** 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using **all** the elements from original.

The elements from indices 0 to n - 1 (**inclusive**) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (**inclusive**) should form the second row of the constructed 2D array, and so on.

Return *an* m x n *2D array constructed according to the above procedure, or an empty 2D array if it is impossible*.
*/

vector<vector<int>> &form2DArray(vector<int> &nums1)
{
}

/*
<aside>
💡 **Question 2**

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

Given the integer n, return *the number of **complete rows** of the staircase you will build*.

</aside>
*/

int stairCoins(int n)
{
    return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
}

/*
Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

**Input:** nums = [-4,-1,0,3,10]

**Output:** [0,1,9,16,100]

**Explanation:** After squaring, the array becomes [16,1,0,9,100].

After sorting, it becomes [0,1,9,16,100].
*/

vector<int> sortSquare(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n - 1;
    while (n--)
    {
        if (abs(nums[i]) < abs(nums[j]))
        {
            ans[n] = nums[j] * nums[j];
            j--;
        }
        else
        {
            ans[n] = nums[i] * nums[i];
            i++;
        }
    }
    return ans;
}

/*
<aside>
💡 **Question 4**

Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

- answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
- answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

**Note** that the integers in the lists may be returned in **any** order.

**Example 1:**

**Input:** nums1 = [1,2,3], nums2 = [2,4,6]

**Output:** [[1,3],[4,6]]

**Explanation:**

For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

</aside>
*/

vector<vector<int>> solve(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> st1, st2;

    for (int i = 0; i < nums1.size(); i++)
        st1.insert(nums1[i]);
    for (int i = 0; i < nums2.size(); i++)
        st2.insert(nums2[i]);

    vector<vector<int>> ans(2);
    for (auto it : st1)
    {
        if (st2.find(it) == st2.end())
            ans[0].push_back(it);
    }
    for (auto it : st2)
    {
        if (st1.find(it) == st1.end())
            ans[1].push_back(it);
    }
    return ans;
}

/*
Given two integer arrays arr1 and arr2, and the integer d, *return the distance value between the two arrays*.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

**Example 1:**

**Input:** arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2

**Output:** 2

**Explanation:**

For arr1[0]=4 we have:

|4-10|=6 > d=2

|4-9|=5 > d=2

|4-1|=3 > d=2

|4-8|=4 > d=2

For arr1[1]=5 we have:

|5-10|=5 > d=2

|5-9|=4 > d=2

|5-1|=4 > d=2

|5-8|=3 > d=2

For arr1[2]=8 we have:

**|8-10|=2 <= d=2**

**|8-9|=1 <= d=2**

|8-1|=7 > d=2
*/

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int count = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < arr2.size(); j++)
        {
            if (abs(arr1[i] - arr2[j]) <= d)
            {
                flag = false;
            }
        }
        if (flag)
            count++;
    }
    return count;
}

/*

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

**Example 1:**

**Input:** nums = [4,3,2,7,8,2,3,1]

**Output:**

[2,3]
*/

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
            ans.push_back(abs(nums[i]));
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    return ans;
}

/*
Suppose an array of length n sorted in ascending order is **rotated** between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that **rotating** an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in O(log n) time.

**Example 1:**

**Input:** nums = [3,4,5,1,2]

**Output:** 1

**Explanation:**

The original array was [1,2,3,4,5] rotated 3 times.
*/

int findMin(vector<int> &nums)
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
        if (nums[mid] > nums[0])
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
An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

**Example 1:**

**Input:** changed = [1,3,4,2,6,8]

**Output:** [1,3,4]

**Explanation:** One possible original array could be [1,3,4]:

- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.

Other original arrays could be [4,3,1] or [3,1,4].
*/

vector<int> findOriginalArray(vector<int> &changed)
{
    int n = changed.size();
    if (n % 2 == 1)
        return {};
    sort(changed.begin(), changed.end());
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[changed[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[changed[i]] == 0)
            continue;
        if (mp[changed[i] * 2] == 0)
            return {};
        ans.push_back(changed[i]);
        mp[changed[i]]--;
        mp[changed[i] * 2]--;
    }
    return ans;
}