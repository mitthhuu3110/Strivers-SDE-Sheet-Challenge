double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	vector<int> c;
	for(int i = 0; i < a.size(); i++){
		c.push_back(a[i]);
	}
	for(int i = 0; i < b.size(); i++){
		c.push_back(b[i]);
	}
	sort(c.begin(), c.end());
	double med = 0;
	if(c.size()%2 != 0){
		med = c[c.size()/2.00];
		return med;
	}else{
		med = (c[c.size()/2] + c[(c.size()/2) - 1])/2.00;
		return med;
	}

	return -1;
}
