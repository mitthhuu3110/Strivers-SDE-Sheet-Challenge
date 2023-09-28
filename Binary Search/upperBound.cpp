int upperBound(vector<int> &arr, int x, int n) {
	// Write your code here
	int low = 0;
	int high = n-1;
	int res = n;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] > x){
			res = mid;
			high = mid-1;
		}else low = mid + 1;
	}
	return res;
}
