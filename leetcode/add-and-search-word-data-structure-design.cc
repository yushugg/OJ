#include <string>
#include <iostream>

using namespace std;

class TrieNode {
public:
  char c;
  TrieNode *right;
  TrieNode *next;

public:
  TrieNode(char ch) : c(ch), right(NULL), next(NULL) {}
};

class WordDictionary {
public:
  TrieNode *root;
  WordDictionary() {
    root = new TrieNode('\0');
    // !!!Avoid first add a string
    root->next = new TrieNode('\0');
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode *p = root;
    int idx = 0;
    TrieNode *fakeHead = new TrieNode('\0');
    while (idx < word.length()) {
      fakeHead->right = p->next;
      TrieNode *iter = fakeHead;
      // Iterate right
      while (iter->right) {
        if (word[idx] == iter->right->c) { p = iter->right; ++idx; break; }
        else iter = iter->right;
      }
      // Add to the right
      if (!iter->right) {
        TrieNode *node = new TrieNode(word[idx]);
        iter->right = node;
        TrieNode *it = iter->right;
        for (int i = idx + 1; i < word.length(); ++i) {
          TrieNode *n = new TrieNode(word[i]);
          it->next = n;
          it = it->next;
        }
        it->next = new TrieNode('\0');
        delete fakeHead;
        return ;
      }
    }
    // Add \0 to the last
    fakeHead->right = p->next;
    TrieNode *iter = fakeHead;
    while (iter->right && '\0' != iter->right->c) iter = iter->right;
    if (!iter->right) iter->right = new TrieNode('\0');
    delete fakeHead;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool searchCharacter(TrieNode *node, string word, int idx) {
    char ch = idx < word.length() ? word[idx] : '\0';
    if ('.' == ch) {
      bool result = false;
      while (node) { result |= searchCharacter(node->next, word, idx + 1); node = node->right; }
      return result;
    }
    while (node) {
      if (node->c == ch) {
        if (idx == word.length()) return true;
        else return searchCharacter(node->next, word, idx + 1);
      }
      else node = node->right;
    }
    return false;
  }
  
  bool search(string word) {
    return searchCharacter(root->next, word, 0);
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main() {
  WordDictionary wordDictionary;
  int size;
  cin >> size;
  while (size--) {
    string word;
    cin >> word;
    wordDictionary.addWord(word);
  }

  string pattern;
  while (cin >> pattern) cout << wordDictionary.search(pattern) << endl;
  
  return 0;
}

