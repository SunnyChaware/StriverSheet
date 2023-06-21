#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> st;
    for(int i = 0; i < n; i++) {
        st.push(i);
    }

	while(st.size() > 1) {
        int id1 = st.top();
        st.pop();
        int id2 = st.top();
        st.pop();
        
        if(knows(id1, id2)) {
            st.push(id2); 
        }
        else {
            st.push(id1); 
        }
    }

		int ans = st.top();
		bool kall = true, knownany = false;


	// checking if celeb knows anyone
		for(int i = 0; i < n; i++) {
        	if(knows(ans, i)) {
				knownany = true;
				break;
        	}
    	}

	// checking if everyoneknows celeb
		for(int i = 0; i < n; i++) {
			if(i != ans and !knows(i, ans)) {
				kall = false;
				break;
			}
		}
		
		if(knownany or !kall) {
			ans = -1;
		}
	return ans;

}
