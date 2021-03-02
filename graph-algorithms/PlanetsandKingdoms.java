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

//Problem : https://cses.fi/problemset/task/1683/
//Sol: https://cses.fi/problemset/result/1777129

/*

Strongly Connected components can be thought of as self-contained cycles
within a directed graph where every vertex in a given cycle can reach every other
vertex in the same cycle
Low-Link values of a node is smallest[lowest] node id reachable from that node when
a DFS(including itself) is performed

*/

/*
Similar Problem :
https://leetcode.com/problems/critical-connections-in-a-network/

Tarjan's Algorithm(Single DFS) using existing Kosaraju's Algorithm
Strongly Connected Components

*/
public class PlanetsandKingdoms {
    //SOLUTION BEGIN
    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int m = fs.nextInt();
        HashMap<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            int a = fs.nextInt() - 1;
            int b = fs.nextInt() - 1;
            graph.putIfAbsent(a, new ArrayList<>());
            graph.get(a).add(b);
        }
        PlanetsandKingdoms current = new PlanetsandKingdoms();
        int[] low = current.solve(graph, n);
        Map<Integer, List<Integer>> multiMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            multiMap.putIfAbsent(low[i], new ArrayList<>());
            multiMap.get(low[i]).add(i);
        }
        int[] ans = new int[n];
        out.println(multiMap.size());
        int id = 1;
        for (List<Integer> scc : multiMap.values()) {
            for (int a : scc) {
                ans[a] = id;
            }
            id++;
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
        }
        out.flush();
        out.close();
    }

    private int[] ids, low;
    private Deque<Integer> stack;
    private boolean[] onStack;
    private int sscCount, id;
    public int[] solve(HashMap<Integer, List<Integer>> graph, int n) {
        ids = new int[n];
        low = new int[n];
        stack = new ArrayDeque<>();
        onStack = new boolean[n];
        Arrays.fill(ids, -1);
        for (int i = 0; i < n; i++) {
            if (ids[i] == -1) dfs(i, graph);
        }
        return low;
    }


    public void dfs(int nodeAt, HashMap<Integer, List<Integer>> graph ) {
        stack.push(nodeAt);
        onStack[nodeAt] = true;
        ids[nodeAt] = low[nodeAt] = id++;
        if (graph.containsKey(nodeAt)) {
            for (int nodeTo : graph.get(nodeAt)) {
                if (ids[nodeTo] == -1) {
                    dfs(nodeTo, graph);
                    low[nodeAt] = Math.min(low[nodeTo], low[nodeAt]);
                } else if (onStack[nodeTo]) {
                    low[nodeAt] = Math.min(ids[nodeTo], low[nodeAt]);
                }
            }
        }
        if (ids[nodeAt] == low[nodeAt]) { //id and low-link value is same, this node starts the scc
            while (!stack.isEmpty()) {
                int node = stack.pop();
                // Assign low-link values for the nodes on the stack i.e for this scc
                // with current low-link value.
                low[node] = low[nodeAt];
                onStack[node] = false;
                if (node == nodeAt) break;
            }
            sscCount++;
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