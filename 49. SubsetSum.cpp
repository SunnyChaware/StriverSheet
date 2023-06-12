#include <bits/stdc++.h> 
void f(int ind, int sum, vector<int> &num, int n, vector<int> &ds){
    if(ind == n){
        ds.push_back(sum);
        return;
    }
    f(ind+1, sum+num[ind], num, n, ds);
    f(ind+1, sum, num, n, ds);
}
vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> ds;
    f(0,0,num,n,ds);
    sort(ds.begin(), ds.end());
    return ds;
}
