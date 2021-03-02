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

//Problem : https://cses.fi/problemset/task/1676/
//Sol: https://cses.fi/problemset/result/1775923

/*
    Similar Problem :
    https://leetcode.com/problems/largest-component-size-by-common-factor/
*/

public class RoadConstruction {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        UnionFind uf = new UnionFind(n);
        int connected = 0;
        for (int i = 1; i <= m; i++) {
            int a = fs.nextInt() - 1;
            int b = fs.nextInt() - 1;
            if (uf.find(a) != uf.find(b)) {
                connected++;
                uf.union(a, b);
            }
            out.print(n - connected);
            out.print(" ");
            out.println(uf.getMaxSize());
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

    static class UnionFind {
        private int count = 0;
        private int[] parent, rank;
        int max = 0;
        public UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        public int find(int p) {
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];    // path compression by halving
                p = parent[p];
            }
            return p;
        }
        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) return;
            parent[rootP] = rootQ;
            int count = rank[rootP] + rank[rootQ];
            rank[rootQ] = count;
            max = Math.max(max, count);
            /*if (rank[rootQ] > rank[rootP]) {
                parent[rootP] = rootQ; // p points to q
            } else {
                parent[rootQ] = rootP; // q points to p
                if (rank[rootP] == rank[rootQ]) {
                    rank[rootP]++;
                }
            }*/

            count--;
        }
        public int getMaxSize() {
            return max;
        }
        public int count() {
            return count;
        }
    }
}