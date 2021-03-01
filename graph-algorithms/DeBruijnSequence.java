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

//Problem : https://cses.fi/problemset/task/1692/
//https://leetcode.com/problems/cracking-the-safe/
//Sol: https://cses.fi/problemset/result/1770061

public class DeBruijnSequence {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        //long ct = System.currentTimeMillis();
        String ans = crackSafe(n, 2);
        //System.err.println(System.currentTimeMillis() - ct + " ms");
        out.println(ans);
        out.flush();
        out.close();
    }

    public static String crackSafe(int n, int k) {
        String strPwd = String.join("", Collections.nCopies(n, "0"));
        HashSet<String> visitedComb = new HashSet<>();
        StringBuilder sbPwd = new StringBuilder(strPwd);

        visitedComb.add(strPwd);

        int numberOfComb = (int)Math.pow(k, n);

        crackSafeAfter(sbPwd, visitedComb, numberOfComb, n, k );

        return sbPwd.toString();
    }

    public static boolean crackSafeAfter(StringBuilder pwd, Set<String> visitedComb, int numberOfComb, int n, int k) {
        if (visitedComb.size() == numberOfComb) {
            return true;
        }

        String lastDigits = pwd.substring(pwd.length() - n + 1);

        for (int ch = 0; ch < k; ch++ ) {
            String newComb = lastDigits + ch;
            if (!visitedComb.contains(newComb)) {
                visitedComb.add(newComb);
                pwd.append(ch);
                if (crackSafeAfter(pwd, visitedComb, numberOfComb, n, k)) {
                    return true;
                }
                pwd.deleteCharAt(pwd.length() - 1);
                visitedComb.remove(newComb);
            }
        }
        return false;
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