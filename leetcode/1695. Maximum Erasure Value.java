/*
subarray중에서 중복된 값을 가지지 않고 가장 큰 subarray 요소들의 합은?

문제의 핵심은 두가지다. 첫번째 : subarray, 두번째: 중복된 값을 가지지 않는다.
첫번째 subarray에서 탐색을 하기 위해 포인터 begin, end를 사용하여 sliding window 기법을 사용한다.
두번째 중복된 값을 가지지 않으려면 Set 자료구조가 적합하다. 하지만 알고리즘의 성능을 높이기 위해서는 boolean[] 배열로 해당 값이 subarray에 포함되어 있으면 true,  포함되지 않으면 false로 나타낼 수 있다. 이번 문제에서 element 값이 10,000 이하로 주어져 제한된 갯수의 boolean[] 배열을 만들 수 있다. 
*/
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        //Set<Integer> set = new HashSet<>();
        boolean[] set = new boolean[10001];
        int begin = 0;
        int end = 0;
        int sum = 0;
        int max = 0;
        for(int i = 0; i < nums.length; i++){
                while(set[nums[i]]){
                    set[nums[begin]] = false;
                    sum-=nums[begin];
                    begin++;
                }
            set[nums[i]] = true;
            sum += nums[i];
            max  = Math.max(max, sum);
        }
        return max;
    }
}
