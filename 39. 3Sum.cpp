#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>>ans;
	sort(arr.begin(), arr.end());
	for(int i=0;i<n;i++){
		int j = i+1, k = n-1;
		int kk = K - arr[i];

		while(j<k){
			int val = arr[j] + arr[k];
			if(val < kk){
				j++;
			}
			else if(val > kk){
				k--;
			}
			else {
				int x = arr[j];
				int y = arr[k];
				ans.push_back({arr[i], arr[j], arr[k]});
				while (j < k and arr[j] == x)
				j++;
				while (j < k and arr[j] == y)
				k--;
			}
		}
		while(i+1<n and arr[i]==arr[i+1])i++;
		
    }
    return ans;
}
