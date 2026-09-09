#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
    
int solution(vector<string> strs, string t)
{
    int ans = 0;
    int len_t = t.size();
    unordered_set<string> strs_set;
    vector<int> dp(len_t+1, INF);
    dp[0] = 0;
    
    for (auto s: strs) strs_set.insert(s);
    
    
    for (int i=1; i < len_t+1; i++){
        
        for (int j=0; j < 5; j++){
            int s_idx = i-1 - j, len_w = j+1;
            if (s_idx < 0) continue;
            
            string sub = t.substr(s_idx, len_w);
            // cout << "sub: " << sub << endl;
            if (strs_set.count(sub)){
                if (s_idx == 0)
                    dp[i] = 1;
                else{
                    dp[i] = min(dp[i], dp[s_idx]+1);
                }
            }
        }
    }
    
    // for (auto n: dp)
    //     cout << n << " ";
    
    ans = dp.back();
    
    if (ans == INF) return -1;
    return ans;
}