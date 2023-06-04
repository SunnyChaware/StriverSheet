#include <bits/stdc++.h>
#define ll long long int
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<ll>> ans;
  for(int i=0;i<n;i++){
    vector<ll>temp;
    for(int j=0;j<=i;j++){
      // if the index if first or last puttinf zero
      if(i==j || j==0)temp.push_back(1);
      
      //addding the upper two values
      else temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
    }
    ans.push_back(temp);
  }
  return ans;
}
