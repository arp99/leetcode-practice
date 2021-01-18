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

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        //push left and right subtree
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* temp1 = q.front();
            q.pop();
            TreeNode* temp2 = q.front();
            q.pop();

            //if both NULL then it's symmetric
            if(temp1 == NULL and temp2 == NULL)
                continue;
            //if either of 2 is NULL or their data is not same then not symmetric
            else if(temp1 == NULL or temp2 == NULL or temp1->val!=temp2->val)
                return false;
            
            //now push the children with both nodes in opposite order
            q.push(temp1->left);
            q.push(temp2->right);
            q.push(temp1->right);
            q.push(temp2->left);
        }
        return true;
    }
};