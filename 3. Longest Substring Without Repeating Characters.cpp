class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int start =0;
        int end = 0;
        int max =0;
        while(start<s.length()){
            char it = s[start];
            if(st.find(it) == st.end()){
                if(max<start-end+1){
                    max = start-end+1;
                }
                st.insert(s[start]);
                start++;
            }
            else{
                st.erase(s[end]);
                end++;
            }
        }
        return max;
    }
};
