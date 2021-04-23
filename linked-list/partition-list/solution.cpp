#include<bits/stdc++.h>
using namespace std;
//approach: make 2 lists, one for having elements 
//smaller than x and other for elements greater or 
//equal to x , the join the leftList and rightList

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //take 2 linked list
        ListNode * leftList , *leftPtr , *rightList , *rightPtr , *traversePtr = head;
        //make dummy nodes to start making the linked lists
        leftList = leftPtr = new ListNode(0);
        rightList = rightPtr = new ListNode(0);
        
        while(traversePtr){
            //if the current element is less than x
            if(traversePtr->val < x){
                leftPtr->next = traversePtr;
                //point to current last node
                leftPtr = leftPtr->next;
            }
            else{
                rightPtr->next = traversePtr;
                rightPtr = rightPtr->next;
            }
            
            traversePtr = traversePtr->next;
        }
        //now make the next of last node of rightList point to null
        rightPtr->next = nullptr;
        //make the last node the leftList point to head of rightList
        leftPtr->next = rightList->next;
        
        //return new head
        return leftList->next;
    }
};