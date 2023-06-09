/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node *rev(Node* head){
     Node*prev=nullptr, *curr = head;
     while(curr!=NULL){
          Node * next = curr->next;
          curr->next = prev;

          prev = curr;
          curr = next;
     }
     return prev;
}
int length(Node *head){
     int c = 0;
     Node * temp = head;
     while(temp!=NULL){
          c++;
          temp = temp->next;
     }
     return c;
}
Node *rotate(Node *head, int k) {
     Node * f= head, * s=head, *prev=head;
     int len = length(head);
     k = k%len;
     int t = len - k;
     while(t--){
          prev = f;
          f = f->next;
     }
     // cout<<f->data;
     prev->next=nullptr;
     Node *n1 = rev(s);
     Node *n2 = rev(f);
     Node * temp = n1;
     while(temp->next!=NULL){
          temp = temp->next;
     }
     temp->next = n2;


     return rev(n1);
}
