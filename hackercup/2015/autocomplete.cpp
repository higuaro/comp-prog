#include <fstream>
#include <iostream>
#include <cstring>
#include <bitset>
#include <list>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <map>

struct trieNode {
   size_t wordCount;
   trieNode* alphabet[28];
   trieNode() : wordCount(0) {
      for (int i = 0; i < 28; i++) {
         alphabet[i] = nullptr;
      }
   }
   
   int childCount() { 
      int count = 0;
      for (int i = 0; i < 28; i++)
         if (alphabet[i] != nullptr) count++;
      return count;
   }
   
   /*
   ~trieNode() {
      for (int i = 0; i < 28; i++) {
         delete alphabet[i];
      }
   }
   */
};

struct trie {
   trieNode* root;
   trie() : root(new trieNode()) {}
   void addWord(const std::string& word);
   bool exists(const std::string& word);
   /*
   ~trie() {
      delete root;
   }
    */
};

void trie::addWord(const std::string& word) {
   trieNode* currentNode = root;
   for (char c : word) {
      trieNode* letter = currentNode->alphabet[c - 'a' + 1];
      if (letter == nullptr) {
         letter = currentNode->alphabet[c - 'a' + 1] = new trieNode();
      }
      currentNode = letter;
      currentNode->wordCount++;
   }
   currentNode->alphabet[0] = new trieNode();
}

bool trie::exists(const std::string& word) {
   trieNode* currentNode = root;
   for (char c : word) {
      trieNode* letter = currentNode->alphabet[c - 'a' + 1];
      if (letter == nullptr) return false;
      currentNode = letter;
   }
   return currentNode->alphabet[0] != nullptr;
}

int minimumPreffixCount(const std::string& word, const trie& t) {
   int preffixCount = 0;
   trieNode* node = t.root;
   for (char c : word) {
      node = node->alphabet[c - 'a' + 1];
      preffixCount++;
      if (node->childCount() < 2 && node->wordCount < 2)
         break;
   }
   return preffixCount;
}

int t_main(int argc, char** argv) {
   std::ifstream fis("autocomplete.txt");
   std::ofstream fos("autocomplete.out");
   std::cout.rdbuf(fos.rdbuf());
   
   int t;
   fis >> t; fis.ignore(256, '\n');
   int cases = 1;
   while (t--) {
      int n;
      fis >> n; fis.ignore(256, '\n');
      int typedLetters = 0;
      trie tr;
      while (n--) {
         std::string word;
         std::getline(fis, word);
         if (!tr.exists(word))
            tr.addWord(word);
         typedLetters += minimumPreffixCount(word, tr);
      }
      std::cout << "Case #" << cases << ": " << typedLetters << std::endl;
      cases++;
   }
   
   return 0;
}