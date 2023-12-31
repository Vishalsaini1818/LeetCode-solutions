class Solution {
    public boolean isSubsequence(String s, String t) {
        int sSz = s.length(), tSz = t.length();
        if(sSz > tSz) return false; 
        //a variable to point to curr character of sub seq 's'
        int sIndx = 0;
        //traverse over the given string
        for(int indx = 0; indx < tSz && sIndx < sSz; indx ++){
            if(t.charAt(indx) == s.charAt(sIndx)){
                sIndx++;
            }
        }
        return sIndx == sSz;
    }
}