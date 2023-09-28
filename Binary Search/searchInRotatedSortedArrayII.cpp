bool searchInARotatedSortedArrayII(vector<int>&A, int k) {
    // Write your code here.
    int low = 0;
    int high = A.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(A[mid] == k) return true;
        if(A[low] == A[mid] && A[mid] == A[high]){
            low++;
            high--;
            continue;
        }
        if(A[low] <= A[mid]){
            if(A[low] <= k && k <= A[mid]){
                high = mid - 1;
            }else low = mid + 1;
        }
        else{
            if(A[mid] <= k && k <= A[high]){
                low = mid + 1;
            }else high = mid - 1;
        }
    }

    return false;
}
