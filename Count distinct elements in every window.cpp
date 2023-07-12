class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        int ptr1 =0;
        int ptr2 = k-1;
        unordered_map<int,int>mp;
        for(int i=ptr1;i<=ptr2;i++){
            mp[arr[i]]++;
        }
        vector<int>ans;
        ans.push_back(mp.size());
        
        while(ptr2<n-1){
            
            mp[arr[ptr1]]--;
            if(mp[arr[ptr1]]==0){
                mp.erase(arr[ptr1]);
            }
            ptr2++;
            ptr1++;
            
            mp[arr[ptr2]]++;
            
            ans.push_back(mp.size());
        }
        return ans;
    }
};
