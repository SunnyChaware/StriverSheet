#include <bits/stdc++.h> 
int cnt = 0;
void merge(long long *arr, int low, int mid, int high){
    vector<int> temp;
    int l = low, r = mid+1;

    while(l<=mid and r<=high){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{
            temp.push_back(arr[r]);
            cnt+=(mid - l + 1);
            r++;
        }
    }

    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        temp.push_back(arr[r]);
        r++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}
void mergeSort(long long *arr, int low, int high){
    if(low<high){
        int mid = (low + high)>>1;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

long long getInversions(long long *arr, int n){
    mergeSort(arr, 0, n-1);
    return cnt;
}
