bool isValidParenthesis(string e)
{
    int n = e.size();
    stack<char> st;
    for(auto i:e){
        if(i=='(' || i=='[' || i=='{'){
            st.push(i);
        }
        else{
            if(st.empty() or 
                (st.top() == '(' and i!=')') or 
                (st.top() == '[' and i!=']') or 
                (st.top() == '{' and i!='}'))return false;
                st.pop();
        }
    }
    return (st.empty());
}
