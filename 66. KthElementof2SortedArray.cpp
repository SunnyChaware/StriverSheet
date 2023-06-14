#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n, int m, int k) {
    if(m>n){
        ninjaAndLadoos(b,a,m,n,k);
    }

    int low = max(0, k-m), high = min(k,n);
    
    while(low<=high){
        int i1 = (low+high)/2;
        int i2 = k-i1;

        int min1 = (i1==n)?INT_MAX:a[i1];
        int max1 = (i1==0)?INT_MIN:a[i1-1];
        int min2 = (i2==m)?INT_MAX:b[i2];
        int max2 = (i2==0)?INT_MIN:b[i2-1];

        if(max1<=min2 and max2<=min1){
            return max(max1,max2);
        }
        else if(max1>min2)high = i1-1;
        else low= i1+1;
    }
    return 1;
}
