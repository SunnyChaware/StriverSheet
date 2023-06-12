int calculateMinPatforms(int a[], int b[], int n) {
    sort(a,a+n);
    sort(b,b+n);

    int p=1, ans = 1;

    int i = 1, j = 0;
    while(i<n and j<n){
        if(a[i]<=b[j]){
            p++;
            i++;
        }
        else p--,j++;

        ans = max(ans, p);
    }
    return ans;
}
