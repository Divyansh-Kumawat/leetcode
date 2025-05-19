class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int maxi=INT_MIN;
        int ans=0;
        reverse(num.begin(),num.end());
        for(int i=0;i<n;i++){
            int x=num[i]-'0';
            if(x%2!=0){
                string ans=num.substr(i,n);
                reverse(ans.begin(),ans.end());
                return ans;
            }

        }
        return "";
    }

};