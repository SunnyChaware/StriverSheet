#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> *rev (LinkedListNode<int> *head){
    
    LinkedListNode<int> * prev = nullptr, *curr = head;
    while(curr!=NULL){
        LinkedListNode<int> *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)return true;

    LinkedListNode<int> * slow = head, * fast = head;
    while(fast!=NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    LinkedListNode<int> *f = rev(slow);
    slow = head;
    while(f!=NULL){
        if(slow->data!=f->data)return false;
        slow = slow->next;
        f = f->next;
    }
    return true;
}
