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
    bool isIdentical(TreeNode* s , TreeNode* t){
        if(s and t) return true;
        else if(s or t) return false;
        if(s->val == t->val and isIdentical(s->left , t->left) and isIdentical(s->right , t->right))
            return true;
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        //t is a subtree if one of the subtree of s is identical,.. so check identical for every node in s
        if(s and t) return true;
        else if(s or t) return t;

        if(isIdentical(s , t)) return true;
        return isSubtree(s->left , t) or isSubtree(s->right , t);
    }
};
