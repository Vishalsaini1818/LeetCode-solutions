class Solution {
    public int maxProduct(String[] words) {
        int[][] alph = new int[words.length][26];
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                alph[i][words[i].charAt(j) - 'a']++;
            }
        }
        int max = 0;
        for (int i = 0; i < alph.length - 1; i++) {
            int[] w1 = alph[i];
            for (int j = i + 1; j < alph.length; j++) {
                int[] w2 = alph[j];
                boolean noSameLetter = true;
                for (int k = 0; k < w1.length; k++) {
                    if (w1[k] > 0 && w2[k] > 0) {
                        noSameLetter = false;
                        break;
                    }
                }
                if (noSameLetter) {
                    int prod = words[i].length() * words[j].length();
                    if (max < prod) max = prod;
                }
            }
        }
        return max;
    }
}