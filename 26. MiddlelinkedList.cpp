Node *findMiddle(Node *head) {
    if(head==nullptr || head->next == nullptr)return head; 
    Node *slow = head, *fast = head;
    while(fast!=nullptr and fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
