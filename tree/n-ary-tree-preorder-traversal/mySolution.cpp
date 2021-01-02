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
    void getPreOrderVector(Node* root){
        if(root == nullptr)
            return;
        v.push_back(root->val);
        for(auto it: root->children){
            getPreOrderVector(it);
        }
    }
    vector<int> preorder(Node* root) {
        getPreOrderVector(root);
        return v;
    }
};