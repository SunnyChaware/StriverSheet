#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if (head == NULL) {
        return NULL;
    }
	
	int ind = 0;
	Node *prev = NULL, *cur = head, *next = NULL;
    Node *tail = NULL, *join = NULL;
    bool isHeadUpdated = false;

	while(cur!=NULL and ind<n){
		int k = b[ind];
		
		if(k==0){
			ind++;
			continue;
		}

		join = cur;
		prev = NULL;
		
		while(cur!=NULL and k--){
			next = cur->next;
			cur->next = prev;
			
			prev = cur;
			cur = next;
		}

		if (isHeadUpdated == false) {
            head = prev;
            isHeadUpdated = true;
        }
		
		if (tail != NULL) {
            tail->next = prev;
        }
		tail = join;
        ind++;
	}
	if (tail != NULL) {
        tail->next = cur;
    }

    // Return the head of the linked list.
    return head;
}
