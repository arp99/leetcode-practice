#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum  = 0;
        int maxSum = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            currSum += nums[i];
            //check maxSum
            maxSum = max(maxSum , currSum);
            //check if currSum is negative ,to discard it for 
            //further subarray sum
            if(currSum < 0)
                    currSum  = 0;
        }
        return maxSum;
    }
};