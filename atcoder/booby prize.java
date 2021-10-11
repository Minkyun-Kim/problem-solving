import java.util.Scanner;
import java.lang.System;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int firstScore = Integer.MIN_VALUE;
        int secondScore = Integer.MIN_VALUE;
        int firstIndex = 0, secondIndex=0;

        int n = scanner.nextInt();
        for(int i = 1; i <= n; i++){
            int score = scanner.nextInt();
            if(score > firstScore){
                secondScore = firstScore;
                secondIndex = firstIndex;
                firstScore = score;
                firstIndex = i;
            }
            else {
                if(score > secondScore){
                    secondScore = score;
                    secondIndex = i;
                }
            }
        }
        System.out.println(secondIndex);
    }
}
