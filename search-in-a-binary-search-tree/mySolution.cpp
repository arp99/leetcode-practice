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
    TreeNode* ptr = nullptr;
    void searchInorder(TreeNode* root, int val){
        if(root == nullptr)
            return;
        searchInorder(root->left , val);
        if(root->val == val)
            ptr = root;
        searchInorder(root->right , val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        searchInorder(root,val);
        return ptr;
    }
};