#include <string>
#include <iostream>

using namespace std;

class TrieNode {
public:
  char c;
  TrieNode *next;
  TrieNode *child;

public:
  // Initialize your data structure here.
  TrieNode() : c('.'), next(NULL), child(NULL) {}
  TrieNode(char ch) : c(ch), next(NULL), child(NULL) {}
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string s) {
    TrieNode *p = root;
    if (!p->child) {
      for (int i = 0; i < s.length(); ++i) {
        TrieNode *node = new TrieNode(s[i]);
        p->child = node;
        p = p->child;
      }
      p->child = new TrieNode('\0');
      return ;
    }
    TrieNode *fakeHead = new TrieNode();
    int i = 0;
    while (i < s.length()) {
      fakeHead->next = p->child;
      TrieNode *iter = fakeHead;
      while (iter->next && s[i] != iter->next->c) iter = iter->next;
      if (iter->next) { p = iter->next; ++i; }
      else {
        TrieNode *node = new TrieNode(s[i]);
        iter->next = node;
        TrieNode *np = iter->next;
        for (int j = i + 1; j < s.length(); ++j) {
          TrieNode *n = new TrieNode(s[j]);
          np->child = n;
          np = np->child;
        }
        np->child = new TrieNode('\0');
        delete fakeHead;
        return ;
      }
    }
    fakeHead->next = p->child;
    TrieNode *iter = fakeHead;
    while (iter->next && '\0' != iter->next->c) iter = iter->next;
    iter->next = new TrieNode('\0');
    delete fakeHead;
  }

  // Returns if the word is in the trie.
  bool search(string key) {
    TrieNode *p = root;
    int i = 0;
    while (p->child && i < key.length()) {
      TrieNode *iter = p->child;
      while (iter && iter->c != key[i]) iter = iter->next;
      if (iter) { p = iter; ++i; }
      else return false;
    }
    if (i == key.length()) {
      TrieNode *iter = p->child;
      while (iter) {
        if (iter->c == '\0') return true;
        else iter = iter->next;
      }
    }
    return false;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *p = root;
    int i = 0;
    while (p->child && i < prefix.length()) {
      TrieNode *iter = p->child;
      while (iter && iter->c != prefix[i]) iter = iter->next;
      if (iter) { p = iter; ++i; }
      else return false;
    }
    return i == prefix.length();
  }

private:
  TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main() {
  Trie trie;
  trie.insert("abcd");
  trie.insert("abce");
  trie.insert("abc");
  trie.insert("edf");
  trie.insert("edgk");

  cout << "Search abce: " << trie.search("abce") << endl;
  cout << "Search abc: " << trie.search("abc") << endl;
  cout << "Search ed: " << trie.search("ed") << endl;
  cout << "Search edpp: " << trie.search("edpp") << endl;

  cout << "Start with abc: " << trie.startsWith("abc") << endl;

  return 0;
}

