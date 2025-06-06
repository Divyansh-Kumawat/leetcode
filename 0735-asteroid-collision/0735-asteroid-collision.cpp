class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(!stk.empty() && asteroids[i]<0 && stk.top()>0){
                
                while(!stk.empty() && stk.top()>0 && abs(asteroids[i])>stk.top()){
                    stk.pop();
                }
                if(!stk.empty() && stk.top()>0  && abs(asteroids[i])==stk.top()){
                    stk.pop();
                    continue;
                }
                if(stk.empty() || stk.top()<0){
                    stk.push(asteroids[i]);
                    continue;
                } 
                continue;
            }
            stk.push(asteroids[i]);
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
return ans;
    }
};