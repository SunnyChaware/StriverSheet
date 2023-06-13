#include<bits/stdc++.h>
void f(int ind, vector<int> &arr, int target, vector<int>&ds, vector<vector<int>> &ans){
    if(target == 0){
		ans.emplace_back(ds);
        return;
    }

	for(int i=ind; i<arr.size(); i++){
		if(i>ind and arr[i]==arr[i-1])continue;
		if(arr[i]>target) break;
        ds.push_back(arr[i]);
        f(i+1,arr,target-arr[i],ds,ans);
        ds.pop_back();
	}


}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
    vector<int> ds;
    f(0,arr,target,ds,ans);
    return ans;
}
