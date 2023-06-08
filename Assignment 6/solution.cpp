#include <bits/stdc++.h>
using namespace std;

/*
A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

**Example 1:**

**Input:** s = "IDID"

**Output:**

[0,4,1,3,2]
*/

vector<int> diStringMatch(string s)
{
    int n = s.length();
    vector<int> ans(n + 1);
    int l = 0, h = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
            ans[i] = l++;
        else
            ans[i] = h--;
    }
    ans[n] = l;
    return ans;
}

/*
<aside>
💡 **Question 2**

You are given an m x n integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

You must write a solution in O(log(m * n)) time complexity.

**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3

**Output:** true

</aside>
*/

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    int start = 0;
    int end = m * n - 1;
    while (start <= end)
    {
        int mid = (start + end) >> 1;
        int row = mid / n;
        int col = mid % n;
        if (mat[row][col] == target)
        {
            return true;
        }
        else if (mat[row][col] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}

/*
<aside>
💡 **Question 3**

Given an array of integers arr, return *true if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

    **Example 1:**

**Input:** arr = [2,1]

**Output:**

false
</aside>
*/

bool validMountainArray(vector<int> &arr)
{
    int i;
    for (i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return false;
        if (arr[i] > arr[i + 1])
            break;
    }
    if (i == 0 || i == arr.size() - 1)
        return false;

    for (; i < arr.size() - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            return false;
    }
    return true;
}

/*
Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

**Example 1:**

**Input:** nums = [0,1]

**Output:** 2

**Explanation:**

[0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/

int findMaxLength(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<int, int> mp;
        for (int j = i; j < nums.size(); j++)
        {
            mp[nums[j]]++;
            if (mp[0] == mp[1])
                ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

/*
<aside>
💡 **Question 5**

The **product sum** of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (**0-indexed**).

- For example, if a = [1,2,3,4] and b = [5,2,3,1], the **product sum** would be 1*5 + 2*2 + 3*3 + 4*1 = 22.

Given two arrays nums1 and nums2 of length n, return *the **minimum product sum** if you are allowed to **rearrange** the **order** of the elements in* nums1.

**Example 1:**

**Input:** nums1 = [5,3,4,2], nums2 = [4,2,2,5]

**Output:** 40

**Explanation:**

We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40

</aside>
*/

int minProductSum(vector<int> &A, vector<int> &B)
{
    sort(begin(A), end(A));
    sort(begin(B), end(B), greater<>());
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
        ans += A[i] * B[i];
    return ans;
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

/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

/*
Given two [sparse matrices](https://en.wikipedia.org/wiki/Sparse_matrix) mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

**Example 1:**
*/