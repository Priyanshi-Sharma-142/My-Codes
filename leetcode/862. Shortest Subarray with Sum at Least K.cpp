/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1], k = 1
Output: 1

Example 2:
Input: nums = [1,2], k = 4
Output: -1

*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> q;
        int i;
        int min_len=INT_MAX;
        for(i=0;i<nums.size();i++){
            
            if(i>0){
                nums[i]+=nums[i-1];
            }
            if(nums[i]>=k){
                min_len=min(min_len,i+1);
            }
        
        while(q.size() && nums[i]-nums[q.front()]>=k){
            min_len=min(min_len,i-q.front());
            q.pop_front();
        }
        while(q.size() && nums[i]<=nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
        if(min_len==INT_MAX){

            min_len=-1;
        }
        return min_len;
    }
};
