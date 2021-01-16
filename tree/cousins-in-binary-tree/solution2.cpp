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
    //solution based on BFS-level order traversal
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        
        //store the levels and parents of nodes in separate vectors then match the condition
        vector<int> parent(101 , -1);
        vector<int> depth(101 , -1);
        queue<TreeNode*> q;
        q.push(root);
        int currDepth = -1 , currParent = root->val;
        while(!q.empty()){
            int s = q.size();

            //increment depth
            currDepth++;
            for(int i = 0 ; i<s; i++){
                TreeNode* temp = q.front();
                q.pop();

                //push depth for temp
                depth[temp->val] = currDepth;

                if(temp->left) q.push(temp->left), parent[temp->left->val] = temp->val;
                if(temp->right) q.push(temp->right), parent[temp->right->val] = temp->val;
            }
        }
        //now just check condition and return
        return depth[x] == depth[y] and parent[x]!=parent[y];
    }
};