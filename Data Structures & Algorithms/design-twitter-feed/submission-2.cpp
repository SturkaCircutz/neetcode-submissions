class Twitter {
public:
    unordered_map<int, vector<int>> followlist;
    unordered_map<int, vector<int>> postlist;
    vector<pair<int,int>> postorder;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        postlist[userId].emplace_back(tweetId);
        postorder.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i = postorder.size()-1; i >= 0 && ans.size()<10; i--){
            int user = postorder[i].first;
            int tweet = postorder[i].second;
            if(user == userId || find(followlist[userId].begin(), followlist[userId].end(),user) != followlist[userId].end()){
                ans.push_back(tweet);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followlist[followerId].emplace_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i = followlist[followerId].size()-1; i >= 0 ; --i){
            if(followlist[followerId][i] == followeeId){
                followlist[followerId].erase(followlist[followerId].begin()+i);
            }
        }
    }
};
