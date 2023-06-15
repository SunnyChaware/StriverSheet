#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int>mp;
    for(auto it: arr){
        mp[it]++;
    }
    vector<int> xxx[n+1];
    
    for(auto it: mp){
        xxx[it.second].push_back(it.first);
    }

    vector<int> ans(k);
    int curr = 0;

    for(int i=n ; i>0 and k>0 ; i--){
        if(xxx[i].size()==0)continue;

        for(auto it: xxx[i]){
            ans[curr++] = it;
            k--;
            if(k==0)break;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
