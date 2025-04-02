class Solution {
    boolean isPallindrome(String s, int i,int j){
        int x=i;
        int y=j;
        while(x<y){
            if(s.charAt(x)!=s.charAt(y)){
                
                return false;    
            }
            x++;
            y--;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        String res="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPallindrome(s,i,j)){
                    String currentSubstring= s.substring(i,j+1);
                    if(res.length()<currentSubstring.length()){
                        res=currentSubstring;
                    }
                }
            }
        }
        return res;
    }
}