class Solution {
    void solve(String digits,String [] map,int index,List<String> ans,StringBuilder  output){
        if(index>= digits.length()){
            ans.add(output.toString());
            return ;
        }
        int number= digits.charAt(index)-'0';
        String value=map[number];
        for(int i=0;i<value.length();i++){
            output.append(value.charAt(i));
            solve(digits,map,index+1,ans,output);
            output.deleteCharAt(output.length() - 1);
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> ans=new ArrayList<>();
        if(digits.length()==0) return ans;
        StringBuilder output = new StringBuilder();
        int index=0;
        String [] map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,map,index,ans,output);
        return ans;

    }
}