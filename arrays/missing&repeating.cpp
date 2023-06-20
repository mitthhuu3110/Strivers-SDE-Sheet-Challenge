#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int missing = -1;
	int repeating = -1;
	int hash[n+1] = {0};
	for(int i = 0; i < n; i++){
		hash[arr[i]]++;
	}
	for(int i = 1;i <= n; i++){
		if(hash[i] == 2) repeating = i;
		else if(hash[i] == 0) missing = i;

		if(missing != -1 && repeating != -1) break;
	}
	return {missing, repeating};
}
