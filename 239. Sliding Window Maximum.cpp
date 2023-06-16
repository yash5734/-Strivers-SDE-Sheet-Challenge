//using pointer approch tc - O(n*k)

class Solution {
    private:
    int maxFun(int start,int end, vector<int>arr){
        int maxi  =INT_MIN;
        while(start<=end){
            maxi  =max(maxi,arr[start]);
            start++;
        }
        return maxi;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int ptr1 = 0;
        int ptr2 = k-1;
        int n = nums.size();
        int maxi =0;
        vector<int>ans;

        while(ptr2<n){
        maxi = maxFun(ptr1,ptr2,nums);
        ptr1++;
        ptr2++;
        ans.push_back(maxi);
        }
        return ans;
    }
};

// using dequeu tc = O(n);


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){

            // remove if deque have out of boundary element

            if(!dq.empty() && dq.front() == i-k) {
                dq.pop_front();
            }

            // remove if dequeu has non decreasing order

            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // push the ans into array if index is greater then the k;

            if(i >=k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
