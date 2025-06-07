class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=nums[i]){
                stk.pop();
            }    
            stk.push(nums[i]);

        }
        for(int i=n-1;i>=0;i--){
                while(!stk.empty() && stk.top()<=nums[i]){
                    stk.pop();
                }
                if(stk.empty()) ans.push_back(-1);
                else ans.push_back(stk.top());
                stk.push(nums[i]);            
        }
        reverse(ans.begin(),ans.end());
        
        return ans;

    }
};