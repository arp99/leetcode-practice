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
    //do level order traversal and track depth , the first leaf node encountered at any level, return its depth
    //as that node will be the closest to the root
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        //store the node along with its depth
        queue<pair<TreeNode* , int>> q;
        q.push(make_pair(root, 1));
        while(!q.empty()){
            pair<TreeNode* , int> temp = q.front();
            q.pop();
            //check if leaf node
            if(!temp.first->left and !temp.first->right)
                return temp.second;//return its depth

            if(temp.first->left)
                q.push(make_pair(temp.first->left , temp.second + 1));
            if(temp.first->right)
                q.push(make_pair(temp.first->right , temp.second + 1));
        }
        return 0;
    }
};