#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int Min(int a, int b, int c)
{
  if (a <= b && a <= c)
    return a;
  else if (b <= a && b <= c)
    return b;
  else
    return c;
}

void Edit_Distance(std::string str1, std::string str2)
{
  int dp[100][100];

  // Initialize dp array
  dp[0][0] = 0;
  for (int i = 1; i <= str1.size(); i++)
    dp[i][0] = i;
  for (int i = 1; i <= str2.size(); i++)
    dp[0][i] = i;

  // Fill the dp array
  for (int i = 1; i <= str2.size(); i++)
  {
    for (int j = 1; j <= str1.size(); j++)
    {
      // The character is the same
      if (str1[j - 1] == str2[i - 1])
        dp[j][i] = Min(dp[j - 1][i] + 1, dp[j][i - 1] + 1, dp[j - 1][i - 1]);
      else
        dp[j][i] = Min(dp[j - 1][i] + 1, dp[j][i - 1] + 1, dp[j - 1][i - 1] + 1);
    }
  }

  // Debug
  // for (int i = 0; i <= str1.size(); i++)
  // {
  //   for (int j = 0; j <= str2.size(); j++)
  //   {
  //     std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;
  std::cout << dp[str1.size()][str2.size()] << std::endl;
}
int main()
{
  std::fstream fin("test.txt");
  std::string str1, str2;
  std::cin >> str1 >> str2;
  Edit_Distance(str1, str2);
}
