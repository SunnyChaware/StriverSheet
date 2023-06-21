#include <bits/stdc++.h> 
int atoi(string str) {
   int n = str.size();
   int ans = 0;
   bool f = false;
   if(str[0]=='-')f = true;
   for(int i=0;i<n;i++){
       if(str[i]>='0' and str[i]<='9'){
            ans*=10;
            ans += (str[i] - '0');
            
       }
   }
   return f?(-1*ans):ans;
}
