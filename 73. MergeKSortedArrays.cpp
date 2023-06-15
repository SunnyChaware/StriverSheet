#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> temp;
    for(int i=0;i<arr.size();i++){
        vector<int> xxx;
        int x = 0, y = 0;
        while(x<temp.size() and y<arr[i].size()){
            if(temp[x]<arr[i][y]){
                xxx.push_back(temp[x]);
                x++;
            }
            else{
                xxx.push_back(arr[i][y]);
                y++;
            }
        }
        while(x<temp.size()){
            xxx.push_back(temp[x++]);
        }
        while(y<arr[i].size()){
            xxx.push_back(arr[i][y]);
            y++;
        }
        temp = xxx;
    }
    return temp;
}
