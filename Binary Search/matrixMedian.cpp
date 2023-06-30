#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix){
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> median;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            median.push_back(matrix[i][j]);
        }
    }
    sort(median.begin(), median.end());
    int mid = median.size()/2;
    return median[mid];
}
