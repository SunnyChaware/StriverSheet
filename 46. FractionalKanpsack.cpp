#include <bits/stdc++.h> 

bool c(pair<int, int>& a, pair<int, int>& b)
{
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double ans = 0;
    int cw = 0;
    sort(items.begin(), items.end(), c);

    for(int i = 0; i < n ; i++){
        if(cw + items[i].first <= w){
            cw += items[i].first;
            ans += items[i].second;
        }
        else{
            int rw = w - cw;
            ans +=  items[i].second*((double)rw / items[i].first);
            break;
        }
    }
    return ans;

}
