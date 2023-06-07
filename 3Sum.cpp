#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
  set<vector<int>>main;
  
  for(int i=0;i<n;i++){
    set<int>hashSet;
    for(int j=i+1;j<n;j++){
      int sum = K-(arr[i]+arr[j]);
      if(hashSet.find(sum) != hashSet.end()){
        vector<int> v = {arr[i], arr[j], sum};
        sort(v.begin(), v.end());
        main.insert(v);
      }
      hashSet.insert(arr[j]);
    }
  }
    vector<vector<int>>ans(main.begin(),main.end());
    return ans;
}
