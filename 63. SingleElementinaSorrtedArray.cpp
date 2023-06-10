int singleNonDuplicate(vector<int>& nums)
{
	int n = nums.size();
        if(n==1)return nums[0];

    if(nums[0]!=nums[1])return nums[0];
    if(nums[n-1]!=nums[n-2])return nums[n-1];
    int l=1, r=n-2;
    while(l<=r){
        int mid = (l+r)>>1;
        if(nums[mid-1]!= nums[mid] and nums[mid+1]!=nums[mid])return nums[mid];
        if(((mid&1) and (nums[mid] == nums[mid-1])) || 
        ((mid%2==0) and (nums[mid] == nums[mid+1]))){
            l = mid+1;
        }
        else r = mid-1;
    }
    return -1;
}
