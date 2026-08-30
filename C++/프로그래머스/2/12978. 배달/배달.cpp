#include <bits/stdc++.h>

const int INF = 1e9;
using namespace std;

void dijkstra(vector<vector<vector<int>>>& graph, vector<int>& dist, int start){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
    dist[start] = 0;
    heap.push({0, start});
    
    while (not heap.empty()){
        auto row = heap.top();
        heap.pop();
        int cur_dist = row[0], cur_v = row[1];
        if (cur_dist > dist[cur_v]) continue;
        
        for (auto& v: graph[cur_v]){
            int next_dist=cur_dist+v[0], next_v=v[1];
            
            if (next_dist < dist[next_v]){
                dist[next_v] = next_dist;
                heap.push({next_dist, next_v});                    
            }
        }
        
    }
    
}

int solution(int N, vector<vector<int>> road, int K) {
    int ans = 0;
    vector<int> dist(N+1, INF);
    vector<vector<vector<int>>> graph(N+1);
    
    for (auto& info: road){
        graph[info[0]].push_back({info[2], info[1]});
        graph[info[1]].push_back({info[2], info[0]});
    }
    
    dijkstra(graph, dist, 1);
    
    for (int d: dist){
        if (d <= K)
            ans++;
    }

    return ans;
}