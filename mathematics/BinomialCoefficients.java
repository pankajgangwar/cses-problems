import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.*;
import java.util.StringTokenizer;

/*
https://cses.fi/problemset/task/1081/
*/

public class BinomialCoefficients {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        long q = fs.nextLong();
        calculateInverse();
        calculateFactorialInv();
        factorial();
        while (q-- > 0) {
            int n = fs.nextInt();
            int k = fs.nextInt();
            long ans = binomialCoefficients(n, k);
            out.println(ans);
        }
        out.flush();
        out.close();
    }
    static int max = (int)1e6;
    static int mod = (int) 1e9 + 7;
    public static long binomialCoefficients(int n, int k) {
        long ans = ((fact[n] * inverseOfFact[k]) % mod * inverseOfFact[n - k]) % mod;
        return ans;
    }

    static long[] inverseOfNumber = new long[max + 1];
    public static void calculateInverse() {
        inverseOfNumber[0] = inverseOfNumber[1] = 1;
        for (int i = 2; i <= max; i++) {
            inverseOfNumber[i] = inverseOfNumber[mod % i] * (mod - mod / i);
        }
    }
    static long[] inverseOfFact = new long[max + 1];
    public static void calculateFactorialInv() {
        inverseOfFact[0] = inverseOfFact[1] = 1;
        for (int i = 2; i <= max; i++) {
            inverseOfFact[i] = (inverseOfNumber[i] * inverseOfFact[i - 1]) % mod;
        }
    }
    static long[] fact = new long[max + 1];
    public static void factorial() {
        fact[0] = 1; fact[1] = 1;
        // n! = n * (n - 1)!
        for (int i = 2; i <= max; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        public String next() {
            while (!st.hasMoreElements())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}