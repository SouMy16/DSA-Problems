class Solution {
    public boolean isSubsequence(String s, String t) {
        int ind=0;
        if(s.length() == 0 && t.length() == 0) return true;
        for(int i=0; i<t.length(); i++) {
            if(ind<s.length() && t.charAt(i) == s.charAt(ind)) ind++;
            if(ind == s.length()) return true;
        }
        return false;
    }
}