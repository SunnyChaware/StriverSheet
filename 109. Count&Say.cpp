#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n==1)return "1";
	if(n==2)return "11";

	string s = "11";
	for(int i=3;i<=n;i++){
		string temp = "";
		s+='$';
		int c = 1;
		for(int j=1;j<s.size();j++){
			if(s[j]==s[j-1]){
				c++;
			}
			else{
				temp += to_string(c);
				temp+=s[j-1];
				c=1;
			}
		}
		s = temp;
	}	
	return s;
}
