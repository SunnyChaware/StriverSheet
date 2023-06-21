//============o(n2)
#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> ans;
    ans.push_back(1);

    for(int i=1;i<n;i++){
        int c = 0;
        for(int j=i ; j >=0; j--){
            if(price[j]<=price[i])c++;
            else break;
        }
        ans.push_back(c);
    }
    return ans;
}

////============o(n)

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n = price.size();

    vector<int> ans(n);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        while(!stk.empty() && price[stk.top()] <= price[i]) {
            stk.pop();
        }

        if(stk.empty() == true) {
            ans[i] = i + 1;
        } else {
            ans[i] = i - stk.top();
        }

        stk.push(i);
    }
    return ans;
}
