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
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        
        if(root->val <low) return trimBST(root->right , low , high);//need to trim it so right child
        //might be within range
        if(root->val >high) return trimBST(root->left , low , high);//trim it so left child might be
        //within range        

        root->left = trimBST(root->left , low , high);
        root->right = trimBST(root->right , low , high);

        return root;
    }
};