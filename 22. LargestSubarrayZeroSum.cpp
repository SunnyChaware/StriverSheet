#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  unordered_map<int, int> mp;
  int sum = 0, ans = 0;
  mp[0] = -1;
  for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    if(mp.find(sum)!=mp.end()){
      ans = max(ans, i-mp[sum]);
    }
    else
    mp[sum] = i;
  }
  return ans;
}
