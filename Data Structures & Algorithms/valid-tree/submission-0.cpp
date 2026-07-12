class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbours(n);
        for(auto edge : edges){
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> que;
        unordered_set<int> count;
        que.push({0, -1});
        count.insert(0);
        while(!que.empty()){
             auto [node, parent] = que.front(); que.pop();
            for(auto & nei : neighbours[node]){
                if(nei == parent){
                    continue;
                }
                if(count.count(nei)){
                    return false;
                }
                que.push({nei, node});
                count.insert(nei);
            }
        }
        return n==count.size();

    }
};
