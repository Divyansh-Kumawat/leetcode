class Solution {
public:
    bool exists(vector<vector<char>>& board, int i, int j, const string& word, int ind) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[ind])
            return false;

        if (ind == word.size() - 1)
            return true;

        char ch = board[i][j];
        board[i][j] = '*'; // mark visited

        bool res = exists(board, i + 1, j, word, ind + 1) ||
                   exists(board, i - 1, j, word, ind + 1) ||
                   exists(board, i, j + 1, word, ind + 1) ||
                   exists(board, i, j - 1, word, ind + 1);

        board[i][j] = ch; // backtrack
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && exists(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
