int search(vector<int>& arr, int target) {
    // Write Your Code Here
    int high = arr.size() - 1;
    int low = 0;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target){
            high = mid - 1;
        }else low = mid + 1;
    }
    return -1;
}
