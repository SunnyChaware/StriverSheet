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
int length(Node *head)
{
    int length = 0;
    Node *tmp = head;

    while (tmp != NULL){
        tmp = tmp->next;
        length++;
    }

    return length;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int c1=length(firstHead), c2=length(secondHead);

    while(c1>c2){
        firstHead = firstHead->next;
        c1--;
    }
    while(c1<c2){
        secondHead = secondHead->next;
        c2--;
    }

    while(firstHead!=secondHead){
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return firstHead;
}
