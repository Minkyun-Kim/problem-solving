/*
DP. costs[i]번쨰 집의 빨간색([0])을 고른다면 그 이전엔 파랑색과 초록색 집 중에 저렴한 집을 고를 수 있다. 이때 저렴한 어느 집을 골라도 상관 없는 이유는 i번째 집이 빨간색이므로 어떤 색을 고르든 겹치지 않기 때문이다.
*/
class Solution {
    public int minCost(int[][] costs) {
        int n = costs.length;
        for(int i = n-1; i > 0; i--){
            costs[i-1][0] = costs[i-1][0] + Math.min(costs[i][1], costs[i][2]);
            costs[i-1][1] = costs[i-1][1] + Math.min(costs[i][0], costs[i][2]);
            costs[i-1][2] = costs[i-1][2] + Math.min(costs[i][0], costs[i][1]);
        }
        return Math.min(Math.min(costs[0][0], costs[0][1]), costs[0][2]);
    }
}
