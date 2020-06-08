#include <iostream>
#include <vector>
#include <fstream>

int dp[10000][10000];

void DP_version(int W, std::vector<int> &vec)
{
  // Initialize dp array
  for (int i = 0; i <= vec.size(); i++)
    dp[0][i] = 0;
  for (int i = 0; i <= W; i++)
    dp[i][0] = 0;

  // Fill the dp array (row by row)

  for (int i = 1; i <= W; i++)
  {
    for (int j = 1; j <= vec.size(); j++)
    {
      dp[i][j] = dp[i][j - 1];
      // Update the value
      if (vec[j - 1] <= i)
      {
        int value = dp[i - vec[j - 1]][j - 1] + vec[j - 1];
        if (value > dp[i][j])
          dp[i][j] = value;
      }
    }
  }

  //Debug
  // for (int i = 0; i <= W; i++)
  // {
  //   for (int j = 0; j <= vec.size(); j++)
  //   {
  //     std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  std::cout << dp[W][vec.size()] << std::endl;
}

int main()
{
  std::vector<int> vec;
  int W, n;
  std::cin >> W >> n;
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int w;
    std::cin >> w;
    vec.push_back(w);
  }

  DP_version(W, vec);
}
