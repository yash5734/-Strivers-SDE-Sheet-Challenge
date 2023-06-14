// optimal approch tc = O(N2) sc = O(N)

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int>num;
        int fact= 1;
        for(int i=1;i<n;i++){
            fact = fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        k = k-1;
        while(true){
            ans = ans + to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            
            if(num.size()==0)break;

            k = k % fact;
            fact = fact/num.size();
        }
        return ans;
    }
};


// BRUTE FORCE TC = O(N2) SC = O(N2)


class Solution {
private:
void solve(int ind,int n, string ds,vector<string>&ans,vector<bool>flag){
    if(ds.length()==n){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<n;i++){
        if(flag[i]==false){
            flag[i] = true;
            ds.push_back(i+1+'0');
            solve(i+1,n,ds,ans,flag);
            flag[i] = false;
            ds.pop_back();
        }
    }
}

public:
    string getPermutation(int n, int k) {
        vector<string>ans;
        vector<bool>flag(n);
        string ds="";
        solve(0,n,ds,ans,flag);
        return ans[k-1];
    }

};
