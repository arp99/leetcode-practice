#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(),candies.end());
        vector<bool> res;
        for(auto candy : candies){
            if(candy + extraCandies >=maxCandy){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};