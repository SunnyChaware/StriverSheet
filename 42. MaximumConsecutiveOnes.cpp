int longestSubSeg(vector<int> &arr , int n, int k){
    int ans = 0;
    int j = -1, c = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            c++;
        }

        while(c>k){
            j++;
            if(arr[j]==0){
                c--;
            }
        }
        ans = max(ans, i-j);
    }
    return ans;
}
