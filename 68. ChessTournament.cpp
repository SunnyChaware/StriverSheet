#include <bits/stdc++.h> 
bool isposible(vector<int> &positions, int c, int mid){
	int allot = 1;
	int preRoom = positions[0];
	for(int i=0;i<positions.size();++i){
		if(positions[i] - preRoom >= mid){
			allot++;
			if(allot>=c)return true;
			preRoom = positions[i];
		}
	}
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
	int s = 1;
	int e = positions[n-1];
	int ans = 1;

	while(s<=e){
		int mid = (s+e)>>1;

		if(isposible(positions,c,mid)){
			s = mid+1;
			ans = mid;
		}
		else e = mid-1;
	}
	return ans;
}
