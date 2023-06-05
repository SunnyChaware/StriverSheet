#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    map<int, int> mp;
    for(auto it: arr){
        mp[it]++;
    }
    for(auto it: mp){
        if(it.second > (n/3)){
            ans.push_back(it.first);
        }
    }
    return ans;
}


////////////////////////////////////////////////////////////////
//              Moores Voting algorithm                       //
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int fcan=0, scan=0, fc =0, sc =0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i] == fcan)fc++;
        else if(arr[i] == scan) sc++;
        else if(fc==0){
            fcan = arr[i];
            fc = 1;
        }
        else if(sc == 0){
            scan = arr[i];
            sc = 1;
        }
        else{
            fc--;
            sc--;
        }
    }
    fc = 0, sc = 0;
    for(auto it: arr){
        if(it == fcan)fc++;
        else if(it == scan)sc++;
    }

    if(fc>n/3)ans.push_back(fcan);
    if(sc>n/3)ans.push_back(scan);

    return ans;
}
