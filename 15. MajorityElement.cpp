#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int c = 1;
	int res = 0;
	for(int i=1;i<n;i++){
		if(arr[i]==arr[res]){
			c++;
		}
		else{
			c--;
			if(c==0){
				c=1,res = i;
			}
		}
	}
	int x = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == arr[res])x++;
	}
	if(x > (n>>1))return arr[res];
	return -1;
}
