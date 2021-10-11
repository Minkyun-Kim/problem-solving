/**
 * DP문제. 메모이제이션을 이용한다. map[i][j]의 의미가 중요하다. map[i][j]는 s1의 i번째, s2의 j번째 substring을 이용하여 s3의 i+j-1번째 스트링까지 만들수 있는지, 없는지를 의미한다. map[i][j]가 true이면 map[i][j+1]은 s2[j+1]이 s3[i+j]와 같다면 역시 true로 보고 해당 인덱스까지는 s1와 s2의 조합으로 완성된다고 볼 수 있다.
 */
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        s1 = " " + s1;
        s2 = " " + s2;

        boolean[][] map = new boolean[s1.length()][s2.length()];
        map[0][0] = true;
        for(int i = 0; i < s1.length(); i++){
            for(int j = 0; j < s2.length(); j++){
                if(i-1>=0 && map[i-1][j] == true && s1.charAt(i) == s3.charAt(i+j-1))
                    map[i][j] = true;
                if(j-1>=0 && map[i][j-1] == true && s2.charAt(j) == s3.charAt(i+j-1))
                    map[i][j] = true;
            }
        }
        return map[s1.length()-1][s2.length()-1];
    }

}
