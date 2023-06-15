#include <bits/stdc++.h>
using namespace std;
class Stack{
    int top;
    int *arr;
    int size;
    public:
    Stack(){
        top = -1;
        size = 100000;
        arr = new int[size];
    }
    void push(int val){
        top++;
        arr[top] = val;
    }

    int Top(){
        return arr[top];
    }

    int pop(){
        int temp = arr[top];
        top--;
        return temp;
    }

    int Size(){
        return top + 1;
    }
};

int main(){

    Stack st;
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    cout << st.Top();
    return 0;
}
