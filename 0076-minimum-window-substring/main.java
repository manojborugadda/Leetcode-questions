class Solution {//TC:O(S length + T.length)  SC:O(S.length)
    public String minWindow(String s, String t) {
        String result = "";
        if(t.length() > s.length()) return result;
        int[] tCount = new int[128];

        for(char c : t.toCharArray()) {
            tCount[c]++;
        }

        char[] sChars = s.toCharArray();
        int left = 0 , right = 0 , minWinLen = Integer.MAX_VALUE;
        int found = 0 , toFind = t.length();

        while(right < s.length()) {
            char ch = sChars[right];
            tCount[ch]--;
            if(tCount[ch] >= 0) {
                found++;
            }
            while(found == toFind) {
                if(minWinLen > (right - left + 1)) {
                    minWinLen = right - left + 1;
                    result  = s.substring(left,right + 1);
                }

                tCount[sChars[left]]++;
                if(tCount[sChars[left]] > 0) {
                    found--;
                }
                left++;
            }
            right++;
        }
        return result;
    }
}
