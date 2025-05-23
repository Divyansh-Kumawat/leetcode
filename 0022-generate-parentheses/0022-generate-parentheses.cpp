class Solution {
public:
    void generate(int n,vector<string> & ans,int o,int c,string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(o<n){
            generate(n,ans,o+1,c,s+'(');
        }
        if(c<o){
            generate(n,ans,o,c+1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        int o=0;int c=0;
        generate(n,ans,o,c,s);
        return ans;
    }
};