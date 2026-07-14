class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> visit;
        vector<vector<int>> neighbours(n);
        for(auto i : edges){
            neighbours[i[0]].push_back(i[1]);
            neighbours[i[1]].push_back(i[0]);
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(!visit.count(i)){
                dfs(i, edges, visit, neighbours);
                res++;
            }
        }

        return res;
    }
    void dfs(int node, vector<vector<int>>&edges, unordered_set<int> &visit, vector<vector<int>>&neighbours){
        visit.insert(node);
        for(auto nei: neighbours[node]){
            if(!visit.count(nei)){
            dfs(nei, edges, visit, neighbours);
            }
        }
    }
};
