class Solution {
public:
    void func(int n,int o,int c,vector<string> &ans,string str){
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(o<n){
            func(n,o+1,c,ans,str+'(');

        }
        if(c<o){
            func(n,o,c+1,ans,str+')');

        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        string str="";
        int o=0;
        int c=0;
        func(n,o,c,ans,str);
        return ans;
    }
};