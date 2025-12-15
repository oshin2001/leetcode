class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string>st;
        int maxi = INT_MIN;
        for(int i = 0;i<wordDict.size();i++){
           string p = wordDict[i];
           if(maxi < p.size()) maxi = p.size();
           st.insert(p);
        }

        vector<int> dp(n+1,false);
        dp[0] = true;

        for(int i = 0;i<n;i++){
             for(int j = 0;j<=i ;j++){
                if(st.find(s.substr(j,i-j+1)) != st.end()){
                    if(dp[j]==true){
                    cout<<s.substr(j,i-j+1)<<endl;
                    dp[i+1] = true;
                    break ;
                    }
                }
             }
        }
        return dp[n];

    }
};