#include <bits/stdc++.h> 
bool ispal(string s, int l, int r){
    while(l<=r){
        if(s[l++]!=s[r--])return false;
    }
    return true;
}

void f(int ind, string s, vector<string>&ds, vector<vector<string>>&ans){
    if(ind == s.size()){
        ans.emplace_back(ds);
        return;
    }

    for(int i=ind; i<s.size(); i++){
        if(ispal(s,ind,i)){
            ds.emplace_back(s.substr(ind,i-ind+1));
            f(i+1,s,ds,ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> ds;
    f(0,s,ds,res);
    return res;
}
