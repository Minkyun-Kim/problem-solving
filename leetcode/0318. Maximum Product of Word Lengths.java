class Solution {
    int[] bitmasks;
    public int maxProduct(String[] words) {
        bitmasks = new int[words.length];
        fillBitmask(words);
        
        int max = 0;
        for(int i = 0; i < words.length;i++){
            for(int j = 0; j < words.length; j++){
                if((bitmasks[i] & bitmasks[j]) == 0)
                    max = Math.max(max, words[i].length() * words[j].length());
            }
        }
        return max;
    }
    
    public void fillBitmask(String[] words){
        for(int i = 0; i < words.length; i++){
            for(char ch : words[i].toCharArray()){
                bitmasks[i] |= (1 << ((int)ch-(int)'a'));
            }
        }
    }
}
