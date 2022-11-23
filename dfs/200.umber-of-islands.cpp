#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == '1')
        {
          cnt++;
          bfs(grid, i, j);
        }
      }
    }
    return cnt;
  }

private:
  void bfs(vector<vector<char>> &grid, const int i, const int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
    {
      return;
    }

    if (grid[i][j] != '1')
    {
      return;
    }

    grid[i][j] = '2';
    bfs(grid, i - 1, j);
    bfs(grid, i + 1, j);
    bfs(grid, i, j - 1);
    bfs(grid, i, j + 1);
  }
};

int main()
{
  Solution s;
  vector<vector<char>> grid{
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}};
  cout << s.numIslands(grid) << endl;

  return 0;
}
