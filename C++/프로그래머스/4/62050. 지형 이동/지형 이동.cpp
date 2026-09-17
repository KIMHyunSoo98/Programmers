#include <bits/stdc++.h>

using namespace std;

void get_group(vector<vector<int>>& land, vector<vector<int>>& group, int sy, int sx, int w, int h, int g_num){
    
    priority_queue<array<int, 3>> queue;
    queue.push({land[sy][sx], sy, sx});
    vector<array<int, 2>> delta = {{0,1}, {0,-1},{1,0},{-1,0}};
    
    while (!queue.empty()){
        auto [cur_h, cur_y, cur_x] = queue.top();
        queue.pop();
        
        for (auto [dy, dx]: delta){
            int ny = cur_y+dy, nx = cur_x+dx;
            
            if ((0 <= ny) && (ny < w) && (0 <= nx) && (nx < w)){
                int diff = abs(land[ny][nx] - cur_h);
                if ((diff <= h) && (group[ny][nx] == 0)){
                    group[ny][nx] = g_num;
                    queue.push({land[ny][nx], ny, nx});
                }
            }
        }
    }
}

int find(vector<int>& parents, int u){
    
    if (parents[u] != u)
        parents[u] = find(parents, parents[u]);
    
    return parents[u];    
}

int union_find(vector<int>& parents, int u, int v){
    
    int pu = find(parents, u), pv = find(parents, v);
    
    if (pu == pv) return true;
    
    if (pu > pv)
        parents[pu] = pv;
    else
        parents[pv] = pu;
    
    return false;
}


int solution(vector<vector<int>> land, int height) {
    int ans = 0, g_num = 1, w = land.size();
    vector<vector<int>> group(w, vector<int>(w));
    
    for (int y=0; y < w; y++){
        for (int x=0; x < w; x++){
            if (group[y][x] == 0){
                group[y][x] = g_num;
                get_group(land, group, y, x, w, height, g_num);
                g_num++;
            }
        }
    }
    // cout << "g_num: " << g_num << "\n";
    // for (int y=0; y < w; y++){
    //     for (int x=0; x < w; x++){
    //         cout << group[y][x] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> heap;
    vector<vector<int>> visited(w, vector<int>(w));
    vector<array<int,2>> delta={{0,1},{0,-1},{1,0},{-1,0}};
    
    for (int y=0; y < w; y++){
        for (int x=0; x < w; x++){                
            for (auto [dy, dx]: delta){
                int ny=y+dy, nx=x+dx;

                if ((0 <= ny) && (ny < w) && (0 <= nx) && (nx < w) && (group[y][x] != group[ny][nx])){
                    visited[ny][nx] = 1;
                    heap.push({abs(land[y][x]-land[ny][nx]), group[y][x], group[ny][nx]});
                }
            }
            
        }
    }
    
    // while (!heap.empty()){
    //     auto [diff, g1, g2] = heap.top();
    //     heap.pop();
    //     cout << diff << " " << g1 << " " << g2 << "\n";
    // }
    
    int num = 1;
    vector<int> parents(g_num);
    
    for (int i=0; i < parents.size(); i++)
        parents[i] = i;
    
    while (!heap.empty()){
        auto [diff, g1, g2] = heap.top();
        heap.pop();
        
        if (union_find(parents, g1, g2)) continue;
        
        ans += diff;
        
        num++;
        if (num == g_num-1){
            break;
        }
    }
    
    
    return ans;
}