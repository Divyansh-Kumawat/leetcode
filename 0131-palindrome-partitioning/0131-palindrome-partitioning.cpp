class Solution {
public:
    bool palindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void func(string s,vector<vector<string>>& ans,int ind,vector<string> &path){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                func(s,ans,i+1,path);
                path.pop_back();
            }
        }
        

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(s,ans,0,path);
        return ans;
    }
};