#include<bits/stdc++.h>
using namespace std;

class Stack{

    queue<int> q;
    public:
    void push(int x){
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int size(){
        return q.size();
    }
    int top(){
        return q.front();
    }
    int pop(){
        int n = q.front();
        q.pop();
        return n;
    }
};

int main(){
    Stack st;
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    st.push(16);

    cout << st.top()<<endl;
    cout << st.pop()<<endl;
    cout << st.top() << endl;
    cout << st.size() << endl;
}
