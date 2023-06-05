#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int missing =0;
	int repeat = 0;
	map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(mp[i] == 0) missing = i;
		if(mp[i] == 2) repeat = i;
	}
	return {missing,repeat};
	
}
