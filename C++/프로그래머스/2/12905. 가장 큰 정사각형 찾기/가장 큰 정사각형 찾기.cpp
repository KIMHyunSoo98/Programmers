#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board)
{
    int ans = board[0][0];
    int h=board.size(), w=board[0].size();
    vector<vector<int>> dp;
    dp = board;
    
    for (int y=1; y < h; y++){
        for (int x=1; x < w; x++){
            if (board[y][x] == 0) continue;
            
            dp[y][x] = min({dp[y-1][x-1], dp[y-1][x], dp[y][x-1]}) + 1;
        }
    }
    
    // for (auto& r: dp){
    //     for (auto& c : r)
    //         cout << c << " ";
    //     cout << endl;
    // }
    
    for (auto& row: dp){
        ans = max(ans, *max_element(row.begin(), row.end()));
    }
    
    return ans * ans;
}