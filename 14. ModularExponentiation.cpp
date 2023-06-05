#include <bits/stdc++.h>

long long power(long long x, long long y, long long mod){
    long long res = 1;    
    x = x % mod; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}


int modularExponentiation(int x, int n, int m) {
	return power(x,n,m);
}
