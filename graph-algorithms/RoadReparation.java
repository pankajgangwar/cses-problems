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

//Problem : https://cses.fi/problemset/task/1675/
//Sol: https://cses.fi/problemset/result/
public class RoadReparation {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        HashMap<Integer, List<long[]>> graph = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            int src = fs.nextInt();
            int dest = fs.nextInt();
            long cost = fs.nextLong();
            graph.putIfAbsent(src, new ArrayList<>());
            graph.get(src).add(new long[] {dest, cost});

            graph.putIfAbsent(dest, new ArrayList<>());
            graph.get(dest).add(new long[] {src, cost});
        }
        //long ct = System.currentTimeMillis();
        long ans = solve(graph, n);
        if (ans != -1) {
            out.println(ans);
        } else {
            out.println("IMPOSSIBLE");
        }
        //System.err.println(System.currentTimeMillis() - ct + " ms");

        out.flush();
        out.close();
    }

    /*  Prims Algorithm to find min total cost to connect all the cities */
    private static long solve(HashMap<Integer, List<long[]>> graph, int n) {
        /* [cost, adj] */
        PriorityQueue<long[]> minHeap = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        int i = 1;
        boolean []visited = new boolean[n + 1];
        long res = 0;
        int connected = 0;
        while (++connected < n) {
            visited[i] = true;
            for (long[] adj : graph.get(i)) {
                long next = adj[0];
                long cost = adj[1];
                if (visited[(int)next]) continue;
                minHeap.offer(new long[] {cost, next});
            }
            while (!minHeap.isEmpty() && visited[(int)minHeap.peek()[1]]) {
                minHeap.poll();
            }
            if (minHeap.isEmpty()) return -1;
            long[] nextMin = minHeap.poll();
            res += nextMin[0];
            i = (int)nextMin[1];
        }
        return res;
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