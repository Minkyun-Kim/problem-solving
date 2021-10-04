/**
 * 틀렸던 이유. 자료형 값의 범위가 계산 결과를 담지 못했기 때문이다.
 * 원래 가로, 세로의 자료형을 int로 잡았는데 h, w는 10^9라 담을 수 있지만 그 넓이는 10^18승으로 담지 못한다. 계산 결과를 담으려면 long 자료형이 필요하므로 long 형태의 자료형을 선언해야 한다.
 */
class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        
        long hor_diff = 0;
        int before = 0;
        for(int cut : horizontalCuts){
            hor_diff = Math.max(cut-before, hor_diff);
            before = cut;
        }
        hor_diff = Math.max(h-before, hor_diff);
        
        long ver_diff = 0;
        before = 0;
        for(int cut : verticalCuts){
            ver_diff = Math.max(cut-before, ver_diff);
            before = cut;
        }
        ver_diff = Math.max(w-before, ver_diff);
       
        return (int)((ver_diff * hor_diff)%(1e9+7));
    }
}
