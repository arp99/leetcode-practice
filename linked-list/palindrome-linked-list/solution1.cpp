//approach1: using stacks, push the linked list in stack, and then traverse the linked list again while checking top of stack and popping from it.
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //simple approach: push to stack then while popping check val from start to end of ll
        stack<ListNode*> st;
        ListNode* ptr = head;
        while(ptr){
            st.push(ptr);
            ptr = ptr->next;
        }
        ptr = head;
        while(!st.empty()){
            if(ptr->val != st.top()->val)
                return false;
            st.pop();
            ptr = ptr->next;
        }
        return true;
    }
};