#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //store the num and index if the difference is not present in map //else return
        map<int,int> visited;
        vector<int> indices;
        int diff;
        for(int i = 0;i<nums.size();i++){
            diff = target - nums[i];
            //if diff is present in map
            if(visited.find(diff)!=visited.end()){
                indices.push_back(visited.find(diff)->second);
                indices.push_back(i);
            }else{
                visited.insert(pair<int,int>(nums[i] , i));
            }
        }    
        return indices;
    }
};