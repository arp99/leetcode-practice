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
    //in this special binary tree the root is the min element in the whole binary tree
    void traverse(TreeNode* root , int &Min , int &nextMin){
        if(!root) return;
        //first time when nextMin = -1 , update value
        if(root->val != Min and root->val < nextMin or root->val!=Min and nextMin==-1){
            nextMin = root->val;
        }
        else if(root->val == Min){
            traverse(root->left , Min , nextMin);
            traverse(root->right , Min , nextMin);    
        }
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        int nextMin = -1;
        traverse(root , min , nextMin);
        if(min!=nextMin and nextMin!=-1) return nextMin;
        else return -1;
    }
};
