class Solution{
public:
    void help(int sum, int i, vector<int>&v, vector<int> &arr, int N){
        if(i == N){
            v.push_back(sum);
            return;
        }
        //if picked
        help(sum + arr[i], i+1, v, arr, N);
        //if not picked
        help(sum, i+1, v, arr, N);
    }

    
    vector<int> subsetSums(vector<int> arr, int N){
        // Write Your Code here
      vector<int> v;
      help(0, 0, v, arr, N);
      sort(v.begin(), v.end());
      return v;
    }
};
