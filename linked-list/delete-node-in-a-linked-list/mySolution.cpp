struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
       //if node is the last node yhen simply delete
       if(!node->next) node = NULL; 
       else{
           //copy the next nodes data and delete the next node by bypasssing
           //next pointer of current node
           node->val = node->next->val;
           node->next = node->next->next;
       }
    }
};