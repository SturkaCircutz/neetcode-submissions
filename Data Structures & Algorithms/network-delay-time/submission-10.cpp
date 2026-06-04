class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for(auto t : times){
            edges[t[0]].emplace_back(t[1], t[2]);
        }
        set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> minheap;
        minheap.push({0,k});
        int t = 0;
        while(!minheap.empty()){
            auto n1 = minheap.top().second;
            auto w1 = minheap.top().first;
            minheap.pop();    //
            if(visited.count(n1)){
                continue;
            }
            visited.insert(n1);
            t = w1;
            if(edges.count(n1)){
                for(auto& next : edges[n1]){
                    
                        auto n2 = next.first;
                        auto w2 = next.second;
                        if(!visited.count(n2)){
                            minheap.push({w1+w2, n2});
                        }
                } 
            }
            
        }
        return visited.size() == n ? t: -1;
        }
        
    
};
