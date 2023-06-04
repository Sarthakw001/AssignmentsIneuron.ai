#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),
..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
Example 1:
Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4
*/

int maxiSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i += 2)
        ans += nums[i];
    return ans;
}

/*
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started
to gain weight, so she visited a doctor.
The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice
likes her candies very much, and she wants to eat the maximum number of different types of
candies while still following the doctor's advice.
Given the integer array candyType of length n, return the maximum number of different types
of candies she can eat if she only eats n / 2 of them.
Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one
of each type.
*/

int distributeCandies(vector<int> &nums)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
        st.insert(nums[i]);
    int n = nums.size();
    if (st.size() > n / 2)
        return n / 2;
    return st.size();
}

/*
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.
A subsequence of an array is a sequence that can be derived from the array by deleting some
or no elements without changing the order of the remaining elements.
Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

int harmonisedArray(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;

    int ans = 0;
    for (auto i : mp)
    {
        if (mp.find(i.first + 1) != mp.end())
        {
            ans = max(ans, mp[i.first] + mp[i.first + 1]);
        }
    }
    return ans;
}

/*
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means
not empty, and an integer n, return true if n new flowers can be planted in the flowerbed
without violating the no-adjacent-flowers rule and false otherwise.
Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
*/

bool canPlaceFlowers(vector<int> &nums, int n)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            bool left = (i == 0) || (nums[i - 1] == 0);
            bool right = (i == nums.size() - 1) || (nums[i + 1] == 0);

            if (left && right)
            {
                nums[i] = 1;
                count++;
            }
        }
    }
    if (count >= n)
        return true;
    return false;
}

/*
Given an integer array nums, find three numbers whose product is maximum and return the
maximum product.
Example 1:
Input: nums = [1,2,3]
Output: 6
*/
int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n == 3)
        return nums[0] * nums[1] * nums[2];
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
}
/*
Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1.
You must write an algorithm with O(log n) runtime complexity.
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/

int binarySearch(vector<int> &nums, int target)
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
    return -1;
}

/*
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.
Example 1:
Input: nums = [1,2,2,3]
Output: true
*/

bool isMonotonic(vector<int> &nums)
{
    bool inc = true;
    bool dec = true;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            inc = false;
        if (nums[i] < nums[i + 1])
            dec = false;
    }
    return inc || dec;
}

/*
You are given an integer array nums and an integer k.
In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i]
to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at
most once for each index i.
The score of nums is the difference between the maximum and minimum elements in nums.
Return the minimum score of nums after applying the mentioned operation at most once for
each index in it.
Example 1:
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
*/

