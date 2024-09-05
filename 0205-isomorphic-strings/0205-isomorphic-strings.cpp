class Solution {
public:
    bool isIsomorphic(string s, string t) {
      
        vector<pair<char,char>> arr;
        for(int i=0;i<s.length();i++){
            arr.push_back({s[i],t[i]});
        }
        for (const auto& p : arr) {
            for (const auto& q : arr){
                if(p.first==q.first) {
                    if(p.second!=q.second){
                        return false;
                    }
                    else{
                        continue;
                    }
                }
                else if(p.first!=q.first){
                    if(p.second==q.second){
                        return false;
                    }
                    else{
                        continue;
                    }
                }
                
            }
                
            }
            
    
        return true;

        
        
    }
};