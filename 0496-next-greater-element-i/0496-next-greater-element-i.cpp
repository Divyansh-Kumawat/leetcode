class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge;
        stack<int> stk;
        int n2=nums2.size();
        int n1=nums1.size();
        unordered_map<int,int> mpp;
        
        for(int i=n2-1;i>=0;i--){
            while(!stk.empty() && nums2[i]>stk.top()){
                stk.pop();
            }
            if(stk.empty()) mpp[nums2[i]]=-1;
            else mpp[nums2[i]]=stk.top();
            stk.push(nums2[i]);
        }
        
        
        for(int i=0;i<n1;i++){
            nge.push_back(mpp[nums1[i]]);
        }
        return nge;
    }
};
  