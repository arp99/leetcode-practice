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
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)//structure different
            return false;
        //the value should be same and also the left and right subtrees must be same
        return (p->val == q->val) && isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};