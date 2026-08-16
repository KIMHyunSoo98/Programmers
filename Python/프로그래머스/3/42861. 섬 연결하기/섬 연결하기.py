import heapq

def solution(n, costs):
    ans = 0
    heap = []
    
    for v1, v2, c in costs:
        heapq.heappush(heap, (c, v1, v2))
        
    parents = [i for i in range(n)]
    
    def find(u, parents):
        
        if (u != parents[u]):
            parents[u] = find(parents[u], parents)
        
        return parents[u]
    
    def union(u, v, parents):
        pu = find(u, parents)
        pv = find(v, parents)
        
        if (pu == pv):
            return True
        
        if (pu > pv):
            parents[pv] = pu
        else:
            parents[pu] = pv
            
        return False
        
    while (heap):
        cost, v1, v2 = heapq.heappop(heap)
        # print(parents)
        if union(v1, v2, parents):
            continue
        
        ans += cost
    
    # print(parents)
    return ans