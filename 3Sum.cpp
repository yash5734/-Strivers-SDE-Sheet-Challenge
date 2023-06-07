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

// Optimal Approach


#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
vector<vector<int>>ans;
sort(arr.begin(),arr.end());
for(int i=0;i<n;i++){
  if(i>0 && (arr[i]==arr[i-1]))continue;
  int j = i+1;
  int k = n-1;
  while(j<k){
    int sum = arr[i]+arr[j]+arr[k];
    
    if(sum>K){
      k--;
    }
    else if(sum<K){
      j++;
    }
    else{
      vector<int>v = {arr[i],arr[j],arr[k]};
      ans.push_back(v);
      j++;
      k--;
      while(j<k&&arr[j] == arr[j-1]) j++;
      while(j<k && arr[k]==arr[k+1]) k--;
    }
  }
}
return ans;
  
}
