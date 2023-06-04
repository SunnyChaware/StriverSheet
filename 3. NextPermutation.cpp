#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    int l,k;
    // finding the first bigger smaller pair
    for(l=n-2;l>=0;l--){
        if(p[l]<p[l+1])break;
    }
    // if not reverse and return
    if(l<0){
        reverse(begin(p), end(p));
        return p;
    }
    else{
        // finding the first bigger
        for(k = n-1;k>=0;k--){
            if(p[k] > p[l])break;
        }
        // swapping and reversing to get the next permutation
        swap(p[l], p[k]);
        reverse(p.begin()+l+1, p.end());
        return p;
    }
    return p;
}
