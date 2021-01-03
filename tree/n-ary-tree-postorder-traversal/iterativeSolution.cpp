#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
        vector<int> postorder(Node* root) {
            vector<int> v;
            stack<Node* > s;
            if(!root)
                return v;
            s.push(root);
            while(!s.empty()){
                Node* top = s.top();
                s.pop();
                v.push_back(top->val);
                for(auto it:top->children){
                    s.push(it);
                }
            }
            reverse(v.begin(),v.end());
            return v;
        }
};