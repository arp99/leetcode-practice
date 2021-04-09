#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //O(n) time solution
    bool containsDuplicate(vector<int>& nums) {
        //better solution using hash table
        unordered_map<int , bool> numsMap;
        for(int num : nums){
            //num already exists in map
            if(numsMap.find(num) != numsMap.end())
                    return true;
            numsMap.insert({num , true});
        }
        return false;
    }
};