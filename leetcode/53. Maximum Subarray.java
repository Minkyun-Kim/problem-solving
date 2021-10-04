/**
 * Kadane's Algorithm
 * DP를 이용하는 카데인 알고리즘이다.
 * 큰 문제를 작은 부분 문제로 나누어 푸는 DP의 특성을 이용한 알고리즘이다.
 *
 * 이전 인덱스가 가지고 있는 최대 부분합에 현재 인덱스 값을 더해 이어갈지, 아니면 자신의 값으로 초기화해 다시 시작할지 결정하면 된다.
 *
 * 최대 부분합을 이어간다는 것은 이전 인덱스의 최대 부분합 값에 현재 인덱스의 값을 더한 값이, 현재 인덱스 값보다 크다는 것을 의미한다. 이전인덱스의 부분 수열의 합이 현재 인덱스보다 작다면 현재 인덱스를 선택하면 된다.
 *
 * 여기서 드는 의문점은 현재 인덱스 값을 선택하기보다 이전 인덱스 값들의 합중에서 맨 앞의 인덱스 값들을 빼주면 조금 더 큰 부분 수열이 나올수 있지 않을까 하는 생각이다.
 * 하지만 이 추측이 불가능한 이유가 있다.
 * 맨 앞의 값이 포함된 이유는 해당 값을 포함함으로서 전체 합이 증가했기 때문이다.
 * max(a[0]+a[1], a[1])을 선택하는 과정에서 a[0]을 포함함으로서 전체 합이 a[1]보다 컸기 때문에 a[0]을 제외한다면 그 이후의 수열은 더 작은 값을 가질수 밖에 없기 때문이다.
 *
 */
class Solution {

    //sol 1
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum = Math.max(sum + nums[i], nums[i]);
            max = Math.max(max, sum);
        }
        return max;
    }

    //sol 2: 메모리 최적화. 임시 변수 삭제
    public int maxSubArray(int[] nums) {
        for(int i = 1; i < nums.length; i++){
            nums[i] = Math.max(nums[i-1] + nums[i], nums[i]);
        }
        return Math.max(...nums);
    }
}
