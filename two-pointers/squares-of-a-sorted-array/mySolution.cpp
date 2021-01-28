#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int i = 0, j = nums.size() - 1 ;
        int k = j;
       vector<int> res(nums.size());
        while(i<=j){
            int powS = pow(nums[i] , 2);
            int powE = pow(nums[j] , 2);
            if(powS <= powE){
                res[k--] = powE;
                j--;
            }else{
                res[k--] = powS;
                i++;
            }
        }
        return res;
    }
};