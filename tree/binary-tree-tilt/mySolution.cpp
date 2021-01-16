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
    //returns the sum of nodes of a subtree
    int sumOfSubtree(TreeNode* root){
        if(root == NULL)
            return 0;
        return root->val + sumOfSubtree(root->left) + sumOfSubtree(root->right);
    }
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return 0;        
        return abs(sumOfSubtree(root->left) - sumOfSubtree(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
};