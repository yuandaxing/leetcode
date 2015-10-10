#include <map>
#include <string>
using std::map;
using std::string;
class TrieNode
{
public:
TrieNode(): is_leaft_(false)
{
}
private:
map<char, TrieNode*> children;
bool is_leaft_;
friend class Trie;
};

class Trie {
public:
Trie() {
root = new TrieNode();
}

// Inserts a word into the trie.
void insert(string word) {
TrieNode *cur = root;
for (int i = 0; i != word.size(); i++)
{
if (cur->children.find(word[i]) == cur->children.end())
{
cur->children[word[i]] = new TrieNode();
}
cur = cur->children[word[i]];
}
cur->is_leaft_ = true;
}

// Returns if the word is in the trie.
bool search(string word) {
TrieNode *cur = root;
for (int i = 0; i != word.size(); i++)
{
if (cur->children.find(word[i]) == cur->children.end())
{
return false;
}
cur = cur->children[word[i]];
}
return cur->is_leaft_ == true;
}

// Returns if there is any word in the trie
// that starts with the given prefix.
bool startsWith(string prefix) {
TrieNode *cur = root;
for (int i = 0; i != prefix.size(); i++)
{
if (cur->children.find(prefix[i]) == cur->children.end())
{
return false;
}
cur = cur->children[prefix[i]];
}
return true;
}

private:
TrieNode* root;
};
