class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge;
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && nums[i]>= stk.top()){
                stk.pop();
            }
            
            stk.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && nums[i]>= stk.top()){
                stk.pop();
            }
            if(stk.empty()) nge.push_back(-1);
            else nge.push_back(stk.top());
            stk.push(nums[i]);
        }
        reverse(nge.begin(),nge.end());
        return nge;
        
        
    }
};