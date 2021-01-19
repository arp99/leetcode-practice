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

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root){
            if(!root->left and !root->right and root->val == targetSum){
                return true;
            } 
            //reduce target for visiting subtrees
            if(hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right , targetSum - root->val))
                return true;       
        }
        return false;
    }
};