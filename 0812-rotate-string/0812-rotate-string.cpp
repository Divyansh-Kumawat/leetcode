class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m) return false;
        if(s==goal) return true;
        queue<char> q1;
        queue<char> q2;
        for(int i=0;i<n;i++){
            q1.push(s[i]);
            q2.push(goal[i]);

        }
        for(int i=0;i<q1.size();i++){
            char c=q1.front();
            q1.pop();
            q1.push(c);
            if(q1==q2){
                return true;
            }
        }
        if(q1==q2) return true;
        return false;

    }
};