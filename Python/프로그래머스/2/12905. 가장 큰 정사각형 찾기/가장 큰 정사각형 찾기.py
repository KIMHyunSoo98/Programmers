

def solution(board):
    h = len(board)
    w = len(board[0])
    
    dp = [board[i][:] for i in range(h)]
        
    for y in range(1, h):
        for x in range(1, w):
            if board[y][x] == 0:
                continue
            
            dp[y][x] = min(dp[y-1][x-1], dp[y-1][x], dp[y][x-1]) + 1
    
    
    
    return max([max(dp[i]) for i in range(h)]) ** 2