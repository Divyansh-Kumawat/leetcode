class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first= strs[0];
        string second= strs[strs.size()-1];
        string finalstr="";
        bool x= true;
        for(int i=0;i<first.length();i++){
            if(first[i]==second[i]){
                finalstr+=first[i];
            }
            else{
                break;
            }
        }
        return finalstr;
        

    
    }
};