struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ListNode* middleNode(struct ListNode* head){
    //take 2 pointer slow pointer and fast pointer
    ListNode* sptr, *fptr;
    sptr = fptr = head;
    while(fptr and fptr->next){
            sptr = sptr->next;
            fptr = fptr->next;
            //fast pointer should be ahead by two places
            if(fptr)
                fptr = fptr->next;
    }
    return sptr;
}