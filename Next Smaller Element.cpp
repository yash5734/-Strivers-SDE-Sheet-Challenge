#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    vector<int>ans(n);
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top()>=arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
