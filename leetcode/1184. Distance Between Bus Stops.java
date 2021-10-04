/**
 * distance 배열을 이용해 distance[start] ~ distance[destination] 사이의 모든 값을 더해주면 되는 문제이다.
 * 단 거리는 시계방향과 시계 반대방향으로 잴 수 있기 때문에, 반대 방향 거리 합인
 * distance[start-1] +...  +distance[0] + distance[n-1] + ... + distance[destination+1] 값이 더 클 수도 있다.
 * 이 값은 전체 거리에서 두 정류장 사이 값을 빼주면 된다.
 *
 * 매번 distance[start] ~ distance[destination] 값을 더해서 구하면 O(n)의 시간이 걸린다.
 * 만약 distnace 배열이 바뀌지 않아 누적합을 구해놓고 사용할 수 있다면 O(1)로 단축할 수 있다.
 */
class Solution{

    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int[] accumulatedDistance = new int[10000];
        // start가 dest보다 크면 swap시켜주면 마지막 return문의 min 함수 호출을 줄일 수 있다.
        accumulatedDistance[0] = 0;
        int length = distance.length;
        for(int i = 1; i < length; i++){
            accumulatedDistance[i%length] = distance[i-1] + accumulatedDistance[i-1];
        }
        accumulatedDistance[0] = accumulatedDistance[length-1] + distance[length-1];

        int tempDistance = Math.abs(accumulatedDistance[destination] - accumulatedDistance[start]);

        return Math.min(tempDistance, accumulatedDistance[0] - tempDistance);
    }
}