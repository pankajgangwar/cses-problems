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

//Problem : https://cses.fi/problemset/task/1675/
//Sol: https://cses.fi/problemset/result/1775733
public class RoadReparationDS {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        List<long[]> edges = new ArrayList<>();
        for (int i = 1; i <= m; i++) {
            int src = fs.nextInt() - 1;
            int dest = fs.nextInt() - 1;
            long cost = fs.nextLong();
            edges.add(new long[] {cost, src, dest});
        }
        //long ct = System.currentTimeMillis();
        long ans = solve(edges, n);
        if (ans != -1) {
            out.println(ans);
        } else {
            out.println("IMPOSSIBLE");
        }
        //System.err.println(System.currentTimeMillis() - ct + " ms");

        out.flush();
        out.close();
    }

    /*  Kruskal's Algorithm with union-find to find min total cost to connect all the cities */
    private static long solve(List<long[]> edges, int n) {
        /* [cost, adj] */
        Collections.sort(edges, Comparator.comparingLong(a -> a[0]));
        long res = 0;
        int connected = 0;
        UnionFind uf = new UnionFind(n);
        for (long[] xx : edges) {
            if (uf.find((int)xx[1]) != uf.find((int)xx[2])) {
                uf.union((int)xx[1], (int)xx[2]);
                res += xx[0];
                connected++;
            }
        }

        return connected != (n - 1) ? -1 : res;
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
        public UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
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
            if (rank[rootQ] > rank[rootP]) {
                parent[rootP] = rootQ; // p points to q
            } else {
                parent[rootQ] = rootP; // q points to p
                if (rank[rootP] == rank[rootQ]) {
                    rank[rootP]++;
                }
            }
            count--;
        }
        public int count() {
            return count;
        }
    }
}