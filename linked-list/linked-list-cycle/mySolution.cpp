#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if list is empty or there is one node
        if(!head or !head->next) return false;
        
        ListNode *slow = head , *fast = head;
        bool isCycle = false;
        //move one pointer slow and another first , if both meets , then there is a loop in the ll
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        return isCycle;
    }
};