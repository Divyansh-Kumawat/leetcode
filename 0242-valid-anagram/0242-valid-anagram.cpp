class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==t){
            return true;
        }
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(), s.end());
          sort(t.begin(), t.end());

          // Case 2: check if every character of str1 and str2 matches with each other
          for (int i = 0; i < s.length(); i++)
          {
            if (s[i] != t[i])
              return false;
          }
          return true;
        
    }
};