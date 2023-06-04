#include <bits/stdc++.h>
// inplace solution
int findDuplicate(vector<int> &arr, int n){
	for(int i=0;i<n;i++){
		if( arr[abs(arr[i])-1] < 0 ){
			return abs(arr[i]);
		}
		else arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
	}
	return 0;
}
