#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isUniValue = true;
    void dfs(TreeNode* root , int value){
        if(root == NULL)
            return;
        if(root->val!= value){
            isUniValue = false;
        }else{
            dfs(root->left,value);
            dfs(root->right,value);
        }
    }
    
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        dfs(root ,value);
        return isUniValue;
    }
};