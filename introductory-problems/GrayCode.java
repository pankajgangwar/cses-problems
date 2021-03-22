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
https://cses.fi/problemset/task/2205/
https://cses.fi/problemset/result/1865281/

https://cp-algorithms.com/algebra/gray-code.html

Take previous code in sequence 0 and 1
Add reversed code in list: 0 1 1 0
Now Add prefix 0 for org previous code and prefix 1 for new generated code: 00, 01, 11, and 10

*/

public class GrayCode {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        for (int i = 0; i < 1 << n; i++) {
            int code = i ^ (i >> 1);
            String res = Integer.toBinaryString(code);
            int len = res.length();
            StringBuilder builder = new StringBuilder();
            if (len < n) {
                String copies = String.join("", Collections.nCopies(n - len, "0"));
                builder.append(copies);
            }
            builder.append(res);
            out.println(builder);
        }
        out.flush();
        out.close();
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