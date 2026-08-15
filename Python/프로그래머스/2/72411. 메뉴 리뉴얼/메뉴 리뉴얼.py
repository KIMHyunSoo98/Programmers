from collections import defaultdict


def solution(orders, course):
    ans = []
    
    def combination(li, n):
        result = []
        
        if n == 1:
            return li
        
        if n > 1:
            for i in range(len(li)-n+1):
                for j in combination(li[i+1:], n-1):
                    result.append(li[i] + j)
                            
        return result
        
    
    for len_c in course:
        menu_dic = defaultdict(int)
        for order in orders:
            if (len(order) < len_c): continue     
            
            for menu in combination(order, len_c):                
                menu_dic[''.join(sorted(menu))] += 1
        
        if menu_dic:
            menu_tuple = sorted(menu_dic.items(), key=lambda x:(-x[1]))
            local_max = menu_tuple[0][1]            
            if local_max < 2: continue
            
            for menu, cnt in menu_tuple:
                if cnt == local_max:
                    ans.append(menu)
    
    return sorted(ans)