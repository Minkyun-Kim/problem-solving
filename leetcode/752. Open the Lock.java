/**
 *0000에서 시작해 각 자리의 숫자를 +1, -1씩 돌려 자물쇠 비밀번호를 맞추는데 필요한 움직임 수를 구하는 방법. 0000부터 9999까지를 모두 노드라고 생각한다. 0000->0001, 0000->0009, 0000->0010 등 각 자리를 한번씩 움직여 나오는 수는 모두 0000에서 길이가 1인 노드로 본다. 여기에 BFS를 이용하면 일정한 거리를 탐색하며 최소로 움직여 target값을 얻을 수 있다.
 */
class Solution {
    public int openLock(String[] deadends, String target) {
        //BFS로 탐색중에 나온 값이 deadends의 값 중 하나인지 O(1)로 비교하려고 Set을 사용
        Set<String> deads = new HashSet<>();
        for(String deadend : deadends){
            deads.add(deadend);
        }
        
        Queue<String> queue = new LinkedList();
        queue.offer("0000");
        queue.offer(null);
        
        //이미 탐색한 숫자는 다시 탐색하지 않는다. 0000->0001->0000->0001 무한 반복될 수 있다.
        Set<String> seen = new HashSet<>();
        seen.add("0000");
        
        int depth = 0;//최소 이동 거리
        while(!queue.isEmpty()){
            String node = queue.poll();
            if(node == null){
                //동일한 depth에 있는 값들을 다 탐색했을 경우
                depth++;
                if(queue.peek()!=null){
                    queue.offer(null);
                }
            }
            else if(node.equals(target)){
                //특정 값이 목표값인 경우
                return depth;
            }
            else if(!deads.contains(node)){
                //deanends에 포함되지 않는 경우. 포함되면 지나갈수 없으므로 더이상 search하지 못하게 무시한다.
                for(int i = 0; i < 4; i++){
                    //네자리 숫자에 대해서 각각 돌려줘야함.
                    for(int d = -1; d <= 1; d += 2){
                        int y = ((node.charAt(i)-'0') + d + 10)%10; //각 자리마다 숫자를 -1, +1만큼 돌려줌. 0에서 9로 가려면 0 -1 + 10을 해야함.
                        String nei = node.substring(0, i) + (""+y) + node.substring(i+1);
                        //직전 또는 이전에 사용했던 숫자는 제외해야한다. 계속 0000->0001->0000->0001 처럼 맴돌수 있다.
                        if(!seen.contains(nei)){
                            seen.add(nei);
                            queue.offer(nei);
                        }
                    }
                }
            }
        }
        return -1;
    }
}
