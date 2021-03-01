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

//Problem : https://cses.fi/problemset/task/1689/
//https://leetcode.com/problems/cracking-the-safe/
//Sol: https://cses.fi/problemset/result/1773415

public class KnightsTour {
    //SOLUTION BEGIN

    public static void main(String[] args) throws Exception {
        PrintWriter out = new PrintWriter(System.out);
        FastScanner fs = new FastScanner();
        int curr_y = fs.nextInt() - 1;
        int curr_x = fs.nextInt() - 1;

        matrix = new int[N][N];

        for (int i = 0; i < N; i++) {
            Arrays.fill(matrix[i], -1);
        }
        //long ct = System.currentTimeMillis();
        solve(curr_x, curr_y, 0);
        //System.err.println(System.currentTimeMillis() - ct + " ms");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                out.print(matrix[i][j] + " ");
            }
            out.println();
        }
        out.flush();
        out.close();
    }

    static int[][] matrix;
    static int N = 8;
    static int[] di = new int[] { 2, 1, -1, -2, -2, -1, 1, 2 };
    static int[] dj = new int[] { 1, 2, 2, 1, -1, -2, -2, -1 };

    public static int deg(int[] a) {
        int d = 0;
        for (int i = 0; i < N; i++) {
            if (free(a[0] + di[i], a[1] + dj[i])) {
                d += 1;
            }
        }
        return d;
    }
    public static boolean solve(int x, int y, int moveCount) {
        matrix[x][y] = moveCount + 1;
        if (moveCount == ((N * N) - 1)) return true;
        List<int[]> p = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int nx = x + di[i];
            int ny = y + dj[i];
            if ( free(nx, ny) ) {
                p.add(new int[] {nx, ny});
            }
        }
        /* Sort the free locations based on adj free space for each move */
        Collections.sort(p, (a, b) -> deg(a) - deg(b));
        for (int[] xx : p) {
            if (solve(xx[0], xx[1], moveCount + 1)) {
                return true;
            }
        }
        matrix[x][y] = -1;
        return false;
    }


    public static boolean free(int nx, int ny) {
        if ( nx >= 0 && nx < N && ny >= 0 && ny < N && matrix[nx][ny] == -1 ) {
            return true;
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