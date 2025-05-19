class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first= strs[0];
        string second= strs[strs.size()-1];
        string finalstr="";
        int i=0;
        if(strs.size()==1) return strs[0];
        if(strs[0]=="") return "";
         while (i < first.size() && i < second.size() && first[i] == second[i]) {
            finalstr += first[i];
            i++;
        }
        return finalstr;
    }
};