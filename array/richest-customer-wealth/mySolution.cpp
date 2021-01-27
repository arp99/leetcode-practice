#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for(auto bank : accounts){
            int sum = 0;
            for(auto wealth : bank){
                sum+=wealth;
            }
            maxWealth = max(maxWealth , sum);
        }
        return maxWealth;
    }
};