#include <fstream>
#include <vector>
#include <iostream>

int Max(std::vector<int> &vec)
{
  int Max = 0;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] > Max)
      Max = vec[i];
  }
  return Max;
}

void LCS(std::vector<int> &vec_a, std::vector<int> &vec_b, std::vector<int> &vec_c)
{
  int dp[100][100][100];

  // Initialize
  for (int i = 0; i <= vec_a.size(); i++)
    dp[i][0][0] = 0;
  for (int i = 0; i <= vec_b.size(); i++)
    dp[0][i][0] = 0;
  for (int i = 0; i <= vec_c.size(); i++)
    dp[0][0][i] = 0;

  // Fill the dp array
  for (int i = 1; i <= vec_a.size(); i++)
  {
    for (int j = 1; j <= vec_b.size(); j++)
    {
      for (int k = 1; k <= vec_c.size(); k++)
      {
        if ((vec_a[i - 1] == vec_b[j - 1]) && (vec_a[i - 1] == vec_c[k - 1]))
        {
          dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
        }
        else
        {
          std::vector<int> temp;
          temp.push_back(dp[i - 1][j][k]);
          temp.push_back(dp[i][j - 1][k]);
          temp.push_back(dp[i][j][k - 1]);
          temp.push_back(dp[i][j - 1][k - 1]);
          temp.push_back(dp[i - 1][j][k - 1]);
          temp.push_back(dp[i - 1][j - 1][k]);
          temp.push_back(dp[i - 1][j - 1][k - 1]);
          dp[i][j][k] = Max(temp);
        }
      }
    }
  }
  std::cout << dp[vec_a.size()][vec_b.size()][vec_c.size()] << std::endl;
}

int main()
{
  std::fstream fin("test.txt");
  std::vector<int> vec_a, vec_b, vec_c;
  int a, b, c;
  std::cin >> a;
  vec_a.reserve(a);
  for (int i = 0; i < a; i++)
  {
    int temp;
    std::cin >> temp;
    vec_a.push_back(temp);
  }
  std::cin >> b;
  vec_b.reserve(b);
  for (int i = 0; i < b; i++)
  {
    int temp;
    std::cin >> temp;
    vec_b.push_back(temp);
  }
  std::cin >> c;
  vec_c.reserve(c);
  for (int i = 0; i < c; i++)
  {
    int temp;
    std::cin >> temp;
    vec_c.push_back(temp);
  }
  LCS(vec_a, vec_b, vec_c);
}
