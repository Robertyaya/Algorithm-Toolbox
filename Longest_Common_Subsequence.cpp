#include <iostream>
#include <vector>
#include <fstream>

int Max(int a, int b, int c)
{
  if (a >= b && a >= c)
    return a;
  else if (b >= a && b >= c)
    return b;
  else
    return c;
}

void LCS(std::vector<int> &a, std::vector<int> &b)
{
  int dp[1000][1000];
  std::vector<int> sub_sequ;

  // Initialize dp array
  for (int i = 0; i <= a.size(); i++)
    dp[0][i] = 0;
  for (int i = 0; i <= b.size(); i++)
    dp[i][0] = 0;

  for (int i = 1; i <= b.size(); i++)
  {
    for (int j = 1; j <= a.size(); j++)
    {
      if (a.at(j - 1) == b.at(i - 1))
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else // a[j-1]!=b[i-1]
      {
        dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
      }
    }
  }

  // Debug
  // for (int i = 0; i <= b.size(); i++)
  // {
  //   for (int j = 0; j <= a.size(); j++)
  //   {
  //     std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // for (int i = 0; i < sub_sequ.size(); i++)
  //   std::cout << sub_sequ[i] << " ";
  // std::cout << std::endl;
  std::cout << dp[b.size()][a.size()] << std::endl;
}

int main()
{
  std::fstream fin("test.txt");
  std::vector<int> vec_a, vec_b;
  int a, b;
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
  LCS(vec_a, vec_b);
}
