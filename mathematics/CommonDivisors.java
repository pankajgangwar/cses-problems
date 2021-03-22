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

public class CommonDivisors {
    //SOLUTION BEGIN
    static long mod = (long) 1e9 + 7;
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextInt();
        }
        int res = solve(arr);
        out.println(res);
        out.flush();
        out.close();
    }

    public static int solve(int []arr) {
        int n = arr.length;
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, arr[i]);
        }
        int[] count = new int[max + 1];
        int res;
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        int counter = 0;
        // Start with max and find multiples of that number exists.
        // If there are more than 2 multiples then current gcd is max
        for (int i = max; i >= 1; i--) {
            int j = i;
            while (j <= max) {
                if (count[j] > 0) {
                    counter += count[j];
                }
                if (counter >= 2) {
                    return i;
                }
                j += i; // Multiples for i i.e i, 2i, 3i.. etc
            }
            counter = 0;
        }
        return 1;
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