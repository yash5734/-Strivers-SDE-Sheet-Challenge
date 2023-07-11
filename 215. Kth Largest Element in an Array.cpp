class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        // we push the k element
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }

        // know we contain only k largest element in the pq from the nums;
        for(int i=k;i<nums.size();i++){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        // in pq elements are stored in decreasing fashion and the top elemnt in smaller ans in above we can do that all the element in the pq i.e kth element are the larger element in the arr so we return the smaller of the kth largest in this we can get the kth larget number;
        return pq.top();
    }
};
