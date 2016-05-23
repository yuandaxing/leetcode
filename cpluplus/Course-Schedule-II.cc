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
  vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites)
  {
    map<int, set<int> > pre_req;
    vector<int> result;
    for (int i = 0; i != numCourses; i++) pre_req[i] = set<int>();
    for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it)
    {
      pre_req[it->first].insert(it->second);
    }
    while (!pre_req.empty())
    {
      int find = numCourses;
      for (map<int, set<int> >::iterator it = pre_req.begin(); it != pre_req.end(); ++it)
      {
        if( it->second.size() == 0)
        {
          find = it->first;
          break;
        }
      }
      if (find == numCourses) break; //not find
      result.push_back(find);
      pre_req.erase(find);
      for (map<int, set<int> >::iterator it = pre_req.begin(); it != pre_req.end(); ++it)
      {
        it->second.erase(find);
      }
    }
    return result.size() == static_cast<size_t>(numCourses) ? result : vector<int>();
  }
};
