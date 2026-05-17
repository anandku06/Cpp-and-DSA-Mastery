// 355. Design Twitter
// Medium
// Topics
// premium lock icon
// Companies
// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

// Example 1:

// Input
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output
// [null, null, [5], null, null, [6, 5], null, [5]]

// Explanation
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
// twitter.follow(1, 2);    // User 1 follows user 2.
// twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.unfollow(1, 2);  // User 1 unfollows user 2.
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

// Constraints:

// 1 <= userId, followerId, followeeId <= 500
// 0 <= tweetId <= 104
// All the tweets have unique IDs.
// At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
// A user cannot follow himself.

// approach: We can use a hash map to store the tweets of each user and a hash set to store the followers of each user. We can then use a priority queue to store the tweets of the users that the user is following and the user's own tweets. We can then use a loop to get the 10 most recent tweets from the priority queue and add them to the news feed.

#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> list of (tweetId, timestamp)
    unordered_map<int, unordered_set<int>> followers;      // userId -> set of followeeIds
    int timestamp;                                         // global timestamp to keep track of the order of tweets
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        userTweets[userId].push_back({tweetId, timestamp++}); // add the tweet to the user's list of tweets with the current timestamp
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> newsFeed;              // to store the 10 most recent tweets in the user's news feed
        priority_queue<pair<int, int>> pq; // max heap to store the tweets of the users that the user is following and the user's own tweets

        // add the user's own tweets to the priority queue
        for (auto &tweet : userTweets[userId])
        {
            pq.push(tweet); // push the tweet (tweetId, timestamp) to the priority queue
        }

        // add the tweets of the users that the user is following to the priority queue
        for (int followeeId : followers[userId])
        {
            for (auto &tweet : userTweets[followeeId])
            {
                pq.push(tweet); // push the tweet (tweetId, timestamp) to the priority queue
            }
        }

        // get the 10 most recent tweets from the priority queue and add them to the news feed
        while (!pq.empty() && newsFeed.size() < 10)
        {
            newsFeed.push_back(pq.top().first); // add the tweetId to the news feed
            pq.pop();                           // remove the tweet from the priority queue
        }

        return newsFeed; // return the news feed
    }

    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId); // add the followeeId to the set of followers of the followerId
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId); // remove the followeeId from the set of followers of the followerId   
    }
};