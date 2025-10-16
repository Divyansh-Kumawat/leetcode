class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int, int> freq;

        set<int> s;
        for(int i=0;i<n;i++){
            int rem=((nums[i]%value)+value)%value;
            freq[rem]++;
        }
        int mex = 0;
        while (true) {
            int rem = mex % value;
            if (freq[rem] == 0) break;  
            freq[rem]--;                 
            mex++;
        }
        return mex;
    }

};