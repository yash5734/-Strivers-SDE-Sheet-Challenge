#include<bits/stdc++.h>
using namespace std;

class Queue{
    int size;
    int front;
    int top;
    int *arr;
    public:

    Queue(){
        size = 100000;
        front = 0;
        arr = new int[size];
        top = -1;
    }

    void push(int val){
        top++;
        arr[top] = val;
    }
    int pop(){
        int temp = arr[front];
        front++;
        return temp;
    }
    int Front(){
        return arr[front];
    }
    int Size(){
        return top - front + 1;
    }
};
int main(){
    Queue q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    cout << q.Size();
    cout << q.Front();
}
