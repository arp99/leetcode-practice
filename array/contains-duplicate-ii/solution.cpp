#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //declare a hashtable <int,int>, stored the num and the index
        unordered_map<int , int> numsMap;
        for(int i = 0;i<nums.size();i++){
            //check if already present
            //then check for the nearby condition
            if(numsMap.find(nums[i]) != numsMap.end()) {
                auto it = numsMap.find(nums[i]);
                if(abs(it->second - i) <= k)
                    return true;
                //update the index with index of current duplicate
                it->second = i;
            }else{
                //store the number and the index
                numsMap.insert({nums[i] , i});    
            }
            
        }
        return false;
    }
};