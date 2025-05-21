class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        map<char, int> myMap;
        for(char ch: s){
            if((myMap.find(ch)!=myMap.end())){
                myMap[ch]++;
            }
            else{
                myMap[ch]=1;
            }
        }
        vector<pair<char, int>> vec(myMap.begin(), myMap.end());
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;  // descending order
        });
        for (const auto &pair : vec) {
            for(int i=0;i<pair.second;i++){
                ans+=pair.first;
            }
            
        }
        return ans;
    }
};