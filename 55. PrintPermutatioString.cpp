#include <bits/stdc++.h> 
void f(string &s, int ind, vector<string> &ans){
    if(ind == s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[ind], s[i]);
        f(s,ind+1,ans);
        swap(s[ind], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    f(s,0,ans);
    return ans;
}
