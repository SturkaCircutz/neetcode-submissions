class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i<gas.size(); i++){
            if(dfs(gas, cost, i, 0, 0)) return i;
        }
        return -1;
    }
    bool dfs(vector<int>& gas, vector<int>& cost, int idx, int count, int ctank){
        if(count == gas.size()) return true;
        ctank += gas[idx];
        ctank-= cost[idx];
        if(ctank<0) return false;
        int etank = ctank + gas[(idx+1)%gas.size()];
        int cost1 = cost[(idx+1)%gas.size()];
        cout<<"ctank: "<<ctank<<endl;
        cout<<"etank: "<<etank<<endl;
        cout<<"cost1: "<<cost1<<endl;
        if(etank<cost1) return false;
        cout<<"count: "<<count<<endl;
        return dfs(gas, cost, (idx+1)%gas.size(), count+1, ctank);
    }
};
