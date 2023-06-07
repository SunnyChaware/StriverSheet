#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    unordered_map<char, int> mp;
    int n = s.size();
    int ans = 0;
    int l =0, r=0;
    while(r<n){
        if(mp.find(s[r])!=mp.end())l=max(mp[s[r]]+1, l);
        mp[s[r]] = r;
        ans = max(ans, r-l+1);
        r++;
    }
    return ans;
}


// https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_8230684?challengeSlug=striver-sde-challenge&leftPanelTab=0
