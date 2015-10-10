#include <vector>
#include <utility>
#include <map>
#include <set>
#include <climits>
#include <iostream>
using std::cout;
using std::set;
using std::map;
using std::pair;
using std::vector;
using std::make_pair;
using std::size_t;
using std::multiset;
/*
  map<int, int> height_to_num
  map<int, set<int> > end_to_height
  vector<pair<int, int> >result;
  beg, end, height = array[0][0], array[0][1], array[0][2]
  result.push_back(make_pair(beg, height))
  cur = (beg, height)
  end_to_height[end].insert(height)
  for element in arrays[1:...]:
     beg, end, height = element[0], element[1], element[2]
     it = end_to_height.begin()
     while (!end_to_height.empty() && it->first <= beg)
     {
         most_beg = *(--it->second.end())
         if most_beg == cur[1]:
              cur[1] = bigest_height_left
              cur[1] = it->first
              end_to_height.erase(it);
         it = end_to_height.begin();
     }
     if height > cur_height || end_to_height.empty():
        result.push_back(beg, height)
     end_to_height.insert(end, height)
     //to remote consecutive element
     a[i][0] == a[i+1][0] || a[i][1] == a[i+1][1]
     remove the same element
 */
/*
  [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ]
  [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]

*/

class Solution {
public:
  struct HeightNum
  {
    map<int, int> height_2_num;
    void Add(int i)
    {
      height_2_num[i] += 1;
    }
    void Remove(int i)
    {
      height_2_num[i] -= 1;
      if (height_2_num[i] == 0)
      {
        height_2_num.erase(i);
      }
    }
    int Most()
    {
      if (!height_2_num.empty())
      {
        return (--height_2_num.end())->first;
      }
      return 0;
    }
  };
  vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings)
  {
    vector<pair<int, int> > result;
    pair<int, int> cur;
    map<int, multiset<int> > end_2_height;
    HeightNum hn;
    if (buildings.size() == 0) return result;
    long beg = buildings[0][0], end = buildings[0][1], height = buildings[0][2];
    cur = make_pair(beg, height);
    end_2_height[end].insert(height);
    hn.Add(height);
    result.push_back(cur);
    size_t i = 1;
    do
    {
      //cout << "do while" << std::endl;
      if (i < buildings.size())
      {
        beg = buildings[i][0], end = buildings[i][1], height = buildings[i][2];
      }
      else
      {
        end = height = 0;
        beg = long(INT_MAX) + 1;
      }
      map<int, multiset<int> >::iterator it = end_2_height.begin();
      if (!end_2_height.empty() && it->first < beg)
      {
        int cur_end = it->first;
        int cur_height = *(--it->second.end());
        for (multiset<int>::iterator sit = it->second.begin(); sit != it->second.end(); ++sit)
        {
          hn.Remove(*sit);
        }
        end_2_height.erase(it);
        if (cur_height == cur.second)
        {
          cur.first = cur_end;
          cur.second = hn.Most();
          result.push_back(cur);
        }
      }
      else
      {
        if (end_2_height.empty()|| cur.second < height)
        {
          cur = make_pair(beg, height);
          result.push_back(cur);
        }
        end_2_height[end].insert(height);
        hn.Add(height) ;
        i++;
      }
    }while (!end_2_height.empty() || i < buildings.size());
     // a[i][0] == a[i+1][0] || a[i][1] == a[i+1][1]
     // remove the same element
    int insert_pos = 1;
    //cout << result.size() << std::endl;
    for (size_t start = 1; start != result.size(); start++)
    {
      //cout << result[start].first << " " << result[start].second << std::endl;
      int cur = insert_pos - 1;
      if (result[cur].first == result[start].first)
      {
        result[cur].second = std::max(result[cur].second, result[start].second);
      }
      else if (result[cur].second == result[start].second)
      {
        continue;
      }
      else
      {
        result[insert_pos++] = result[start];
      }
    }
    result.resize(insert_pos);
    return result;
  }
};


int main(int argc, char *argv[])
{
  vector<int> a = {0, 1, 3}; //b = {2, 5, 3};
  vector<vector<int> > c = {a};
  Solution sol;
  vector<pair<int, int> > result = sol.getSkyline(c);
  return 0;
}
