#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty())ans[i]=-1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}
