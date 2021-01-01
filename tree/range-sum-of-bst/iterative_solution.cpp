#include<bits/stdc++.h>
using namespace std;
/* Definition for a binary tree node.*/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *currNode = s.top();
            s.pop();
            if(currNode!=nullptr){
                if(currNode->val >=low && currNode->val<=high){
                    sum+=currNode->val;
                }
                if(currNode->val >low)
                    s.push(currNode->left);
                if(currNode->val <high)
                    s.push(currNode->right);
            }
        }
        return sum;
    }
    
};