bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int begin = 0, end = n*m-1;

    while(begin<=end){
        int mid = (begin+end)>>1;
        int midval = mat[mid/m][mid%m];

        if(midval == target)return true;
        else if(midval <= target)begin = mid+1;
        else end = mid-1;
    }
    return false;
}
