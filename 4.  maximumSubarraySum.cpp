// Normal Kadanes algotithm 
// ut here if the result is negative you have to return 0;

#include <bits/stdc++.h> 
#define ll long long
long long maxSubarraySum(int arr[], int n)
{
    ll maxi = INT_MIN;
    ll sum = 0;
    for(int i=0;i<n;i++){
        if(sum<0)sum=0;
        sum+=arr[i];
        maxi = max(maxi, sum);
    }
    if(maxi < 0)return 0;
    return maxi;
}
