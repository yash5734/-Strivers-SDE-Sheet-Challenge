class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int num = nums1[i];
            bool flag  =false;
            int max = -1;
            for(int j =0;j<nums2.size();j++){
                if(num == nums2[j]){
                    flag = true;
                }
                if(flag){
                    if(nums2[j]>num){
                        max = nums2[j];
                        break;
                    }
                }
            }
            ans.push_back(max);
        }
        return ans;
    }
};
