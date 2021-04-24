#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getMeetingPoint(ListNode* list){
        ListNode* hare = list , *turtle = list;
        while(turtle and hare and hare->next){
            turtle = turtle->next;
            hare = hare->next->next;
            if(turtle == hare){
                //reference where they meet
                //not necessary start of loop
                return turtle;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* meetingPoint = getMeetingPoint(head);
        if(!meetingPoint) return NULL;
        
        //if 2 nodes present return head
        if(head->next->next == head) return head;

        ListNode* ptr1 = head , *ptr2 = meetingPoint;
        while(ptr1 and ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2)
                    return ptr1;
        }
        return NULL;
    }
};