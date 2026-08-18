import heapq
from collections import defaultdict

def solution(N, road, K):
    ans = 0
    dist = [float('inf')] * (N+1)
    graph = defaultdict(list)
    
    for v1, v2, c in road:
        graph[v1].append([v2, c])
        graph[v2].append([v1, c])
    
    # print('graph', graph)
    
    def dijkstra(start, graph, dist):
        heap = [(0, start)]
        dist[start] = 0
        # print(heap)
        while heap:
            cur_dist, cur_v = heapq.heappop(heap)
            
            if (cur_dist > dist[cur_v]):
                continue
            # dist[cur_v] = cur_dist
            
            for next_v, d in graph[cur_v]:
                next_dist = cur_dist + d
                if (next_dist < dist[next_v]):
                    dist[next_v] = next_dist
                    heapq.heappush(heap, (next_dist, next_v))
        
        return dist
    
    
    dijkstra(1, graph, dist)
    # print(dist)
    for d in dist[1:]:
        if d <= K:
            ans += 1
            
    return ans    
