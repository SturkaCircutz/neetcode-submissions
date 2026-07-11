class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res (numCourses);
        vector<int> outline (numCourses, 0);
        vector<vector<int>> neighbours (numCourses);
        for(auto & pre : prerequisites){
            outline[pre[0]]++;
            neighbours[pre[1]].push_back(pre[0]);
        }
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(outline[i] == 0){
                que.push(i);
            }
        }
        int count = 0;
        while(!que.empty()){
            auto node = que.front(); que.pop();
            count++;
            res[count-1] = node;
            for(auto & nei : neighbours[node]){
                outline[nei]--;
                if(outline[nei] == 0){
                    que.push(nei);
                }
            }
        }
        if(count != numCourses){
            return {};
        }
        return res;
    }
};
