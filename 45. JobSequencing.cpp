#include <bits/stdc++.h> 
bool c(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), c);
    int maxi = INT_MIN, ans = 0, n = jobs.size();

    for(int i=0;i<n;i++){
        maxi = max(maxi, jobs[i][0]);
    }
    vector<int> temp(maxi+1, -1);

    for(int i=0;i<n;i++){
        for(int j = jobs[i][0]; j>=1; j--){
            if(temp[j]==-1){
                ans+=jobs[i][1];
                temp[j] = i;
                break;
            }
        }
    }
    
    return ans;
}
