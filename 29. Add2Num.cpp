/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
// Node* rev(Node * head){
//     Node * prev = nullptr, * curr = head;
//     while(curr != nullptr){
//         Node * next = curr->next;
//         curr->next = prev;

//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

// void dis(Node * head){
//     while (head != NULL) {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }

Node *addTwoNumbers(Node *num1, Node *num2){

    Node * t1 = num1, *t2 = num2;
    int temp = t1->data + t2->data;

    int carry = temp/10;
    int sum = temp%10;

    Node * n = new Node(sum);
    Node * nh = n;

    t1=t1->next;
    t2=t2->next;

    while(t1!=nullptr and t2!=nullptr){
        temp = carry + t1->data + t2->data;
        carry = temp/10;
        sum = temp%10;

        n->next = new Node(sum);
        n = n->next;

        t1=t1->next;
        t2=t2->next;
    }

    if(t2==NULL){
        while(t1!=nullptr){
            // cout<<"l";
            temp = t1->data + carry;
            carry = temp/10;
            sum = temp%10;
            n->next = new Node(sum);
            n = n->next;
            t1=t1->next;
        }
    }
    if(t1==NULL){
        while(t2!=nullptr){
            temp = t2->data + carry;
            carry = temp/10;
            sum = temp%10;
            n->next = new Node(sum);
            n = n->next;
            t2=t2->next;
        }
    }
    if(carry!=0)n->next = new Node(carry);
    return nh;
}
