class Solution {
public:
    void paranthesis(int n,int o,int c,string str,vector<string> & ans){
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(o<n){
            paranthesis(n,o+1,c,str+'(',ans);
        }
        if(c<o){
            paranthesis(n,o,c+1,str+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        paranthesis(n,0,0,"",ans);
        return ans;
    }
};