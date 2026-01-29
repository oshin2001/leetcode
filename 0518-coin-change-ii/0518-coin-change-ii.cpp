class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int LIMIT = INT_MAX;
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
                if (dp[i] > LIMIT) dp[i] = LIMIT;
            }
        }
        return (int)dp[amount];
    }
};