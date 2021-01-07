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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q;
        if(!root) return result;
        
        q.push(root);
        q.push(NULL);//mark level end
        double sum = 0;
        int count = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp){
                sum += temp->val;
                count++;//count elements in current level
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }else{
                result.push_back(sum/count);
                sum = 0;
                count = 0;
                if(q.size()>0)
                    q.push(NULL);
            }
        }
        return result;
    }
};