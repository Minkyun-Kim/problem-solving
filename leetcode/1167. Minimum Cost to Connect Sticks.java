/**
 * 해당 문제의 키 포인트는 가장 짧은 막대끼리 더해야 cost가 가장 작다는 것이다.
 *그러므로 여러 길이의 막대가 있을때 항상 가장 짧은 길이의 막대 두 개를 골라야하고 이런 경우 우선순위 큐를 이용이 적합하다. 만일 일차원 배열에서 가장 작은 두 개의 막대를 고르려면 O(n)의 시간이 필요한데, 우선순위 큐의 경우 삽입과 삭제에 O(log n)의 시간이 걸리기 때문에 훨씬 빠르게 탐색할 수 있다.
 */
class Solution {
    int cost = 0;
    PriorityQueue<Integer> pq;
    public int connectSticks(int[] sticks) {
        pq = new PriorityQueue<>();
        for(int stick : sticks){
            pq.add(stick);
        }
        
        while(pq.size() > 1){
            Integer s1 = pq.poll();
            Integer s2 = pq.poll();
            cost += s1+s2;
            pq.add(s1+s2);
        }
        return cost;
        
    }
}
