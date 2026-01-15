class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        vector<int> pos[26];
        vector<vector<int>> pref(26, vector<int>(n,0));

        for(int i = 0; i < n; i++) {
            pref[s[i] - 'a'][i]++;
            for(int j=0;j < 26;j++) {
                if(i-1>=0)
                pref[j][i] += pref[j][i-1];
            }
        }

        for(int i =0;i<n;i++) {
            pos[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < n;i++) {
            int j = n - 1;

            while(j >= i) {
                int found = 1;
                for(int c = 0;c<26 && j>=i;c++) {

                    int fq = pref[c][j];
                    if(i - 1 >=0) {
                        fq -= pref[c][i-1];
                    }
                    if(fq>0 && fq < k) {
                        found = 0;
                        int ind = lower_bound(pos[c].begin(), pos[c].end(), i) - pos[c].begin();
                        j = min(j, pos[c][ind]-1);
                    }
                }
                if(found) {
                    ans = max(ans, j-i+1);
                    break;
                }
            }
        }

        return ans;
    }
};