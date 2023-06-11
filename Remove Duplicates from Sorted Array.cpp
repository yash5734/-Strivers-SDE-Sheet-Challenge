
// optimal approch tc = O(N) SC = O(1);
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ptr =0;
        for (int i=0;i<n;i++){
            if(nums[i] != nums[ptr]){
                ptr++;
                nums[ptr] = nums[i];
            }
        }
        return ptr+1;
    }
};

// brute force tc O(nlogn) sc = O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.insert(nums[i]);
        }
        int i=0;
        for(auto it : temp){
            nums[i++] = it;
        }
        return temp.size();
    }
};
