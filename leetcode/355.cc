/*
这个解法有些冗余..其实完全不用User class..但是在True scenario中肯定要这个类..
还有求recently 10个post的时候，用priority queue比较好..
*/
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include "assert.h"
using namespace std;

class User {
private:
    int user_id_;
    std::set<int> followees_;
    std::vector<pair<int, time_t> > tweet_ids_;
public:
    User() {}
    User(int user_id) {
        user_id_ = user_id;
    }
    
    bool operator< (const User &rhs) const {
        return user_id_ < rhs.user_id_;
    }

    void postTweet(int tweet_id, time_t time_stamp) {
        tweet_ids_.push_back(make_pair(tweet_id, time_stamp));
    }
    void addFollowee(int followee) {
        if (followee != user_id_)
            followees_.insert(followee);
    }
    void removeFollowee(int followee) {
        followees_.erase(followee);
    }
    vector<pair<int, time_t> > getTweets() {
        return tweet_ids_;
    }
    set<int> getFolloweeIds() {
        return followees_;
    }
}; 

class Twitter {
private:
    time_t global_time_stamp_ = 0;
    std::map<int, User> id_to_user_;
    void addUser(int userId) {
        if (id_to_user_.find(userId) == id_to_user_.end()) {
            User user(userId);
            id_to_user_[userId] = user;
        }    
        return;
    }
    static bool cmp_sort(pair<int, time_t> a, pair<int, time_t> b) {
        return a.second > b.second;
    }

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        addUser(userId);
        User user = id_to_user_[userId];
        user.postTweet(tweetId, global_time_stamp_++);
        id_to_user_[userId] = user;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        addUser(userId);    
        User user = id_to_user_[userId];
        vector<pair<int, time_t> > tweets;

        vector<pair<int, time_t> > user_tweets = user.getTweets();
        int size = user_tweets.size();
        for (int i = size - 1; i >= max(0, size - 10); --i) {
            tweets.push_back(user_tweets[i]);
        }
        
        auto followees = user.getFolloweeIds();
        for (auto it = followees.begin(); it != followees.end(); ++it) {
            vector<pair<int, time_t> > followee_tweets = id_to_user_[*it].getTweets();
            size = followee_tweets.size();
            for (int i = size - 1; i >= max(0, size - 10); --i) {
                tweets.push_back(followee_tweets[i]);
            }
        }
        std::sort(tweets.begin(), tweets.end(), cmp_sort);
        vector<int> news_feed;
        for (int i = 0; i < min(10, int(tweets.size())); ++i) {
            news_feed.push_back(tweets[i].first);
        }
        return news_feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        addUser(followerId);
        addUser(followeeId);
        User user = id_to_user_[followerId];
        user.addFollowee(followeeId);
        id_to_user_[followerId] = user;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        addUser(followerId);
        addUser(followeeId);
        User user = id_to_user_[followerId]; 
        user.removeFollowee(followeeId);
        id_to_user_[followerId] = user;
    }
};

void test() {
    Twitter twitter;
    
    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);
    
    // User 1's news feed should return a list with 1 tweet id -> [5].
    auto news_feed = twitter.getNewsFeed(1);
    assert(news_feed == vector<int>{5});
    
    // User 1 follows user 2.
    twitter.follow(1, 2);
    
    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    news_feed = twitter.getNewsFeed(1);
    auto ans = vector<int>{6, 5};
    assert(news_feed == ans);

    
    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);
    
    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    news_feed = twitter.getNewsFeed(1);
    assert(news_feed == vector<int>{5});

    cout << "Test Pass." << endl;
}

int main() {
    test();
}
