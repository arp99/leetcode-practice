#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , bool> map;
        vector<int> res;
        for(auto i: nums1){
            if(map.find(i) == map.end()){
                map[i] = true;
            }
        }
        for(auto j: nums2){
            if(map[j] == true){
                map[j] = false;//so that unique elements are inserted
                res.push_back(j);
            }
        }
        return res;
    }
};