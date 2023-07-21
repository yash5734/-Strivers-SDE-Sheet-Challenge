class Solution {
    private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = 0 + f(i-1,j-1,s1,s2,dp);
        }
        else{
           int insert = 1+f(i,j-1,s1,s2,dp);
           int Delete = 1+f(i-1,j,s1,s2,dp);
           int replace = 1+f(i-1,j-1,s1,s2,dp);

           return dp[i][j] = min(insert,min(Delete,replace)); 
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};