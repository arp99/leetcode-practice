#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeBackspace(string &str){
        int removePointer = 0;
        for(int i = 0;i<str.length();i++){
            if(str[i] != '#'){
                str[removePointer++] = str[i];
            }
            else if(str[i] == '#'){
                if(removePointer >0){
                    removePointer--;
                }
            }
        }
        return removePointer;
    }
    
    bool backspaceCompare(string S, string T) {
        int newLength_S = removeBackspace(S);
        int newLength_T = removeBackspace(T);    
        
        if(newLength_S != newLength_T)
            return false;
        else{
            for(int i = 0;i<newLength_S;i++){
                if(S[i]!=T[i])
                    return false;
            }
        }
        return true;
    }
};

// T.C : O(N)
// S.C : O(1)