bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<int>st;
    st.push(-1);
    for(auto ch:expression){
        if(ch == '[' || ch == '(' || ch == '{'){
            st.push(ch);
        }
        else{
            char top = st.top();
            if (top == '[' && ch == ']' || top == '(' && ch == ')' ||
                top == '{' && ch == '}'){
                    st.pop();
                }
            else{
                return false;
            }
        }
            
    }
    st.pop();
    if(!st.empty()) return false;
    return true;
}
