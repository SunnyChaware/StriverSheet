#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	long long maxi = INT_MIN;
	long long pro = 1;

	for(auto it: arr){
		pro = it*pro;
		maxi = max(maxi, pro);
		if(pro==0)pro=1;
	}

	pro = 1;
	reverse(begin(arr), end(arr));
	for(auto it: arr){
	    pro *= it;
	    maxi = max(maxi, pro);
	    if(pro == 0)pro = 1;
	}
	
	return maxi;
}
