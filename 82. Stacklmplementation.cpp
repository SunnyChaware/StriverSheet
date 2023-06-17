#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> arr;
    int size;
    int n;
    
    Stack(int n) {
        this->arr.resize(n);
        this->size = -1;
        this->n = n;
    }

    void push(int num) {
        // Write your code here.
        if(size!=n-1){
            ++size;
            arr[size] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(size!=-1){
            --size;
            return arr[size+1];
        }
        else return -1;
    }
    
    int top() {
       if(size!=-1){
           return arr[size];
       }
       else return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(size!=-1)return 0;
        return 1;
    }
    
    int isFull() {
        // Write your code here.
        if(size!=n-1)return 0;
        return 1;
    }
    
};
