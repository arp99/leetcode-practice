#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        //if both the nodes are greater than the root then the lca will be on right subtree
        if(root->val <p->val and root->val <q->val) 
            return lowestCommonAncestor(root->right , p , q);
        //if both the nodes are less than the root then the lca will be on the left subtree
        else if(root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left , p , q);
        //first node which lies in between p and q is the lca in case of BST
        return root;
    }
};
