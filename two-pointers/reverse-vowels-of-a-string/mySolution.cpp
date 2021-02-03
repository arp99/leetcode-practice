#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'){
          return true;
        }
      return false;
    }
    string reverseVowels(string s) {
        int front = 0, end = s.length() - 1;
        while(front < end){
            if(!isVowel(s[front])) front++;
            if(!isVowel(s[end])) end--;

            if(isVowel(s[front]) && isVowel(s[end])){
                if(s[front]!=s[end]){
                    swap(s[front] , s[end]);
                }
                front++;
                end--;
            }
        }
        return s;       
    }
};