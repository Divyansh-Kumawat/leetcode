class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l=0;
        int r=0;
        int len=0;
        int n=s.length();
        HashSet<Character> hash = new HashSet<>();
        while(r<n){
            while(hash.contains(s.charAt(r))!=false){
                hash.remove(s.charAt(l));
                l++;
            }
            hash.add(s.charAt(r));
            len=Math.max(len,r-l+1);
            r++;
        }
        return (len==Integer.MIN_VALUE)?0:len;

    }
     

}