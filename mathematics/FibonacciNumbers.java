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

public class FibonacciNumbers {
    //SOLUTION BEGIN
    static long mod = (long) 1e9 + 7;
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        long n = fs.nextLong();
        long res = solve(n);
        out.println(res);
        out.flush();
        out.close();
    }

    public static long solve(long n) {
        long mod = (long)1e9 + 7;
        long[] fib = new long[(int)n + 1];
        fib[0] = 0;
        fib[1] = 1l;
        if (n == 0 || n == 1) return n;
        for (int i = 2; i <= n; i++) {
            fib[i] = (fib[i - 2] % mod + fib[i - 1] % mod) % mod;
        }
        return fib[n] % mod;
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