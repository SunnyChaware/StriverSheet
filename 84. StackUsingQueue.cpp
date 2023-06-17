#include <bits/stdc++.h>

class Stack {
   public:
    queue<int> *q1, *q2;

    Stack() {  
        q1 = new queue<int>();
        q2 = new queue<int>();
    }

    int getSize() {
        return q1->size();  
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(int data) {  
        q1->push(data);
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        while (q1->size() > 1) {  
            q2->push(q1->front());
            q1->pop();
        }

        int ans = q1->front();  
        q1->pop();

        queue<int> *temp = q1;  
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        while (q1->size() > 1) {  
            q2->push(q1->front());
            q1->pop();
        }

        int ans = q1->front();  
        q1->pop();
        q2->push(ans);  

        queue<int> *temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }
};
