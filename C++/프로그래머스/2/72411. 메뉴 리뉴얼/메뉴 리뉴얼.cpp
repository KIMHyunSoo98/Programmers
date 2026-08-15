#include <bits/stdc++.h>

using namespace std;

vector<string> combination(string li, int n){
    vector<string> result;
    
    if (n == 1)
        for (auto l: li)
            result.push_back(string(1, l));
    
    if (n > 1){
        for (int i=0; i < li.size()-n+1; i++){
            for (auto j: combination(li.substr(i+1), n-1)){
                result.push_back(string(1, li[i]) + j);
            }
        }   
    }
    
    return result;    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ans;
    
    for (int num_c: course){
        unordered_map<string, int> menu_map;
        int local_max = 0;
        
        for (auto& order: orders){
            if (order.size() < num_c) continue;
            
            for (auto& menu: combination(order, num_c)){
                sort(menu.begin(), menu.end());
                menu_map[menu] += 1;
                local_max = max(local_max, menu_map[menu]);
            }            
        }
        
        if (menu_map.empty()) continue;
        if (local_max < 2) continue;
        
        for (auto& [menu, cnt]: menu_map){
            if (cnt == local_max)
                ans.push_back(menu);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}