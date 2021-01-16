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
    int getDepth(TreeNode* root , int depth , int data){
        if(!root) return -1;
        if(root->val == data) return depth;
        int x = getDepth(root->left, depth + 1 , data);
        if(x!=-1) return x;
        x = getDepth(root->right, depth + 1 , data);
        return x;
    }
    int getParent(TreeNode* root , int data){
        if(!root) return -1;
        if(root->left and root->left->val == data or root->right and root->right->val == data)
            return root->val;
        int x = getParent(root->left, data);
        if(x!=-1) return x;
        x = getParent(root->right, data);
        return x;
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = getDepth(root , 0 , x);
        int yDepth = getDepth(root , 0 , y);
        int xParent = getParent(root , x);
        int yParent = getParent(root , y);

        return xDepth == yDepth and xParent!=yParent;
    }
};