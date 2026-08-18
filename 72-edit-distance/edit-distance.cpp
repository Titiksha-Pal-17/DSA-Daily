

class Solution {
public:
    int f(string& a, string& b, int n, int m,
          vector<vector<int>>& dp) {

        if (n == 0)
            return m;

        if (m == 0)
            return n;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (a[n-1] == b[m-1]) {
            return dp[n][m] =
                f(a, b, n-1, m-1, dp);
        }

        return dp[n][m] = 1 + min({
            f(a, b, n, m-1, dp),     // insert
            f(a, b, n-1, m, dp),     // delete
            f(a, b, n-1, m-1, dp)    // replace
        });
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n+1,
            vector<int>(m+1, -1)
        );

        return f(word1, word2, n, m, dp);
    }
};