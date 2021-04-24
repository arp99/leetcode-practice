//approach2: using reversing the linked list.
/*
1. find the middle node
2. reverse the linked list in the right of middle node
3. then compare both the data of left and right list
4. then again reverse the right part and get back the original linked list
*/

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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL , *current = head , *next = head->next;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        //prev is the new head of the reversed linked list
        return prev;
    }
    
    bool compareList(ListNode* head1 , ListNode* head2){
        ListNode* temp1 = head1 , *temp2 = head2;
        while(temp1 and temp2){
            if(temp1->val == temp2->val){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }else{
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
       ListNode* slowPtr = head , *fastPtr = head , *prevSlowPtr = head , *midNode = NULL;
       bool res = true;
       //at least 2 nodes
        if(head!=NULL and head->next!=NULL){
           //get the middle node
            while(fastPtr!=NULL and fastPtr->next!=NULL){
                fastPtr = fastPtr->next->next;
                prevSlowPtr = slowPtr;
                slowPtr = slowPtr->next;
            }
            //now for odd no. of nodes, the fastPtr will be not null and be at the last node
            //so in that case midNode becomes the slowptr and the right list becomes slowptr->next
            if(fastPtr!=NULL){
                midNode = slowPtr;
                slowPtr = slowPtr->next;
            }
            //revserse the rightHalf
            ListNode* rightHalf = slowPtr;
            //now end the left half
            prevSlowPtr->next = NULL;
            rightHalf = reverse(slowPtr);
            res = compareList(head , rightHalf);
            //now reverse the right part again to get the original list back
            rightHalf = reverse(rightHalf);
            //now need to join the left part and right part
            //in case of odd nodes
            //first join the prevSlowptr->midNode->rightHalf
            if(midNode){
                prevSlowPtr->next = midNode;
                midNode->next = rightHalf;
            }
            //in case of even
            else{
                prevSlowPtr->next = rightHalf;
            }
        }
        return res;
    }
};