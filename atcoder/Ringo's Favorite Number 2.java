import java.util.Scanner;
import java.lang.System;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long[] arr = new long[200]; /** TODO: Why long? */

        int n = scanner.nextInt();
        long ans = 0L;
        for(int i = 0; i < n; i++){
            int input = scanner.nextInt();
            ans += arr[input%200]++;
        }

        System.out.println(ans);
    }
}
