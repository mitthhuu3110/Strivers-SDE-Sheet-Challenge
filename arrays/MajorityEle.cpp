#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int, int> ump;
	for(int i = 0; i < n; i++){
		ump[arr[i]]++;
	}
	int max_count = n/2;
	int res = -1;
	for(auto i: ump){
		if(i.second > max_count){
			res = i.first;
			return res;
		}
	}
	return -1;
}


