class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<int> visited;
        unordered_map<int, vector<pair<int,int>>> edges;
        for(auto t : times){
            edges[t[0]].emplace_back(t[1], t[2]);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minheap;
        minheap.push({0,k});
        int t = 0;
        while(!minheap.empty()){
            auto curr = minheap.top();
            int n1 = curr.second, w1 = curr.first;
            minheap.pop();
            if(visited.count(n1)){
                continue;
            }
            visited.insert(n1);
            t = w1;
            if(edges.count(n1)){
                for(auto&next: edges[n1]){
                    auto n2 = next.first, w2 = next.second;
                    if(!visited.count(n2)){
                        
                        minheap.push({w1+w2,n2});
                    }
                }
            }

        }
        return visited.size()==n ?t: -1;
    }
};
