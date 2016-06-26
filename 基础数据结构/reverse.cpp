ListNode* reverseList(ListNode* head) {
    if(!head)return head;
    if(!head->next)return head;
    auto p=head;
    ListNode* pre=nullptr;
    while(p){
        auto q=p->next;
        p->next=pre;
        pre=p;
        p=q;
        
    }
    return pre;
}