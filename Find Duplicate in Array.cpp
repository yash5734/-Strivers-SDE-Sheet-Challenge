#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	map<int,int>mp;
	int ans =0;
	for(int i=0;i<n;i++){
        if (mp[arr[i]] == 1) {
            ans = arr[i];
			break;
        }
        mp[arr[i]] = 1;
	}
	return ans;

}
