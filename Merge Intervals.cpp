#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
sort(arr.begin(), arr.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });    
        vector<vector<int>>ans;
    vector<int>curr = arr[0];
    for(int i=1;i<arr.size();i++){
        if(curr[1]<arr[i][0]){
            ans.push_back(curr);
            curr=arr[i];
        }else{
            curr[1] = max(curr[1],arr[i][1]);
        }
    }
    ans.push_back(curr);
    return ans;
}
