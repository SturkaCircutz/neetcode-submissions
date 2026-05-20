class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        comp(candidates, target, curr, 0);
        return ans;
    }

    void comp(vector<int>& cand, int target, vector<int>curr, int i){

        if(target==0)  {ans.push_back(curr);
        return;} // end
        for(int j = i; j<cand.size(); ++j){
            if(j>i && cand[j]==cand[j-1] ) continue;
            if(cand[j]>target) return;
            curr.push_back(cand[j]);
            comp(cand, target - cand[j], curr, j+1);
            curr.pop_back();
        }
    

    }
};
