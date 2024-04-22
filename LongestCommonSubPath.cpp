#define MODD 10000000000037ll
#define ll long long
class Solution {
public:

    ll PW[111111];

    bool Check(const vector<vector<int>>& paths, int n, int L) {
        for (int i = 0; i < paths.size(); i++) {
            if (paths[i].size() < L) return false;
        }

        unordered_map<ll, int> counts;
        for (int i = 0; i < paths.size(); i++) {
            unordered_set<ll> curr_hashes;
            ll H = 0;
            for (int j = 0; j <= L - 1; j++) {
                H += paths[i][j] * PW[L - 1 - j] % MODD;
                H %= MODD;
            }

            curr_hashes.insert(H);
            for (int j = L; j < paths[i].size(); j++) {
                H -= paths[i][j - L] * PW[L - 1] % MODD;
                H = (H * n + paths[i][j]) % MODD;
                H %= MODD;
                if (H < 0) H += MODD;
                curr_hashes.insert(H);
            }

            for (ll h : curr_hashes) {
                counts[h]++;
            }
        }
        for (auto c : counts) {
            if (c.second == paths.size()) return true;
        }
        return false;
    }


    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int min_len = paths[0].size();
        for (const auto& p : paths) {
            min_len = min(min_len, (int)p.size());
        }
        PW[0] = 1;
        for (int i = 1; i <= min_len + 1; i++) {
            PW[i] = (PW[i - 1] * n) % MODD;
        }
        int low = 0;
        int high = min_len;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (Check(paths, n, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};