#include <bits/stdc++.h>
#define ll long long int
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1; j<n-2;j++){
            int l = j+1, r = n-1;

            while(l<r){
                if(arr[i]+arr[j]+arr[l]+arr[r] == target){
                    return "Yes";
                }
                else if(arr[i]+arr[j]+arr[l]+arr[r] < target)l++;
                else r--;
            }
        }
    }
    return "No";
}
