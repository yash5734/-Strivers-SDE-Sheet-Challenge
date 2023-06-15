void insertAtBottom(stack<int>&s,int num){
    if(s.empty() || (!s.empty()&&s.top()<num)){
        s.push(num);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s,num);
    s.push(temp);
}

void SortedStack :: sort()
{
   //Your code here
   if(s.empty()) return;
   int temp = s.top();
   s.pop();
   sort();
   insertAtBottom(s,temp);
}
