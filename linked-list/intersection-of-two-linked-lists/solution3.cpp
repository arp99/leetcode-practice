#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct Result{
    ListNode* tail;
    int length;
};

class Solution {
public:
    
    Result getTailAndLength(ListNode* list){
        int len = 1;
        ListNode* curr = list;
        while(curr->next != NULL){
            len ++;
            curr = curr->next;
        }
        Result res;
        res.length = len;
        res.tail = curr;
        return res;
    }

    ListNode * getNewHead(ListNode *list , int diff){
        ListNode* curr = list;
        while(diff > 0 and curr!=NULL){
            curr = curr->next;
            diff--;
        }
        return curr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB == NULL) return NULL;
        //get the tail node and the length of the two list
        Result res1 = getTailAndLength(headA);
        Result res2 = getTailAndLength(headB);
        //if different tail nodes then there is no intersection
        if(res1.tail != res2.tail)
            return NULL;
        
        //now we need to advance the pointer in longer list by the difference in length
        ListNode* shorter = res1.length < res2.length ? headA : headB ;
        ListNode* longer = res1.length > res2.length ? headA : headB ;
        
        //if they are of same length
        if(res1.length == res2.length){
            shorter = headA;
            longer = headB;
        }
        
        //now advance the head in the longer list
        longer = getNewHead(longer , abs(res1.length - res2.length));

        //now we have both list with same length, so advance both list together untill we get a collispon
        while(shorter !=longer){
            shorter = shorter->next;
            longer = longer->next;
        }
        //return either one
        return shorter;
    }
};