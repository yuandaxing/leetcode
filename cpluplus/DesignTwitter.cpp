/*
 * author: yuandx
 * create: 2016-06-27
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using std::priority_queue;
using std::unordered_map;
using std::unordered_set;
using std::ostringstream;
using std::istringstream;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;
using std::for_each;
/*
  every user could follow 1000-
  * some user could be followed more than 1e7 users
  * active user
 */
class Twitter
{
public:
  static int start_;

  struct Twit
  {
    int seq_no_;
    int con_;
    Twit(int seq, int c):
      seq_no_(seq), con_(c)
    {

    }
  };
  struct User
  {
    vector<int> follow_;
    vector<Twit> twit_;
  };
  struct Pos
  {
    vector<Twit>::iterator beg, end;
  };
  unordered_map<int, User> id_2_user_;
  /** Initialize your data structure here. */
  Twitter()
  {
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    int cur_id = start_++;
    User& user = id_2_user_[userId];
    user.twit_.push_back(Twit(cur_id, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    auto comp =  [](const Pos& p1, const Pos& p2)
    {
      return (p1.beg)->seq_no_ > (p2.beg)->seq_no_;
    };

    priority_queue<Pos> queue(comp);

  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {

  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {

  }
};

int main()
{

  return 0;
}
