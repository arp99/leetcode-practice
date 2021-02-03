#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getActualString(string s){
        stack<char> st;
        string newStr = "";
        char top;
        int backSpace_count = 0;
        for(auto c : s){
            st.push(c);
        }
        
        while(!st.empty()){
            top = st.top();
            st.pop();
            if(top == '#'){
                backSpace_count++;
            }
            if(top != '#' and backSpace_count == 0){
                newStr +=top;
            }
            else if(top!= '#' and backSpace_count>0){
                backSpace_count--;
            }
        }
        return newStr;
    }
    
    
    bool backspaceCompare(string S, string T) {
        return getActualString(S) == getActualString(T);    
    }
};

// T.C : O(N)
// S.C : O(N)