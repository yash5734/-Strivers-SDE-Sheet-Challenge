class Solution {
public:
    int romanToInt(string s) {
        int n =s.length();
        map<char,int>mp; // create a map to store the roman with int
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int result =0; // this is ans which we can return
        result += mp[s[n-1]]; // store the last value in the result
        for(int i=n-2;i>=0;i--){ // iterrate n-2 to 0 since we have already store the last in result
            if(mp[s[i]] < mp[s[i+1]]){ // check it the eg. 4th index is smaller then the 5th index then we subtract IV
                result-=mp[s[i]]; // in I is in 4th index and V is in 5th index so we check that if the present elemt 
            }else result +=mp[s[i]]; // is smaller then the next element if it is then we simply subtract else add
        }
        return result;
    }
};
