#include<bits/stdc++.h>
using namespace std;

// Approach: take 2 stacks and push two list , then start popping and compare the pointers

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> st1 , st2;
        ListNode* temp1 = headA , *temp2 = headB;
        while(temp1){
            st1.push(temp1);
            temp1 = temp1->next;
        }
        while(temp2){
            st2.push(temp2);
            temp2 = temp2->next;
        }
        ListNode* prevTop = NULL;
        while(!st1.empty() and !st2.empty()){
            ListNode* top1 = st1.top() , *top2 = st2.top();
            st1.pop();
            st2.pop();
            
            if(top1 == top2){
                prevTop = top1;
            }else{
                return prevTop;
            }
        }
        return prevTop;
    }
};