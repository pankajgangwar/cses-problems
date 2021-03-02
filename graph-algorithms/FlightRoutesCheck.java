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

//Problem : https://cses.fi/problemset/task/1682/
//Sol: https://cses.fi/problemset/result/1776421

/*
Strongly connected graph
*/
public class FlightRoutesCheck {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        HashMap<Integer, List<Integer>> graph = new HashMap<>();
        HashMap<Integer, List<Integer>> invertGraph = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            int a = fs.nextInt();
            int b = fs.nextInt();
            graph.putIfAbsent(a, new ArrayList<>());
            invertGraph.putIfAbsent(b, new ArrayList<>());

            graph.get(a).add(b);
            invertGraph.get(b).add(a);
        }
        boolean[] visited = new boolean[n + 1];
        boolean[] invertVisited = new boolean[n + 1];

        dfs(graph, visited, 1);
        boolean f = true;
        for (int u = 1; u <= n; u++) {
            if (!visited[u]) {
                out.println("NO");
                out.println("1 " + u);
                out.flush();
                out.close();
                return;
            }
        }

        dfs(invertGraph, invertVisited, 1);
        for (int u = 1; u <= n; u++) {
            if (!invertVisited[u]) {
                out.println("NO");
                out.println(u + " 1");
                out.flush();
                out.close();
                return;
            }
        }
        out.println("YES");
        out.flush();
        out.close();
    }


    private static void dfs(HashMap <Integer, List<Integer>> graph, boolean[] visited, int u) {
        if (visited[u]) return;
        visited[u] = true;
        if (!graph.containsKey(u)) return;
        for (int v : graph.get(u)) {
            dfs(graph, visited, v);
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