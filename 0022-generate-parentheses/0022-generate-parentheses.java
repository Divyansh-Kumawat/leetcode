class Solution {
    void generate(List<String> ans,StringBuilder str,int open ,int close,int n){
        if(str.length()==2*n){
            ans.add(str.toString() );
            return;
        }
        if(open<n){
            generate(ans,str.append('('),open+1,close,n);
            str.deleteCharAt(str.length() - 1);

        }
        if(close<open){
            generate(ans,str.append(')'),open ,close+1,n);
            str.deleteCharAt(str.length() - 1);

        }
       
        

    }
    public List<String> generateParenthesis(int n) {
        List<String> ans= new ArrayList<>();
        StringBuilder str=new StringBuilder();
        int open=0;
        int close=0;
        generate(ans,str,open,close,n);
        return ans;

    }
}