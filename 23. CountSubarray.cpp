#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mp;
    int c = 0, xorr = 0;
    for(auto it: arr){
        xorr ^= it;

        if(xorr == x)c++;

        if(mp.find(xorr^x)!=mp.end()){
            c+=mp[xorr^x];
        }
        mp[xorr]++;
    }
    return c;
}


// https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge
