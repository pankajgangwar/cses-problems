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
 
// Problem : https://cses.fi/problemset/task/1095/
// Solution: https://cses.fi/problemset/result/1810991/

public class Exponentiation {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int t = fs.nextInt();
        while(t-- > 0){
            long a = fs.nextLong();
            long b = fs.nextLong();
            long res = iterative(a, b);
            res = res % mod;
            out.println(res);
        }
        out.flush();
        out.close();
    }
    static long mod = (long)1e9 + 7;
    public static long iterative(long x, long n){
        long res = 1L;
        while(n > 0){
            if(n % 2 != 0){
                res = (res * x) % mod;
            }

            x = (x * x) % mod;
            n = n / 2;
        }
        return res % mod;
    }
    public static long dfs(long x, long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n % 2 == 0 ){
            return (dfs(x, n / 2) % mod ) * (dfs(x, n / 2 ) % mod);
        }else{
            return x * (dfs(x, n - 1 ) % mod);
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