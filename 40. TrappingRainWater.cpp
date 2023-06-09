#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> f(n,0), b(n,0);
    f[0] = arr[0], b[n-1] = arr[n-1];
    // cout<<f[0]<< " "<<b[n-1];
    for(int i=1;i<n;i++){
        f[i] = max(f[i-1], arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        b[i] = max(b[i+1], arr[i]);
    }

    // for(auto it: f)cout<<it<<" ";
    // cout<<endl;
    // for(auto it: b)cout<<it<<" ";
    long res = 0;
    for(int i=1;i<n-1;i++){
        res += (min(f[i],b[i])-arr[i]);
    }
    return res;
}
