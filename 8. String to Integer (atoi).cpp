class Solution {
public:
  int myAtoi(string s) {
		int i =0;
		while(i<s.length() && s[i] == ' '){ // to remove the spaces in the begning eg "  46547" = "46547";
			i++;
		}
		s = s.substr(i); // i-->n remove all spaces

		int sign = +1;
		double ans =0;
		if(s[0] == '-' ) sign = -1; // if "-12321" sign will be -1 bcz we multiply with the ans. last

		int max = INT_MAX , min = INT_MIN;
		i = (s[0]== '+' || s[0] == '-')? 1:0; // if the input consist -,+ then we will start the iterate by 1 to skip +,-

		while(i<s.length()){
			if(s[i] == ' '|| !isdigit(s[i])) break; // if in middle if there is space and alpha then break it.

			ans = ans*10 + s[i]-'0'; // convert eact char to int 

			if(sign == -1 && -1*ans<INT_MIN) return min; // check for range that if ans is leser then INT_MIN then return min
			if(sign == +1 && ans>INT_MAX) return max; // bcz in question given that if range is below then 2^32
			i++;
		}

		return (int)(sign * ans); // multuply with sign at the end

  }
};
