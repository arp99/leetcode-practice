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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList , *sumPtr ,*l1Ptr = l1 , *l2Ptr = l2;
        //take dummy node to make new list
        sumList = sumPtr = new ListNode(0);
        int sum = 0 , carry = 0 , a , b;
        // one of the number may be of more digits that's why or
        while(l1Ptr or l2Ptr){
            a = l1Ptr!=NULL? l1Ptr->val : 0;
            b = l2Ptr!=NULL ? l2Ptr->val : 0;
            
            sum = a + b + carry;
            carry = sum / 10;
            //make new node for sumList
            ListNode* temp = new ListNode( sum % 10);
            //point the next digit of the final sum
            sumPtr->next = temp;
            sumPtr = sumPtr->next;
             //move the pointers of l1 an l2
            if(l1Ptr)
                l1Ptr = l1Ptr->next;
            if(l2Ptr)
                l2Ptr = l2Ptr->next;
        }
        //if now there is a carry which is not 0
        //need to be added to the sumList
        if(carry != 0)
            sumPtr->next = new ListNode(carry);
        return sumList->next;
    }
};