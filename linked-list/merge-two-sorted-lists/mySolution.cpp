struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        //now the starting pointer of new ll will be leseer value of head of two ll
        ListNode* s = nullptr , *head = nullptr;
        if(l1 and l2){
            if(l1->val <= l2->val){
                s = l1;
                l1 = l1->next;
            }else if(l2->val <= l1->val){
                s = l2;
                l2 = l2->next;
            }
        }      
        head = s;

        //now loop till one of them reaches null
        while(l1 and l2){
                if(l1->val <= l2->val){
                    s->next = l1;
                    l1 = l1->next;
                    s = s->next;
                }else if(l2->val <= l1->val){
                    s->next = l2;
                    l2 = l2->next;
                    s = s->next;
                }
        }
        //now if one of them is NULL point s to other
        if(l1 == nullptr) s->next = l2;
        if(l2 == nullptr) s->next = l1;  

        return head;
    }
};