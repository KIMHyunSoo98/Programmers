from collections import defaultdict, deque


def permutation(li, n, cur_path=[], result=[]):    
    if (len(cur_path) == n):
        result.append(cur_path)
        return
    
    for i in range(len(li)):
        permutation(li, n, cur_path + [li[i]], result)
    
    return result
        

def bfs(tree, queue, open_type):
    
    next_queue = queue.copy()
    visited = set(next_queue)
    # print('visited', visited)
    
    while queue:
        cur_v = queue.popleft()
        
        for next_v, next_type in tree[cur_v]:
            if (next_type == open_type) and (next_v not in visited):
                # print('next_v', next_v)
                visited.add(next_v)
                queue.append(next_v)
                next_queue.append(next_v)
        
    return next_queue
        

def solution(n, infection, edges, k):
    ans = 1
    tree = defaultdict(list)
    
    for (x, y, ty) in edges:
        tree[x].append((y, ty))
        tree[y].append((x, ty))
    
    # print(tree)
    
    for order_types in permutation([1,2,3], k):
        # print('order_types', order_types)
        queue = deque([infection])
        # visited = set()
        # visited.add(infection)
        partial_ans = 1
        
        for open_type in order_types:
            # print('queue', queue, '\n open_type', open_type, '\n')
            # print('before_queue', queue)
            new_queue = bfs(tree, queue, open_type)
            # print('new_queue', new_queue)
            # print(new_queue)
            partial_ans = len(new_queue)
            # print('partial', partial_ans)
            # print()
            # print('partial_ans', partial_ans)
            # if (ans == partial_ans): break
            ans = max(ans, partial_ans) 
            # print('ans', ans)
            if (ans == n): break
            queue = new_queue.copy()
            # print('queue', queue)
            # print()
        
    
    return ans