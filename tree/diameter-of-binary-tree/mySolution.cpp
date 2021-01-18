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
    //the diameter may pass through root or not
    //so 2 cases=>i) through root(just return lheight + rheight) 
    //ii) not through root(return max(ldiameter , rdiameter))
    //diameter is the no. of edges between longest path between 2 nodes
    int helper(TreeNode* root , int &ans){
        if(!root) return 0;
        
        int lHeight = helper(root->left, ans);
        int rHeight = helper(root->right, ans);

        ans = max(ans , lHeight + rHeight);
        return 1 + max(lHeight , rHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        helper(root , ans);
        return ans;
    }
};