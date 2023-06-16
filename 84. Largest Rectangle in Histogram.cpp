class Solution {
private:
    // Function to find the indices of the nearest left smaller element for each element
    vector<int> leftSmaller(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            // Pop elements from the stack until a smaller element is found or the stack becomes empty
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = 0; // If stack is empty, no smaller element to the left exists
            } else {
                ans[i] = st.top() + 1; // Index of the nearest smaller element to the left
            }
            
            st.push(i); // Push the current index to the stack
        }
        
        return ans;
    }

    // Function to find the indices of the nearest right smaller element for each element
    vector<int> rightSmaller(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack until a smaller element is found or the stack becomes empty
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = n - 1; // If stack is empty, no smaller element to the right exists
            } else {
                ans[i] = st.top() - 1; // Index of the nearest smaller element to the right
            }
            
            st.push(i); // Push the current index to the stack
        }
        
        return ans;
    }

public:
    // Function to calculate the largest rectangle area
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall = leftSmaller(heights, n);
        vector<int> rightSmall = rightSmaller(heights, n);
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            // Calculate the area using the nearest left and right smaller indices
            int temp = (rightSmall[i] - leftSmall[i] + 1) * heights[i];
            maxi = max(maxi, temp);
        }
        
        return maxi;
    }
};
