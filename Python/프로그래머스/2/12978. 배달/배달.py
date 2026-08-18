import heapq

def solution(N, road, K):
    ans = 0
    dist = [float('inf')] * (N+1)
    graph = {i+1: {} for i in range(N)}
    
    for v1, v2, c in road:
        if graph[v1].get(v2, 0) != 0:
            if graph[v1][v2] > c:
                graph[v1][v2] = c
                graph[v2][v1] = c
        else:
            graph[v1][v2] = c
            graph[v2][v1] = c
    
    # print('graph', graph)
    
    def dijkstra(start, graph, dist):
        heap = []
        dist[start] = 0
        for k, v in graph[start].items():
            heapq.heappush(heap, (v, k))
        # print(heap)
        while heap:
            cur_dist, cur_v = heapq.heappop(heap)
            
            if (cur_dist > dist[cur_v]):
                continue
            dist[cur_v] = cur_dist
            
            for next_v, d in graph[cur_v].items():
                next_dist = cur_dist + d
                if (next_dist <= dist[next_v]):
                    # dist[next_v] = next_dist
                    heapq.heappush(heap, (next_dist, next_v))
        
        return dist
    
    
    dist = dijkstra(1, graph, dist)
    # print(dist)
    for d in dist[1:]:
        if d <= K:
            ans += 1
            
    return ans    