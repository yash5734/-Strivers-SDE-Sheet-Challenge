#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int maxi = 1;
    int cnt = 1;
    int curr = arr[0];
    for(int i=0;i<n;i++){
         
        if(arr[i] == curr+1){
            cnt++;
            
        }else if(curr!=arr[i]) cnt =1;
        curr = arr[i];
        maxi = max(maxi,cnt);
    }
    return maxi;
}
