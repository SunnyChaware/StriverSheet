#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> win(k);

    for(int i=0;i<k;i++){
        while(win.empty()==false and nums[i]>=nums[win.back()]){
            win.pop_back();
        }
        win.push_back(i);
    }
    
    for(int i=k;i<n;i++){
        ans.push_back(nums[win.front()]);
        while(win.empty()==false and win.front()<=i-k){
            win.pop_front();
        }
        while(win.empty()==false and nums[i]>=nums[win.back()]){
            win.pop_back();
        }
        win.push_back(i);
    }
    ans.push_back(nums[win.front()]);
    return ans;
}
