class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        vector<vector<int>> neighbours(numCourses);
        vector<int> pre(numCourses, 0);
        for(auto n : prerequisites){
            pre[n[1]]++; // label the prerequites
            neighbours[n[0]].push_back(n[1]); // must take course 1 before course 0
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++){
            if(pre[i] == 0){
                que.push(i);
            }
        }
        int finish = 0;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            finish++;
            for(auto & nei : neighbours[node]){
                pre[nei]--;
                if(pre[nei] == 0){
                    que.push(nei);
                }
            }
        }
        return finish == numCourses;
    }
};
