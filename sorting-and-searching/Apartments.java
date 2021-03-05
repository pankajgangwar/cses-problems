import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

//Problem : https://cses.fi/problemset/task/1621/
//Sol: https://cses.fi/problemset/result/1778489

public class Apartments {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        int k = fs.nextInt();
        int[] desiredSize = new int[n];
        for (int i = 0; i < n; i++) {
            desiredSize[i] = fs.nextInt();
        }

        int[] apartmentSize = new int[m];
        for (int i = 0; i < m; i++) {
            apartmentSize[i] = fs.nextInt();
        }
        Arrays.parallelSort(desiredSize);
        Arrays.parallelSort(apartmentSize);

        int count = 0;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (Math.abs(desiredSize[i] - apartmentSize[j]) <= k) {
                ++i;
                ++j;
                ++count;
            } else {
                if (desiredSize[i] - apartmentSize[j] > k) {
                    ++j;
                } else {
                    ++i;
                }
            }
        }
        out.print(count);
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