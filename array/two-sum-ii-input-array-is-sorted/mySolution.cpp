#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1,sum;
        while(start<end){
            sum = numbers[start] + numbers[end];
            if(sum>target) end--;
            else if(sum<target) start++;
            else break;
        }
        vector<int> res = {start + 1, end + 1};
        return res;
    }
};