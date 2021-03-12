struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        else{
            ListNode* sptr = NULL , *mptr = head , *fptr = head->next;
            while(mptr){
                mptr->next = sptr;
                sptr = mptr;
                mptr = fptr;
                if(fptr) fptr = fptr->next;
            }
            return sptr;    
        }
    }
};