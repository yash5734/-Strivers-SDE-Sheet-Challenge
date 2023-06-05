#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr) {
	// Write your code here
    int n = arr.size();
    vector<int>ans;
	map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	int floor = n/3;
	for(int i =0;i<n;i++){
          if (mp[arr[i]] > floor && mp[arr[i]] !=-1) {
            mp[arr[i]] = -1;
            ans.push_back(arr[i]);
          }
        }
	return ans;
}
