class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int dice, int target, int k, vector<vector<int>> &dp) {

        if(dice == 0) {
            return target == 0;
        }

        if(target < 0) return 0;

        if(dp[dice][target] != -1)
            return dp[dice][target];

        long long ways = 0;

        for(int i = 1; i <= k; i++) {
            ways = (ways + solve(dice - 1, target - i, k, dp)) % MOD;
        }

        return dp[dice][target] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(n, target, k, dp);
    }
};