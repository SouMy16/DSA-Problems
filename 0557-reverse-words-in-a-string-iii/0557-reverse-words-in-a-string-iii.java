class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder("");
        StringBuilder cur = new StringBuilder("");
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == ' ') {
                cur.reverse();
                ans.append(cur);
                ans.append(' ');
                cur = new StringBuilder("");
            }
            else cur.append(s.charAt(i));
        }
        ans.append(cur.reverse());
        return ans.toString();
    }
}