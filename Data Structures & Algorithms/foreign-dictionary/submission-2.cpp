class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> adj;
        for(auto & w : words){
            for(auto & c: w){
                adj[c] = unordered_set<char>{};
                indegree[c] = 0;
            }
        }
        string res = "";
        for(int i = 0; i < words.size()-1; i++){
            string pre = words[i], later = words[i+1];
            int minlen = min(pre.size(), later.size());
            if(pre.size()> later.size() && pre.substr(0, minlen) == later.substr(0, minlen)){
                return "";
            }
            for(int j = 0; j < minlen; j++){
                if(pre[j] != later[j]){
                    if(!adj[pre[j]].count(later[j])){
                        adj[pre[j]].insert(later[j]);
                        indegree[later[j]]++;
                    }
                    break;
                }
            }
        }
            queue<char> q;
            for(auto & [c, indeg] : indegree){
                if(indeg == 0){
                    q.push(c);
                }
            }
            while(!q.empty()){
                char front = q.front();
                q.pop();
                res+=front;
                for(auto & nei: adj[front]){
                    indegree[nei]--;
                    if(indegree[nei] == 0){
                        q.push(nei);
                    }
                } 
            }
            return res.size() == indegree.size() ? res:"";
                }
};
