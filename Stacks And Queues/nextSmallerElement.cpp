#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    // Write your code here.
    stack<int> s;
    vector<int> res(n, -1);
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()) res[i] = -1;
        else res[i] = s.top();
        s.push(arr[i]);
    }
    return res;
}
