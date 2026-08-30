#include <bits/stdc++.h>

const int INF = 1e9;
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>& graph, vector<int>& dist, int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    dist[start] = 0;
    heap.push({0, start});
    
    while (not heap.empty()){
        auto row = heap.top();
        heap.pop();
        int cur_dist = row.first, cur_v = row.second;
        if (cur_dist > dist[cur_v]) continue;
        
        for (auto& v: graph[cur_v]){
            int next_dist=cur_dist+v.first, next_v=v.second;
            
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
    vector<vector<pair<int,int>>> graph(N+1);
    
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