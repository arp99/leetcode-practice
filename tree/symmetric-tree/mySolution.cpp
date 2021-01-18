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

    bool helper(TreeNode* leftTree , TreeNode* rightTree){
        //if both subtrees are NULL then also symmetric
        if(leftTree == NULL and rightTree == NULL) return true;
        //if either of them is NULL or their values are not same then tree is not symmetric
        else if(leftTree == NULL or rightTree == NULL or leftTree->val!=rightTree->val) return false;

        //else both are not NULL and values same and all subtrees are symmetrical
        return (leftTree->val == rightTree->val) and helper(leftTree->left , rightTree->right) and helper(leftTree->right , rightTree->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left , root->right);
    }
};