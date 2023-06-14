double median(vector<int>& a, vector<int>& b) {
	int n1 = a.size();
	int n2 = b.size();

	// smaller array in a
	if(n1>n2){
		median(b,a);
	}

	int start = 0, end = n1-1;
	while(start <= end){
		int i1 = (start+end)/2;
		int i2 = ((n1+n2+1)/2) - i1;

		int min1 = (i1==n1)?INT_MAX : a[i1];
		int max1 = (i1==0)?INT_MIN : a[i1-1];
		int min2 = (i2==n2)?INT_MAX : b[i2];
		int max2 = (i2==0)?INT_MIN : b[i2-1];

		if((max1 <= min2) and (max2<=min1)){
			if((n1+n2)&1){
				return (double)max(max1,max2);
			}
			else{
				return ( ((double)max(max1,max2) + (double)min(min1,min2))/2 );
			}
		}
		else if(max1>min2) end = i1-1;
		else start = i1+1;
	}

}
