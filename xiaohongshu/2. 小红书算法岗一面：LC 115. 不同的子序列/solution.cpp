class Solution {
    public:
        int numDistinct(string s, string t) {
            int n=s.size(), m=t.size();
            unsigned long long f[n+1][m+1]; // f[i][j] s[0...i] t[0..j] 的答案
            memset(f, 0L, sizeof f);

            if (n < m) return 0;
            if (s==t) return 1;
            if (n == m  && s != t) return 0;

            // f[i][j] if s[i] == t[j] f[i][j] += f[i-1][j-1]
            // f[i][j] f[i][j] += f[i-1][j]

            for (int i=0;i<=n;++i) f[i][0] = 1;
            for (int j=1;j<=m;++j) f[0][j] = 0;

            for (int i=1;i<=n;++i) {
                for (int j=1;j<=m;++j) {
                    if (s[i-1] == t[j-1]) f[i][j] += f[i-1][j-1];
                    f[i][j] += f[i-1][j];
                }
            }

            return f[n][m];
        }
};
