import java.util.Scanner;
import java.lang.System

class Main {

    public static void main(String[] var0) {
        Scanner scanner = new Scanner(System.in);
        Integer s = scanner.nextInt();
        Integer t = scanner.nextInt();
        int ans = 0;

        for(int a = 0; a <= s; ++a) {
            for(int b = 0; a + b <= s; ++b) {
                for(int c = 0; a + b + c <= s; ++c) {
                    if (a * b * c <= t) {
                        ++ans;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
