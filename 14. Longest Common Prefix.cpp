class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
    string str1 = strs[0];
    string temp = "";
    string str2 = strs[strs.size() - 1];
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i])
        {
            break;
        }
        temp.push_back(str1[i]);
    }
        return temp;
    }
};
