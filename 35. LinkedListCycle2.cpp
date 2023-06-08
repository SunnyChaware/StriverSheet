/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    bool f = false;
    Node * slow = head, *fast = head;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            f = true;
            break;
        }
    }
    if(!f)return NULL;

    slow= head;
    while(slow!=fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return fast;

}
