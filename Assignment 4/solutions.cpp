#include <bits/stdc++.h>
using namespace std;

/*
<aside>
💡 Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

**Example 1:**

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

Output: [1,5]

**Explanation:** Only 1 and 5 appeared in the three arrays.

</aside>
*/

vector<int> sortArray(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{

    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size())
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            ans.push_back(arr1[i]);
            i++, j++, k++;
        }
        else if (arr1[i] <= arr2[j] || arr1[i] <= arr3[k])
            i++;
        else if (arr2[j] <= arr1[i] || arr2[j] <= arr3[k])
            j++;
        else if (arr3[k] <= arr1[i] || arr3[k] <= arr2[j])
            k++;
    }
    return ans;
}

/*
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
<aside>
💡 Given a 2D integer array matrix, return *the **transpose** of* matrix.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

**Example 1:**

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

Output: [[1,4,7],[2,5,8],[3,6,9]]

</aside>
*/

vector<vector<int>> transpose(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][i] = ans[i][j];
        }
    }
    return ans;
}

/*
<aside>
💡 Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is **maximized**. Return *the maximized sum*.

**Example 1:**

Input: nums = [1,4,3,2]

Output: 4

**Explanation:** All possible pairings (ignoring the ordering of elements) are:

1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3

2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3

3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4

So the maximum possible sum is 4.

</aside>
*/

int maxiSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }
    return sum;
}

/*
<aside>
💡 You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

Given the integer n, return *the number of **complete rows** of the staircase you will build*.

</aside>
*/

int arrangeCoins(int n)
{
    return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
}

/*
<aside>
💡 Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

Input: nums = [-4,-1,0,3,10]

Output: [0,1,9,16,100]

**Explanation:** After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100]

</aside>
*/

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size(), low = 0, high = n - 1;
    vector<int> ans(n);
    while (n--)
    {
        if (abs(nums[low]) < abs(nums[high]))
        {
            ans[n] = nums[high] * nums[high];
            high--;
        }
        else
        {
            ans[n] = nums[low] * nums[low];
            low++;
        }
    }
    return ans;
}



/*

*/

/*
<aside>
💡 **Question 8**

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

*Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

**Example 1:**

**Input:** nums = [2,5,1,3,4,7], n = 3

**Output:** [2,3,5,4,1,7]

**Explanation:** Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

</aside>
*/

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> result(2 * n);
    for (int i = 0; i < n; ++i)
    {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[n + i];
    }
    return result;
}