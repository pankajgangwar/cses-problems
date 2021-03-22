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
 
// Problem : https://cses.fi/problemset/task/1712/
// Solution: https://cses.fi/problemset/result/1811267/

/*
https://en.wikipedia.org/wiki/Fermat's_little_theorem
*/

public class ExponentiationII {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        long mod = (long)1e9 + 7;
        int t = fs.nextInt();
        while(t-- > 0){
            long a = fs.nextLong();
            long b = fs.nextLong();
            long c = fs.nextLong();
            long res = iterative(a, iterative(b, c, mod - 1), mod);
            res = res % mod;
            out.println(res);
        }
        out.flush();
        out.close();
    }
    
    public static long iterative(long x, long n, long mod){
        long res = 1L;
        x = x % mod;
        while(n > 0){
            if(n % 2 != 0){
                res = (res * x) % mod;
            }

            x = (x * x) % mod;
            n = n >> 1;
        }
        return res % mod;
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