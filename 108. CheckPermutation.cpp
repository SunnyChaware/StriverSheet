#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    map<char,int> mp;
    for(auto it: str1)mp[it]++;
    for(auto it: str2)mp[it]++;

    for(auto it: mp){
        if(it.second &1)return false;
    }
    return true;
}
