INF = float('inf')

def solution(strs, t):
    ans = 0
    dp = [INF] * (len(t)+1)
    set_strs = set(strs)
    dp[0] = 0
    
    for i in range(1, len(t)+1):
        for k in range(5):
            s_i = i-1 - k
            if (s_i < 0):                
                break
            
            if (t[s_i:i] in strs):
                if (s_i == 0):
                    dp[i] = min(dp[i], 1)
                else:
                    dp[i] = min(dp[i], dp[s_i]+1)
            
    if (dp[-1] == INF):
        return -1

    return dp[-1]