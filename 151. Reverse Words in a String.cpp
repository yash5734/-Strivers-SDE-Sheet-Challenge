class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        int i = n-1;

        while(i>=0){ // iterate the loop from last to end
            if(s[i]==' ') // if there is a space in the string s then skip it
            i--;
            else{         // if it is not space 
                string temp = " ";  // we create a temp string in this we store the each character from last to untill space is not found.
                int j = i;          // loop from i to j so that whole one word can iterate if we found space then termiante loop
                while(j>=0 && s[j]!=' '){
                    temp += s[j];
                    j--;
                }
                reverse(temp.begin(),temp.end());  // reverse the array since we store the element in reverse order.
                ans+=temp; // add the temp string which contain one word into the ans ie main string
                i = j;    
            } 
        }
        ans.pop_back();  // remove the extra space bcz temp string contain one space
        return ans;
    }
};
