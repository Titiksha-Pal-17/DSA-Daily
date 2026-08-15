class Solution {
public:
    int f(string& x, string& y, int n, int m,
           vector<vector<int>>& dp) {

        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (x[n - 1] == y[m - 1]) {
            return dp[n][m] =
                1 + f(x, y, n - 1, m - 1, dp);
        }

        return dp[n][m] = max(
            f(x, y, n, m - 1, dp),
            f(x, y, n - 1, m, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1,vector<int>(m + 1, -1));

        // Fill DP
        f(str1, str2, n, m, dp);

        string ans;

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            // Same character
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            }

            // Move towards larger LCS
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }

            else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Remaining characters
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};