Node *removeKthNode(Node *head, int K) {
    
    if (head == NULL || K == 0) {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while(K--){
        fast = fast->next;
    }

    if(fast == nullptr)return head->next;

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;

}
