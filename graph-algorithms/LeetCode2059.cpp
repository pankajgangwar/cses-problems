class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> bfs;
        bfs.push(start);

        int minOp = 0;
        unordered_set <int> visited;

        while (!bfs.empty()) {
            int size = bfs.size();
            while (size-- > 0) {
                int curr = bfs.front();
                bfs.pop();
                if (curr == goal) return minOp;
                if (curr < 0 || curr > 1000) continue;
                if (visited.find(curr) != visited.end()) {
                    continue;
                }
                visited.insert(curr);
                for (int i = 0; i < nums.size(); i++) {
                    bfs.push(curr + nums[i]);
                    bfs.push(curr - nums[i]);
                    bfs.push(curr ^ nums[i]);
                }
            }
            minOp += 1;
        }
        return -1;
    }
};