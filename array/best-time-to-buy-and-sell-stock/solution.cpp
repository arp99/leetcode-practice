#include<bits/stdc++.h>
using namespace std;
//approach: kadane's algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currBuy = prices[0];
        int maxProfit = 0 , currProfit = 0;
        for(int i = 1;i<prices.size();i++){
            if((prices[i] - currBuy) >0){
                currProfit = prices[i] - currBuy;
            }else{
                currProfit = 0;
                currBuy = prices[i];
            }
            maxProfit = max(maxProfit , currProfit);
        }
        return maxProfit;
    }
};