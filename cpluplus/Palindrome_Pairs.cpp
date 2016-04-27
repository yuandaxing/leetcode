/*
 * author: yuandx
 * create: 2016-04-24
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
/*
 * Example 1:
 * Given words = ["bat", "tab", "cat"]
  Return [[0, 1], [1, 0]]
  The palindromes are ["battab", "tabbat"]
*/
/*
 * reverse order Trie Tree
 */
class TrieNode
{
public:
  TrieNode(): is_leaf_(false), idx_(-1)
  {
  }
  map<char, TrieNode*> children;
  bool is_leaf_;
  int idx_;
  friend class Trie;
};

class Trie {
public:
  TrieNode* root;
public:
  Trie() {
    root = new TrieNode();
  }
  // Inserts a word into the trie.
  void insert(string word, int idx) {
    TrieNode *cur = root;
    for (size_t i = 0; i != word.size(); i++)
    {
      if (cur->children.find(word[i]) == cur->children.end())
      {
        cur->children[word[i]] = new TrieNode();
      }
      cur = cur->children[word[i]];
    }
    cur->is_leaf_ = true;
    cur->idx_ = idx;
  }
  static void CollectLeaf(TrieNode* cur, vector<int>& idxs)
  {
    if(cur == NULL)
    {
      return ;
    }
    if (cur->is_leaf_)
    {
      idxs.push_back(cur->idx_);
    }
    for (auto it = (cur->children).begin(); it != (cur->children).end(); ++it)
    {
      CollectLeaf(it->second, idxs);
    }
  }
};
class Solution
{
public:
  bool IsPalindrome(const string& s, int i, int j)
  {
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++, j--;
    }
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string>& words)
  {
    Trie t;
    for (size_t i = 0; i != words.size(); i++)
    {
      string tmp(words[i]);
      std::reverse(tmp.begin(), tmp.end());
      t.insert(tmp, i);
    }
    vector<vector<int>> result;
    for (int i = 0; i != static_cast<int>(words.size()); i++)
    {
      TrieNode* cur = t.root;
      string& s = words[i];
      bool left = true;
      for (size_t k = 0; k != s.size(); k++)
      {
        if (cur->children.find(s[k]) != cur->children.end())
        {
          cur = cur->children[s[k]];
          if (cur->is_leaf_ && IsPalindrome(s, k+1, s.size() - 1)
              && i != cur->idx_)
          {
            result.push_back({i, cur->idx_});
          }
        }
        else
        {
          left = false;
          break;
        }
      }
      vector<int> leaf_over;
      if (left)
      {
        for (auto it = cur->children.begin(); it != cur->children.end(); ++it)
        {
          Trie::CollectLeaf(it->second, leaf_over);
        }
      }
      for (auto it = leaf_over.begin(); it != leaf_over.end(); ++it)
      {
        string& str = words[*it];
        if (IsPalindrome(str, 0, str.size() - s.size() - 1))
        {
          result.push_back({i, *it});
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution s;
  vector<string> v1 = {"bbaabaaaabbbbaaaabaaaabaabbabbbaaabbabbbabbaaababbaabbaaaabbbaabbaabaaaabaaabbaabab","babbbbbaabbbaaaaaabbbbbbbaabbabbabbbbbaababaabbabbbabbbbbbabba","bbbbaabbbababbabbbbabaababaabbaabbabaaaaabababbabbabbbbbabbbbaaaabbabbabbbabababbbaaa","ababbbbbbbaaaabbaaababbbabababbaabbaababbbabbbabaabbaabaababbbabababaaabbbbabbaa","abbbaababaaaaabababaabaaaaaabbbbbbbababaaaabaabbbaaabbaaaabbbabbbbabbaaaaaaaaaaabbaaaababbabbbabbabaaaaabbaababbabbabababaaaaabbabbababbaaaabbbababaaabbaaabbabbaaba","aabbaaaaaaabaaabbbababbbbabababaaabbbabaabbababbaabbbbbaabbbbaabaa","abbabaabbaaaaaababbbabbabababbababbbbaaaaabbbaaabbaababbababbbabbaaaabbabbbabbabaaaaaaabbabbbaababaaaabbaabaabababbaaaababbabbbabaabbabbbbaaaabbabbaabbaaaababbbbbbaaaaaababba","abbabaabbabbabbbabaabbbbbabaabbbbaabaaabaabaaabbaaaaaaababbababb","bbabbbbaaabbbbaaababbabaabbbbababaaaabbaaabbbaabbbaaabaababababaaaaabbbbaaaabbbababbabbbbaabbbbaaaaaaaaaabbabaaabaabaaa","aabaabbabbabbaaabbbbbaabbaababbabbaabbabaaaaaababaabaabbaaaabbabbbaababaaabaabbbbbaabbbbabbbbaaaaabbbbabbbbabaabaabbaabbbabaabababaabbaaaaabbabaaabbaabbbabaaaababbabbbababaaabbaa","bbbaaaaaaaabaababbabbabbbb","aabbaababbbbbbbabbbababaaaababbabaaabbaaaaabbbaaababbaaabbaaaaaaabbaabbaababbbbaabbaababbabbbbbbaaabaaaabbaabaababaabaab","aabbaabaabbabaabbbababbbaababbaaaababaaaaabaaaababbabbabababaaaabbabbbabbbbbbaababaaabbbababaabaaaabbbabaaa","aabbbbbbaabbabababbbbabbbbbaabbabaabbaaabbbb","ababbabaaabaaa","babbaaaaabbaaabaaaabaabaabaaabaaaaaaabaaabba","bababaabbaaaaababbabaaabbbabababbbbbabbbbababb","aaababbbbaabaabaaaabaabbabbababaaaaab","baabbbbbaabbaaaaababbabaabbabaaaabbabbbaabbabababababbaabaaabbbaabaabbbabbaaabbbbabababaabaabaabaabbbaaabaaabbbaaabaaaabbaaabbaaaababbbbabbaabbababbaabbbbbbababaaaabbbababa","baabbabaabaababbbaababbbbbabbbabbaaaaaaaabbbaabbaabaabbbabaabaabaabbaaabaaaabaaabaababaa","bbabbbabaababaabaaabbbbaaaaaabbbaaaaaaabababababbbbababbaaaaabbaabbabababbaaaabababbababbabbababbabbaa","aabbaabaabbaaabaaaaaabaaabbabababaaaabbabaabaaabbbabababbaabaaabbabbbbabbaabbababbbabbaaaabaaababbabbbbbbaaabbaababbabaabaaabaaabbbabaababaa","babaaababaabbabbabbbbbabaaabbaaabbabaabbabbabbbaabbbaaaaaabaabbaababbbbaaababbababbabbbabaababaabbabababbbabaabbbbaabaababbaa","bbabbababaaababababaabaaaaaaaabaababaababbabbabb","bbabbbbabbaaaabaabbbbbbabbbaaaaaaabbbbabbaaabbabaabbabaabbbbbbaabbbabaaabbabaaabbaba","baabbbbbbaaaaabbaabbbbabaaabbaaaabbbaaabbabaaababaababbbbbbabbaabaaabaaabbabbabaaaba","bbbaabaabbabababbaaabbaaaababaabbbbaabaaaaaaaaabbbbaabbbbabbbabababbabbbbababbaabbba","aabbbaabaababaaaabbbbabaabaabaaabababbaabbaabbaaabaababaaabbbabaaababaabbaababbbbaababaabaabbaababbababbbbbababababaabbabbaabaaaaaabaabbaabaabaaabaabba","abbabaababbbbbbaaaaaababbaabaabbaabbaaaababaababaabbbbbaaaabbbabbbbbaabbbbbbaaababbbaabaabababb","bbbaabaabaaaaabaabaabbbbaaaabaabbbbbaabbaaabbbbbababbbbabbaaaaabbaababababababbbbbbbaaabaabbbaaaaababbbaabbabaabababbbbaaabaabbababbbaabbaabbbbaaaabababbabaabbaaaaaababaaaaabaababaabbabaabbabababab","babaabaabaabbbabaaaabaabbbaaaaaaabaababbabbbaabbbabaababbabbaabbaaabaaaabaababbabbaababbabababbbabaabbbababbbbbbbaaababbaaaabaabaabbababbaaabbaabbbaaabaabaaaabaa","abbbababaaabbaabbbbabababbaabbaaaabaabaabbbbbbbbaabbbbaaaaabbbbabaaaaabbbaaaaabbbbaaaaaababbbbbaabbabaaaaabbaabaaabaababbabaabaaabbab","babaabaababababbbbabababbbaabbaaabbbaabbaaaabaaabbbbbaaaab","aaaabbaabababbbaa","bbbbabbaabaabbbbaaaaaaaabbaababaaabaaabaaabbbbaababbbaabaabbbbaaabbabaabbbbbabbbbaaabababaabbaaababbabababbbabbabaabaaaabbab","aababaabaaaaaabbabababaaaaababbbbaabaa","bbababaaaaaaaaabaabbaaaabaaaaaaaaabbbabaabbbbbabaabaaabbbabbbabbbaaaaaabaaabbbbbbaa","abbaabaaaaabbaaaaaabbbbabaabbabbaabbbabbababaabaabaaabbababbaaabaababbbbbabbbabbabbaaaabbaababbaababbbabbbbbbaaabbbbbbb","baabababbbbbaabbbabaababaababaababbbabbbbbababbaababbaaaabaaabbbbaaaababbabbbabaabaabbababaaa","abbaabbbaabbabbabbbbbbbabbbabbaaabbaaababbaabbaababab","bbabbabbbbbbabababbbabaabbbaaaabababbaabbbabbbbaababbaabaaabbbbabaaaabbbabbaaabaabbaabbbaaababbaaaabaabbabbbabbbaaabaaabbbbabbaabbaabaa","aaaabbbabbaabbababbabbabaababbababaabbaaabaaaababbbabbaaaabbbbabaaabbbaaabababbbabbaabaaabbaabbbaabbbbaaabbbaabbbbababaaaaababbbabaabbbbbbabbabbbbbabaaabaaaaaabbaa","babaaabaabbaababaaabbaaababbbbbbbaabbbbbbbbabbaabbbbbbaaaaabbaabababaabbbabaaaaaaabbaabababaaabbabbabbaababbaaabbbaaaababbbbbabbbaabbbaaaabbabbaabbbaababbaaaabbaaaababbbbbb","abaababbaaabbbaaaaababaabbab","aabbaaaababbbabbbaaabaabababbabbbaabaaaabaabaaaabbabaabbaaabbbaaabbaabbabbbbaaabbbababbaabbaaaabbbabaabbbabbbbbbbaab","aabbbabbabaaaaabbabbababbbabbbbbbbbaabbbbabbbaabaabbaaababbbaaaaabbaaabbab","baaaabababaaababbaabbbabaaabbbbabbbbaaaabbabbbbbbbbababbaaaaabaabaaabbaabbbbbabababaabbbbaabbbbbabbaabaaabaababbbabbbabaababbaaaabbaaaaaabaababbbabaabbbaaabbbabbbaabbbbbbaabbabbbbabaabbbbaba","bbbaababaabaabbabbaabbabbaabbbbabaabbabbbbbbbabbaaaaababaaabbbaba","baaaaababaabaabaabbbbabbbbbaabbaabbaaababaabaababaabbaaabbabbbabbbaababababbaaaab","baabaaababbabbbaaaabbaabbaababbaababbbaabaabaaaaaabbbbababaaabaaabaababbaabbabbaababbbbbabbabbaabbaabbbabbbaabb","bbaaaaabbbaaabbbaaaaaaaaaabaaaaa","bbbbbbabaaaaabbbbaaabbabaababaabababbabbabaabababababbaabbabbbabbbababa","bbaabbbaabbabababaaaaaabbaabbababbbbabaabbbaabbabaabbbabbbabbaaabbabbababaaabbbababbabbbbbbbbaaaaabbaa","abaabbbaabbbbaabbabaabaaabaabaaaabbabbbabbaaabbbbababaabaaabaaaaaaaabaaaababbababaabbbbbaababaabbbbabbaaabbbabbabbbbabbbbaabaaa","bababbabbaaabbabaababbbbaabaabbbbbbababaabbbbaababababbaabbaabaaaababbabbabab","baaabbabbaaababbbbbbbaabaaabbabbaaabbabababbaaaabaabbbbaaaabbabbbbbbabaaaaabaabaaaaabababbbaabbaabbabbbbbabaababababbbbbbaabbbabbbaaabaabababaabaabbbbbbbbabaaaaabbaababab","ababababababbbabbabbbbbabbabbbbabbaaabbbbbbbbbbabbaabaabbbababbabbbaaaababbaabbbaab","baaaabbababbabaabbabbaabbbbabbbabbabbbbbabaaaabaabbbabbaababbabababaaaaabaaaababbbabbbaaaaabbbabbbaaaabbbbbaaaba","baababbbaaaabbbaaababbabaababbbbbaaabaabaaabababbbbaabbaaabaaabaaaaaabbbbbaabaaaababbbaabb","aaabaabbabaaaaaaaaaabbb","abbbaabaabbbbbabbaababbaaaaababbaaaaabbabbbb","ababaabababbbabbbbaaabbabbbaaaaaaabbabbbaba","baababbaabbbaabbbbbbaaabbbbaaaabbbbabaabbaaabaaababbbaaabbaabaabaabaaabbbbbaabaaaaab","babbabababaabbbaabababaaaaaaaaaabbbbabbababbbaaaabbaabababbbbbbbababaaaababbaaaabaabaaabaabaaaaababbbbababbaabbaaabbabaaababbbbbabbbaaabaababbaabbabbbbaaaabababaaa","abbbbbaaaaabbaabbbabaabbabaabbbaaabbaaabaabbb","abbababb","aababaaabbbabbbbaaaabaababbababbbaaaaabbababbbbaaaaaababababaabaaaabbbabbaababbbabbabaabbababbbbabbabbbabaaabababaababbbbbaaabaabaaaabbabbaaababbabaaaaa","abbbaaaaabaabbbabbbabbaaabbaababababbbaabbababaababaabbaaababbabbb","aaabaaabaabaababbabbbbaaaaaaaaabbbabbaabbababbaabababbbbbabbabababbabaaaabbbbabbbbbbbabbabaabababbaaabbaaaaaabbababbbbbbbaabbabbaaaababbabaaabbaabaaababaabaaaabaaba","baabbabbaabbbabbbbabbbaabbabaababaaaabaaaabbaaabaaababbabbbbbabaabbbaababaaababaababbaabaabaabababaaabbbbaabbbabbbbbba","abaababaaabaabbaabaaababbaabbbababbbaaaaaabbbabaaababbaabbbbaaabaabbaaabaaaababbabbbbbababbbaabbaaababaaaaaaababbbbbba","aaaabbaaaaaabbbaaaaabbaabbaabaabbababbbbbabababbababbabbaaaaabbaaabbabbaaabbbbbbaaabbbbbabbbbbabbabbaaaaaabbbbbaaaaaabbabbbbbbabbbaabbbaababbbbbabbaaabaa","ababbaaaababababbabaaabaaaaaabbbbababaababbababaabaabababaaaabbaaabaaaaaaabbbbababbabbbbabbbbbbabbbabaabbbabbbbbabbbbbababbbbaabbbaabbbababaaaabbbbaaabbab","bbabaababbabbbbbbaabbaaaabbaaabbabbaaabbabbaabaaabbbabbbababaabbbaaba","bbaaabbbaabaababbbababaaabbbbababbbbbaabaaabbbaabbbaaaaabbaabbaabaaabbabaababaaabbaababaabbbbbbaaabbabaabababaabbbaaaaabbbaaaabaabbababaaababaabbaabaaaaabaaaababbabaabababababaabaaaabaaabbaaabbbbababa","abbaaabbbaabbabb","abbbabbaaaabaabaaababaaaaabababbbaabbbbaabbbaaa","babaaabbbbbb","baaabaaabbbabaabbbaabaabbaaaabbbabbabbbbbaabbabbbabaabababaabbbbabaabaabbaaabbbabaaaaaaaaaabbbbaaabbaaaaaabaababbaabbabaabbbabaaabbbbaabbaababba","babababbbbabbaaaaaabbbbbaba","babba","abbbabaabbabbbbbbbbababaaaaaab","bbabbabbbabaaabbbaaababbbbaaaaaaabab","bbabbaabbbabaaaaaababaabbbabaaabaaababaabaaaaaaaaaaabbaababaababbababbabbababbbaaabbaaaabbaabbbbaaabbabbbabaabbbbbabababbaabaabbbabaabaaabaaababbbabbabbaababaabbbbaabaabbabbbbabbabbaababbbbba","bbaaabaaababaaaabbaabbabbbaabbaaabaababbaaababbbaaabaabaabbabababaaaabbbbbaaaabbbbbbababbbbabbbababbaababaababbbabaaabbabaaaabababaaabababaaabbbbbaaaaababaabbbbaabaaabba","ababaaaaaabbabbabba","aaabababaabaaabaaaaabaaabaababbbbbababbbabbbbbbaabbaaaaaba","baabbbab","abbaaaaababbbaaaabbbaaabbaaababbababababaabbabaabaaabaabaaabbaaabbababbaabaaaabaabababbbbbbabaabaaabaaaababbaababbaabbbbbaabbbbbbabaa","ababaaabbababbabbbaabbbaabaaaaaaaabbabaabaaaaaabaa"};
  vector<string> v = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> result = s.palindromePairs(v1);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << "(" << (*it)[0] << ", " << (*it)[1] << ")";
  }
  cout << endl;
  return 0;
}
