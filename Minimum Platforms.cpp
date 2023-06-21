class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                count++;
                i++;
                ans = max(ans, count);
            } else {
                count--;
                j++;
            }
        }
        return ans;
    }
};
