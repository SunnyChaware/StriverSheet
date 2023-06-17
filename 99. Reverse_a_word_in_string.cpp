// (tc, sc) -> ( o(n^2), o(n) )
#include<bits/stdc++.h>
string reverseString(string &str){
	string ans;
	int n = str.size();
	int i = 0;
	while(i<n){
		while(i<n and str[i]==' ')i++;
		string temp;
		while(i<n and str[i]!=' '){
			temp+=str[i];
			i++;
		}
		if(temp.size()!=0){
			ans.insert(0,temp+" ");
		}
		i++;
	}
	if(ans.length()==0)return ans;
	return ans.substr(0, ans.length() - 1);
}



// (tc, sc) -> ( o(n), o(n) )
string reverseString(string &str){
	if(str == "" || str == " ")return "";
	string ans;
	int i = str.size()-1;

	while(i>=0){
		if(str[i]==' ')i--;
        else {
			if(ans.size()>0)ans+=' ';
			int j = i;
			while(j>=0 and str[j]!=' ')j--;
			ans.append(str.substr(j+1, i-j));
            i = j;
		}
    }
	return ans;
}
