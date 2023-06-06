int removeDuplicates(vector<int> arr, int n) {
	// Write your code here.
	int ind = 0;
	int cnt = 0;
	for(int i=0;i<n-1;i++){
          if (arr[i] == arr[i + 1]) {
            ind = i + 1;
			cnt++;
          }
        }
	
	
	return arr.size()-cnt;
}
