#include <map>
#include <string>
#include <algorithm>
using std::string;
using std::map;

struct Node
{
  Node(char c, bool stop = false): c_(c), stop_(stop)
  {
  }
  ~Node()
  {
    for (map<char, Node*>::iterator it = children_.begin(); it != children_.end(); ++it)
    {
      delete it->second;
    }
  }
  map<char, Node*> children_;
  char c_;
  bool stop_;
};

class WordDictionary {
  Node* root;

public:
  WordDictionary()
  {
    root = new Node(-1, true);
  }
  ~WordDictionary()
  {
    delete root;
    root = NULL;
  }
public:

    // Adds a word into the data structure.
    void addWord(string word) {
      Node* cur = root;
      for (int i = 0; i != word.size(); i++)
      {
        if (cur->children_.find(word[i]) == cur->children_.end())
        {
          cur->children_[word[i]] = new Node(word[i]);
        }
        cur = cur->children_[word[i]];
      }
      cur->stop_ = true;
    }

  bool search_aux(string& word, int i, Node* cur)
  {
    if (i == word.size())
    {
      return cur->stop_;
    }
    if (word[i] == '.')
    {
        auto it = find_if(cur->children_.begin(), cur->children_.end(),
                          [i, this, &word](map<char, Node*>::value_type& v){
              return search_aux(word, i+1, v.second);
                          });
      return it != cur->children_.end();
    }
    else
    {
      return cur->children_.find(word[i]) != cur->children_.end() && search_aux(word, i+1, cur->children_[word[i]]);
    }
  }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      return search_aux(word, 0, root);
    }
};
