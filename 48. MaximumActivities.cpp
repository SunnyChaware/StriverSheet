#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        arr.push_back({finish[i], start[i]});
    }

    sort(arr.begin(), arr.end());

    int ans = 1;
    int limit = arr[0].first;

    for(int i=1;i<n;i++){
        if(arr[i].second >= limit){
            ans++;
            limit = arr[i].first;
        }
    }
    return ans;
}
