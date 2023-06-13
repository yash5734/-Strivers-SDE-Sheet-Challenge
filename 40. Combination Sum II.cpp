class Solution {
    private:
    void solve(int ind,int target, vector<int>candidates,vector<vector<int>>&ans,vector<int>ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(target<=0) return;

        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(i>ind && candidates[i]==candidates[i-1])continue;
            ds.push_back(candidates[i]);
            solve(i+1,target - candidates[i],candidates,ans,ds);
            ds.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,candidates,ans,ds);
        return ans;
    }
};
