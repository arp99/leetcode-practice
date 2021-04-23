#include<bits/stdc++.h>
using namespace std;

//push the 2 list to 2 stacks then one by one pop calculate sum and carry, then make result linked list
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
        stack<ListNode *> st1 , st2;
        while(l1){
            st1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2);
            l2 = l2->next;
        }
        ListNode* result = NULL;
        //now one by one pop and make resultant list
        //continue if any one  of the stack is not empty as one of the numbers can be bigger than other
        int a , b , sum = 0, carry = 0;
        while(!st1.empty() or !st2.empty()){
            a = b = 0;
            if(!st1.empty()){
                a = st1.top()->val;
                st1.pop();
            }
            if(!st2.empty()){
                b = st2.top()->val;
                st2.pop();
            }
            sum = a + b + carry;
            carry = sum / 10;
            //make new node for result sum list
            ListNode* temp = new ListNode( sum % 10 );
            if(result == NULL)
                result = temp;
            else{
                temp->next = result;
                result = temp;
            }
        }
        //if the carry is greater than 0 then add a node before result
        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            temp->next = result;
            result = temp;
        }
        return result;
    }
};