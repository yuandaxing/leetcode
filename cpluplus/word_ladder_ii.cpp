/*
 * author: yuandx
 * create: 2016-05-21
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
class Solution
{
private:
  unordered_map<string, vector<string>> word_2_words;
  unordered_set<string> visited_;
  void DFS(const string& end, const string& cur,
           vector<string>& tmp,
           vector<vector<string>>& result,
           int length)
  {
    if (end == cur)
    {
      tmp.push_back(end);
      result.push_back(tmp);
      tmp.pop_back();
      return ;
    }
    if (length > 0)
    {
      tmp.push_back(cur);
      visited_.insert(cur);
      vector<string>& v = word_2_words[cur];
      for (auto it = v.begin(); it != v.end(); ++it)
      {
        if (visited_.find(*it) == visited_.end())
        {
          DFS(end, *it, tmp, result, length - 1);
        }
      }
      tmp.pop_back();
      visited_.erase(cur);
    }
  }
public:
  bool HasEdge(const string& w1, const string& w2)
  {
    int count = 0;
    for (size_t i = 0; i != w1.size(); ++i)
    {
      if (w1[i] != w2[i])
      {
        count += 1;
      }
    }
    return count == 1;
  }
  vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
  {
    wordList.insert(beginWord);
    wordList.insert(endWord);
    for (auto it = wordList.begin(); it != wordList.end(); ++it)
    {
      auto it2 = it;
      for (++it2; it2 != wordList.end(); ++it2)
      {
        if (HasEdge(*it, *it2))
        {
          word_2_words[*it].push_back(*it2);
          word_2_words[*it2].push_back(*it);
        }
      }
    }

    //BFS
    vector<string> cur, next;
    unordered_set<string> visited;
    size_t count = 0;
    cur.push_back(beginWord);
    visited.insert(beginWord);
    while (!cur.empty())
    {
      if (find(cur.begin(), cur.end(), endWord) != cur.end())
      {
        count += wordList.size();
        break;
      }
      for (auto it = cur.begin(); it != cur.end(); ++it)
      {
        auto& v = word_2_words[*it];
        for (auto it2 = v.begin(); it2 != v.end(); ++it2)
        {
          if (visited.find(*it2) == visited.end())
          {
            next.push_back(*it2);
            visited.insert(*it);
          }
        }
      }
      cur.clear();
      count++;
      cur.swap(next);
    }
    vector<vector<string>> result;
    if (count > wordList.size())
    {
      vector<string> tmp;
      DFS(endWord, beginWord,
               tmp, result, count - wordList.size());
    }
    return result;
  }
};

int main()
{
  Solution s;
  unordered_set<string> v1 = {"hot","dot","dog","lot","log"};
  vector<vector<string>> result = s.findLadders("hit", "cog", v1);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
    {
      cout << *it2 << " " ;
    }
    cout << endl;
  }

  return 0;
}
