class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict (wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push(pair<string, int>(beginWord, 1));
        if(dict.find(endWord) == dict.end()) return 0;
        while(!q.empty()){
            auto [curr, len] = q.front(); q.pop();
            for(int w = 0; w < curr.size(); w++){
                char org = curr[w];
                for(char i = 'a'; i<='z'; i++){
                    curr[w] = i;
                    if(curr == endWord){
                        return len+1;
                    }
                    if(dict.find(curr) != dict.end()){
                        q.push({curr, len+1});
                        dict.erase(curr);
                    }
                }
                curr[w] = org;
            }
        }
        return 0;
    }
};
