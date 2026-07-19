class Solution {
public:
    unordered_set<int> cycle;
    int start;
    vector<vector<int>> adj;
    vector<bool> visit;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n+1);
        visit.resize(n+1, false);
        start = -1;
        for(auto & edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(1, -1);
        for(int i = edges.size()-1; i>= 0; i--){
            int u = edges[i][0], v = edges[i][1];
            if(cycle.count(u) && cycle.count(v)){
                return {u, v};
            }
        }
        return {};
    }
    bool dfs(int node, int par){
        if(visit[node]){
            start = node;
            return true;
        }
        visit[node] = true;
        for(auto nei : adj[node]){
            if(nei == par) continue;
            if(dfs(nei, node)){
                if(start != -1) cycle.insert(nei);
                if(start == node){
                    start = -1;
                }
                return true;
            }
        }
        return false;
    }
};
