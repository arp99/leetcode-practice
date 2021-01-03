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
    vector<int> v;
    void getPostOrderVector(Node* root){
        if(root == nullptr)
            return;
        for(auto it:root->children){
            getPostOrderVector(it);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        stack<Node*> s;
        if(!root)
            return v;
        s.push(root);
        while(!s.empty()){
            Node* top = s.top();
        }
        getPostOrderVector(root);
        return v;
    }
};