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

// Problem : https://www.spoj.com/problems/DIVSUM/

/*
https://cses.fi/problemset/task/1082/
*/

public class SumofDivisors {
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
        HashMap<Long, Long> map = new HashMap<>();
        for (long i = 1, la = 0; i <= n; i = la + 1) {
            la = (long)(n / (n / i));
            map.putIfAbsent(i, la);
        }

        long res = 0;
        for (Map.Entry<Long, Long> entry : map.entrySet()) {
            long l = entry.getKey();
            long r = entry.getValue();
            long ap_sum = ap_summation(l, r);
            long q = (n / l);
            res = (res + q % mod * ap_sum % mod) % mod;
        }
        return res % mod;
    }

    /*
        20 : 2 , 2, 5
        10 : 2 , 5
    */
    public static long ap_summation(long l, long r) {
        long xx = r - l + 1;
        long yy = l + r;
        if (xx % 2 == 0) xx /= 2;
        else yy /= 2;
        xx %= mod;
        yy %= mod;
        return (xx % mod * yy % mod);
    }

    public static long solution(long n) {

        long i = 1, minVal = n;
        long ans = 0;
        while (i * i <= n) {
            long l = n / (i + 1);
            long r = n / i;
            if (l >= r) continue;
            ans = (ans + ((i % mod * ap_summation(l + 1, r) % mod) % mod)) % mod;
            minVal = l;
            ans = (ans % mod);
            i += 1;
        }
        for (int j = 1; j < (minVal + 1); j++) {
            ans = (ans + (j * (n / j))) % mod;
        }
        return ans % mod;
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