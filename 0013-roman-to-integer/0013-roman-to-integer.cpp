class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
       
        unordered_map<char,int> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
         int sum=0;
        for(int i=0;i<n-1;i++){
            if(roman[s[i]]<roman[s[i+1]]){
                sum-=roman[s[i]];
            }
            else{
                sum+=roman[s[i]];
            }

        }
        sum+=roman[s[n-1]];
        return sum;
    }
};