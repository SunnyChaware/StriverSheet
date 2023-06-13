#include<bits/stdc++.h>
string kthPermutation(int n, int k) {
    vector<int>nums;
    int fact = 1;
    for(int i=1;i<n;i++){
        nums.emplace_back(i);
        fact*=i;
    }
    nums.push_back(n);

    string ans = "";
    k--;

    while(true){
        ans+=to_string(nums[k/fact]);
        nums.erase(nums.begin()+ k/fact);
        if(nums.size()==0){
            break;
        }
        k = k%fact;
        fact = fact/nums.size();
    }
    return ans;
}
