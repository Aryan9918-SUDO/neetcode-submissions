class Twitter {
public:
    int timestamp;
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>> tweets;
    //userid->({time,tweetid})
    Twitter() {
        timestamp=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxheap;
        for(auto& tweet : tweets[userId]){
            maxheap.push(tweet);
        }
        for(int followee:following[userId]){
            for(auto& tweet : tweets[followee]){
                maxheap.push(tweet);
            }
        }
        vector<int>feed;
        while(!maxheap.empty() && feed.size() < 10) {
            feed.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return feed;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        following[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
    }
};
