class Solution {
public:
    vector<int> find_nse(vector<int>& arr){
        vector<int> nse(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=(st.empty()?arr.size():st.top());
            st.push(i);
        }
        return nse;
    }
    vector<int> find_psee(vector<int>& arr){
        vector<int>psee(arr.size());
        stack<int> stk;
        for(int i=0;i<arr.size();i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            psee[i]=(stk.empty()?-1:stk.top());
            stk.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=find_nse(arr);
        vector<int> psee=find_psee(arr);
        int total=0; 
        int mod=(int)(1e9+7);
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+ (right* left*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};