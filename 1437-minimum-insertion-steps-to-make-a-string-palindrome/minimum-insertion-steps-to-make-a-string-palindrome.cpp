class Solution {
public:
     int f(string& a, string& b, int n, int m,
          vector<vector<int>>& dp) {

        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (a[n-1] == b[m-1]) {
            return dp[n][m] =
                1 + f(a, b, n-1, m-1, dp);
        }

        return dp[n][m] = max(
            f(a, b, n-1, m, dp),
            f(a, b, n, m-1, dp)
        );
    }
    int minInsertions(string s) {
        string r = s;
        reverse(r.begin() , r.end()) ;
        int n =s.size();
        int m =r.size() ;
        
        vector<vector<int>> dp(
            n+1,
            vector<int>(m+1, -1)
        );

        int lps = f(s,r,n ,m , dp) ;
        //longest palindromic subsequence lps
        return n-lps ;
    }
};