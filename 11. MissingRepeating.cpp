#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int, int> ans;
	for(int i=0;i<n;i++){
		if(arr[abs(arr[i])-1]<0){
			ans.second = abs(arr[i]);
		}
		else{
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i]>0)ans.first = i+1;
	}
	return ans;
	
}
