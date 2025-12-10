#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word = false;
    ~TrieNode() {
        for (auto &p : children) delete p.second;
    }
};

struct Trie {
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    ~Trie() { delete root; }

    void insert(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->is_end_of_word = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty()) return {};

        Trie trie;
        for (auto &w : words) trie.insert(w);

        int rows = (int)board.size();
        int cols = (int)board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        unordered_set<string> result_set;
        string path;
        path.reserve(32);

        function<void(int,int,TrieNode*)> backtrack = [&](int r, int c, TrieNode* node) {
            if (node->is_end_of_word) {
                result_set.insert(path);
                node->is_end_of_word = false; 
            }

            visited[r][c] = true;
            static const int DIRS[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for (auto &d : DIRS) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (visited[nr][nc]) continue;
                char next_char = board[nr][nc];
                auto it = node->children.find(next_char);
                if (it != node->children.end()) {
                    path.push_back(next_char);
                    backtrack(nr, nc, it->second);
                    path.pop_back();
                }
            }
            visited[r][c] = false;
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                char start = board[r][c];
                auto it = trie.root->children.find(start);
                if (it != trie.root->children.end()) {
                    path.clear();
                    path.push_back(start);
                    backtrack(r, c, it->second);
                }
            }
        }
        vector<string> result(result_set.begin(), result_set.end());
        return result;
    }
};