#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& parents, int v){
    if (v != parents[v])
        parents[v] = find(parents, parents[v]);
    
    return parents[v];
}

bool union_(vector<int>& parents, int u, int v){
    int pu = find(parents, u);
    int pv = find(parents, v);
    
    if (pu == pv)
        return true;
    else if (pu < pv)
        parents[pv] = pu;
    else
        parents[pu] = pv;
    
    return false;
}


int solution(int n, vector<vector<int>> costs) {
    int ans = 0, num_edges = 0;
    vector<int> parents;
    
    for (int i=0; i < n; i++)
        parents.push_back(i);
    
    sort(costs.begin(), costs.end(), [](const vector<int> a, const vector<int> b){
        if (a[2] < b[2])
            return true;
        else if (a[2] > b[2])
            return false;
        else
            return a < b;
    });
    
    for (auto& cost: costs){
        int v1=cost[0], v2=cost[1], c=cost[2];
        
        if (union_(parents, v1, v2))
            continue;
        
        ans += c;
        num_edges += 1;
        if (num_edges == n-1)
            break;
    }
    
    return ans;
}