def solution(answers):
    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    cnt = [0, 0, 0]
    
    for i in range(len(answers)):
        if p1[i%5] == answers[i]:
            cnt[0] += 1
        if p2[i%8] == answers[i]:
            cnt[1] += 1
        if p3[i%10] == answers[i]:
            cnt[2] += 1
        
    m_cnt = max(cnt)
    ans = []
    for i in range(3):
        if cnt[i] == m_cnt:
            ans.append(i+1)
    
    return ans