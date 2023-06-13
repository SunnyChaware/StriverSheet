void f(int ind, vector<int> &arr, int target, vector<int>&ds, vector<vector<int>> &ans){
    if(ind == arr.size()){
        if(target == 0 and ds.size()!=0){
            ans.push_back(ds);
        }
        return;
    }


    f(ind+1,arr,target,ds,ans);
    ds.push_back(arr[ind]);
    f(ind+1,arr,target-arr[ind],ds,ans);
    ds.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    f(0,arr,k,ds,ans);
    return ans;
}
