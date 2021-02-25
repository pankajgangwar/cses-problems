import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

//Problem : https://cses.fi/problemset/task/1195/
//Sol: https://cses.fi/problemset/result/1748143
public class FlightRoutes {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        int k = fs.nextInt();
        HashMap<Integer, List<long[]>> graph = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            int src = fs.nextInt();
            int dest = fs.nextInt();
            int cost = fs.nextInt();
            graph.putIfAbsent(src, new ArrayList<>());
            graph.get(src).add(new long[] {dest, cost});
        }
        //long ct = System.currentTimeMillis();
        String ans = solve(graph, n, k);
        //System.err.println(System.currentTimeMillis() - ct + " ms");
        out.println(ans);
        out.flush();
        out.close();
    }

    /*  Dijikstra with dp*/
    private static String solve(HashMap<Integer, List<long[]>> graph, int n, int k) {
        int mod = (int) 1e9 + 7;
        long max = (long)1e18;
        long[]ans = new long[k];
        StringBuilder res = new StringBuilder();
        //[src, totalCost]
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[1]));
        pq.offer(new long[] {1L, 0L});
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            int src = (int)curr[0];
            long totalCost = curr[1];
            if (src == n && k > 0) {
                res.append(String.valueOf(totalCost)).append(" ");
                k--;
            } else if (k == 0) {
                return res.toString().trim();
            }
            for (long[] edge : graph.getOrDefault(src, new ArrayList<>())) {
                int dest = (int)edge[0];
                long cost = edge[1];
                pq.offer(new long[] {dest, cost + totalCost});
            }
        }
        return "";//This should never happen
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