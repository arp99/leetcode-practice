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
    vector<vector<int>> result;
public:
    void bfs(TreeNode* root){
        if(root == nullptr)
            return;
        queue<TreeNode*>q;
        vector<int> level;
        q.push(root);
        q.push(NULL);//to mark end of levels
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp){
                
                level.push_back(temp->val);//push nodes in current level
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }else{
                result.push_back(level);
                level.clear();//erase elements to store next level
                if(q.size()>0)
                    q.push(NULL);//mark end of next level
            }
        }
        reverse(result.begin() , result.end());
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        bfs(root);
        return result;
    }
};