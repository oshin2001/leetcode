class Solution {
public:
    int dp[10][1024][2][2][2];

    int helper(string s, int idx, int taken, bool tight, bool found, bool started) {
        if (idx == s.size()) return found;

        if (dp[idx][taken][tight][found][started] != -1)
            return dp[idx][taken][tight][found][started];

        int ans = 0;
        int end = tight ? s[idx] - '0' : 9;

        for (int i = 0; i <= end; i++) {
            int curr_started = started || i > 0;
            int curr_tight   = tight && i == end;
            int curr_taken   = curr_started ? (taken | (1 << i)) : taken;
            int curr_found   = started ? (found || ((taken >> i) & 1)) : found;

            ans += helper(s, idx + 1, curr_taken, curr_tight, curr_found, curr_started);
        }

        return dp[idx][taken][tight][found][started] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0, 1, 0, 0);
    }
};