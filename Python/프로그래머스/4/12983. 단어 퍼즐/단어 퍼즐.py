def solution(strs, t):
    ans = 0
    dp = [float('inf')] * (len(t))
    set_strs = set(strs)
    dp[0] = 0
    
    for i in range(len(t)):
        for k in range(5):
            s_i = i-k
            if (s_i < 0):                
                break
            print(dp)
            
            if (t[s_i:i+1] in strs):
                if (s_i == 0):
                    dp[i] = min(dp[i], 1)
                else:
                    dp[i] = min(dp[i], dp[s_i]+1)
            
    print(dp)

    return ans