#include <vector>

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        board.assign(n, string(n, '.'));
        dfs(0, n);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<string> board;
    void dfs(int i, int n)
    {
        if (i == n)
        {
            res.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (!isValid(i, j))
                continue;
            board[i][j] = 'Q';
            dfs(i + 1, n);
            board[i][j] = '.';
        }
    }

    bool isValid(int row, int col)
    {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }
};

int main(int argc, char const *argv[])
{
    auto res = (new Solution)->solveNQueens(4);
    auto pv = [](const auto res)
    {
        for (auto &&i : res)
            cout << i << "\n";
    };
    for (auto &&i : res)
    {
        pv(i);
        cout << '\n';
    }

    return 0;
}
