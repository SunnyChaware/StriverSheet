#include <bits/stdc++.h>

class Queue {
    stack<int> *s1;
    stack<int> *s2;
public:
    Queue() {
        s1 = new stack<int>();
        s2 = new stack<int>();

    }
    void enQueue(int val) {
        while (!s1->empty()) {
            s2->push(s1->top());  
            s1->pop();
        }

        s1->push(val);

        while (!s2->empty()) {
            s1->push(s2->top());    
            s2->pop();
        }


    }

    int deQueue() {
        if(s1->empty()) {
            return -1;
        }

        int tp = s1->top();
        s1->pop();
        return tp;
    }

    int peek() {
        if (s1->empty()) {
            return -1;
        }

        return s1->top();
    }

    bool isEmpty() {
        return (s1->empty());
    }

};
