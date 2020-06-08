#include <iostream>
#include <vector>

int Min(std::vector<int> &vec)
{
  int min;
  for (int i = 0; i < vec.size(); i++)
  {
    if (i == 0)
      min = vec[i];
    else
    {
      if (vec[i] < min)
        min = vec[i];
    }
  }
  return min;
}

void Money_Change_DP(int money)
{
  // Denominations 1,3,4
  std::vector<int> DP;
  std::vector<int> denomimations;
  denomimations.push_back(1);
  denomimations.push_back(3);
  denomimations.push_back(4);
  DP.reserve(money + 1);

  for (int i = 0; i <= money; i++)
  {
    if (i == 0)
      DP.push_back(0);
    else
    {
      std::vector<int> min_dp;
      for (int j = 0; j < denomimations.size(); j++)
      {
        if (i - denomimations[j] >= 0)
          min_dp.push_back(DP[i - denomimations[j]] + 1);
      }
      DP.push_back(Min(min_dp));
    }
  }

  // for (int i = 0; i < DP.size(); i++)
  //   std::cout << DP[i] << " ";
  // std::cout << std::endl;

  std::cout << DP[DP.size() - 1] << std::endl;
}
int main()
{
  int money;
  std::cin >> money;
  Money_Change_DP(money);
}
