class Solution

{
    private:
    void solve(int ind,int sum,vector<int>&arr,vector<int>&ans,int n){
        if(ind == n){
         ans.push_back(sum);
         return;
        } 
        
        solve(ind+1,sum+arr[ind],arr,ans,n);
        solve(ind+1,sum,arr,ans,n);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
       solve(0,0,arr,ans,N);
       sort(ans.begin(),ans.end());
       return ans;
    }
};
