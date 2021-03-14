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
       ListNode* middle(ListNode* head){
        ListNode* slow , *fast;
        slow = fast = head;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        stack<ListNode* > s;
        //find middle of linked list and then push the nodes from the middle to end in the stack
        ListNode* middleNode = middle(head);

        ListNode* curr = middleNode;
        while(curr){
            s.push(curr);
            curr = curr->next;
        }
        middleNode->next = nullptr;
        ListNode* join = head ;
        while(!s.empty()){
            ListNode *temp = s.top();
            s.pop();
            ListNode* nextStart = join->next;
            join->next = temp;
            temp->next = nextStart;
            join = nextStart;

        }
        //now end the resultant list
        if(join)
            join->next = nullptr;
    }
};