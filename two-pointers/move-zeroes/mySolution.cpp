#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
        for( ; j<nums.size();j++){
            if(nums[j] !=0 and nums[i] == 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }else if(nums[i]!=0){
                i++;
            }
        }
    }
};