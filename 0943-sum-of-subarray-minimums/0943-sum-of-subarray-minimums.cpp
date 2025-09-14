class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        stack<int> stk;
        vector<int> ple(n), nle(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            if(stk.empty()) ple[i]=-1;
            else ple[i]=stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(stk.empty()) nle[i]=n;
            else nle[i]=stk.top();
            stk.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            total = (total + (arr[i] * left % mod) * right % mod) % mod;
        }

        
        return (int)total;
    }
};