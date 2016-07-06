#include <vector>
#include <string>
using std::vector;
using std::string;
/*
 * vector search in four direction, [0, 1], [0, -1], [1, 0], [-1, 0]
 * Trie tree search
 * depth first
 */
class Solution
{
  vector<string> results;
  int x_dim, y_dim;

  struct TrieNode
  {
    TrieNode* exits[26];
    bool      is_end;
  };

  void recurse( vector<vector<char>>& board, string& s, int x, int y, TrieNode* trie_curr )
  {
    if ( x >= x_dim || y >= y_dim )
      return;

    const auto c = board[y][x];

    if ( !c )
      return;

    auto trie_next = trie_curr->exits[ c-'a' ];
    if ( !trie_next )
      return;

    s.push_back( c );
    board[y][x] = 0;

    if ( trie_next->is_end ) {
      results.push_back( s );
      trie_next->is_end = false;
    }

    recurse( board, s, x-1, y, trie_next );
    recurse( board, s, x+1, y, trie_next );
    recurse( board, s, x, y-1, trie_next );
    recurse( board, s, x, y+1, trie_next );

    board[y][x] = c;
    s.pop_back();
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
  {
    if ( !words.size() || !board.size() || !board[0].size() )
      return results;

    int tot_chars = 0;
    for ( const auto& word : words )
      tot_chars += word.length();

    TrieNode* trie_pool = (TrieNode*)calloc( sizeof(TrieNode), tot_chars + 2 );
    int num_trie_nodes = 0;

    TrieNode* trie_root = &trie_pool[ num_trie_nodes++ ];

    for ( const auto& word : words )
    {
      TrieNode* trie_curr = trie_root;
      for ( const auto c : word ) {
        auto& trie_next = trie_curr->exits[ c-'a' ];

        if (!trie_next)
          trie_next = &trie_pool[ num_trie_nodes++ ];

        trie_curr = trie_next;
      }
      trie_curr->is_end = true;
    }
    x_dim = board[0].size();
    y_dim = board.size();
    string s;
    for ( auto y = 0 ; y < y_dim ; ++y )
      for ( auto x = 0; x < x_dim; ++x )
        recurse( board, s, x, y, trie_root );

    free( trie_pool );  // from C to shining C.
    return results;
  }
};
