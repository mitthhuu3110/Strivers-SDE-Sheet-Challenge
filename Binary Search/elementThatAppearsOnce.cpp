#include<bits/stdc++.h>
int singleNonDuplicate(vector<int>& arr){
	// Write your code here
	unordered_map<int, int> ump;
	for(int i = 0;  i < arr.size(); i++){
		ump[arr[i]]++;
	}
	int res = 0;
	for(auto it: ump){
		if(it.second == 1) res = it.first;
	}
	return res;
}
