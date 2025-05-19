class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int maxi=INT_MIN;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int x=num[i]-'0';
            if(x%2!=0){
                string ans="";
                for(int j=0;j<=i;j++){
                    ans+=num[j];

                }
                return ans;
            }

        }
        return "";
    }

};