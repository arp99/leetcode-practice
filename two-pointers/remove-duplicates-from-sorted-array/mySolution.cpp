#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() == 0) return 0;
            int endPointer = 1;
            for(int i = 0;i<nums.size();i++){
                if(nums[i] != nums[endPointer - 1]){
                    nums[endPointer++] = nums[i];
                }
            }
            return endPointer;
        }
}