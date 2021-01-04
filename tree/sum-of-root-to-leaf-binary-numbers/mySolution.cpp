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
    vector<int> v;
    int sum  = 0;
    void getPathRootToLeaf(TreeNode* root , int pathlen){
        if(root == nullptr)
            return;
        v.insert(v.begin()+pathlen , root->val);
        pathlen++;
        // If the node is the leaf node 
        if(root->left == nullptr and root->right == nullptr){
            binToDecimal(v , pathlen);
        }
        //traverse both left and right children
        else{
            getPathRootToLeaf(root->left , pathlen);
            getPathRootToLeaf(root->right , pathlen);
        }
    }
    void findSum(int num){
        sum+=num;
    }
    void binToDecimal(vector<int> v , int len){
        int decNum = 0;
        for(int i = 0;i<len;i++){
            decNum += v[i] * (1<<len - i - 1);
        }
        findSum(decNum);
    }
    int sumRootToLeaf(TreeNode* root) {
        getPathRootToLeaf(root , 0);
        return sum;
    }
};