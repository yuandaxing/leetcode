#include <vector>
#include <utility>
#include <map>
#include <set>
using std::vector;
using std::pair;
using std::map;
using std::set;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
      map<int, set<int> > prereq;
      vector<int> result;
      for (int i = 0; i != numCourses; i++) prereq[i] = set<int>();
      for (int i = 0; i != prerequisites.size(); i++)
      {
        prereq[prerequisites[i].first].insert(prerequisites[i].second);
      }
      while (!prereq.empty())
      {
        int find = numCourses;
        for (map<int, set<int> >::iterator it = prereq.begin(); it != prereq.end(); ++it)
        {
          if( it->second.size() == 0)
          {
            find = it->first;
            break;
          }
        }
        if (find == numCourses) break;
        result.push_back(find);
        prereq.erase(find);
        for (map<int, set<int> >::iterator it = prereq.begin(); it != prereq.end(); ++it)
        {
          it->second.erase(find);
        }
      }
      return result.size() == numCourses ? result : vector<int>();
    }
};
