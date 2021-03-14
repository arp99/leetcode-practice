#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sptr = head , *fptr = head , *dptr = head;
        int i= n;
        //make the initial distance between the fast and slow pointer as n
        while(i--){
            fptr = fptr->next;
        }
        //if after havinf the initial distance fast pointer goes out of list then
        //slow pointer node must be deleted
        if(!fptr)
            return sptr->next;
        //else move until fast pointer is within the range of linked list
        while(fptr and fptr->next){
            fptr = fptr->next;
            sptr = sptr->next;
        }
        //delete the node by bypassing the links
        sptr->next = sptr->next->next;
        return dptr;
    }
};