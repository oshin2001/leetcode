class Solution {
public:
const long long mod=1e9+7;
long long solve(int i,int a,int l,vector<vector<vector<long long>>> &dp)
{ if(l>=3 || a>=2) return 0;
  if(i==0) return 1;
  if(dp[i][a][l]!=-1) return dp[i][a][l];
    int tka=solve(i-1,a+1,0,dp)%mod;
    int tkl=solve(i-1,a,l+1,dp)%mod;
    int tkp=solve(i-1,a,0,dp)%mod;
    return dp[i][a][l]=(0LL+(tka+tkl)%mod+tkp)%mod;
}
    int checkRecord(int n) {
        vector<vector<vector<long long >>> dp(n+1,vector<vector<long long>>(3,(vector<long long>(4,-1))));
        return solve(n,0,0,dp);
    }
};