#include <bits/stdc++.h> 
int merge(int low, int mid, int high, vector<int> &arr){
	int c=0;
	int s = mid+1;
	for(int i = low; i<= mid; i++){
		while(s<=high and arr[i]>2LL*arr[s]){
			s++;
		}
		c+=(s-(mid+1));
	}
	
	vector<int> temp;
	int l = low, r = mid+1;
	while(l<=mid and r<=high){
		if(arr[l] <= arr[r]){
			temp.push_back(arr[l++]);
		}
		else{
			temp.push_back(arr[r++]);
		}
	}
	while(l<=mid){
		temp.push_back(arr[l++]);
	}
	while(r<=high){
		temp.push_back(arr[r++]);
	}

	for(int i=low;i<=high;i++){
		arr[i] = temp[i-low];
	}
	return c;
}
int mergeSort(vector<int> &arr, int low, int high){
	
    if(low>=high)return 0;
    int mid = (low + high)/2;
	int inv = mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid+1, high);
    inv += merge(low, mid, high, arr);
    
	return inv;
}
int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr, 0, n-1);
}
