LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> * prev = nullptr, *curr = head;
    while(curr != nullptr){
        LinkedListNode<int> * next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    return prev;
}
