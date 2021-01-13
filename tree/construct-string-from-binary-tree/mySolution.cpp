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
    string str = "";
    void preOrder(TreeNode* t){

        if(t==nullptr)
            return;
        //append root
       str+=to_string(t->val);
        //now check if left present
        if(t->left){
            str+='(';
            tree2str(t->left);
            str+=')';
        }
        //check if right present
        if(t->right){
            //now if left is null then push () in the string
            if(t->left == nullptr)
                str+="()";
            str+='(';
            tree2str(t->right);
            str+=')';
        }
    }
    
    string tree2str(TreeNode* t) {
        preOrder(t);
        return str;
    }
};