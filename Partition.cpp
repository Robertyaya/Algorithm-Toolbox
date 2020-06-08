#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

bool DP_Partition(std::vector<int> &vec)
{
  // Sorting first
  std::sort(vec.begin(), vec.end(), [](int &a, int &b) { return a > b; });

  int sum = 0;
  for (int i = 0; i < vec.size(); i++)
    sum += vec[i];

  if (sum < 3 || sum % 3 != 0)
  {
    return false;
  }

  bool dp[sum / 3 + 1][vec.size() + 1];

  // Initialize dp array
  for (int i = 0; i <= vec.size(); i++)
  {
    dp[0][i] = true;
  }
  for (int i = 1; i <= sum / 3; i++)
  {
    dp[i][0] = false;
  }

  // Record the last index in order to back tracking
  int last_index;
  bool flag = true;
  for (int i = 1; i <= sum / 3; i++)
  {
    for (int j = 1; j <= vec.size(); j++)
    {
      dp[i][j] = dp[i][j - 1];
      if (i >= vec[j - 1])
      {
        dp[i][j] = dp[i][j] || dp[i - vec[j - 1]][j - 1];
        if (dp[i][j] && i == sum / 3 && flag)
        {
          last_index = j;
          flag = false;
        }
      }
    }
  }

  last_index = vec.size();

  if (!dp[sum / 3][vec.size()])
    return false;

  // Back tracking and remove the element from the vector
  int total = sum / 3;
  while (total > 0)
  {
    total -= vec[last_index - 1];
    for (int i = 1; i <= vec.size(); i++)
    {
      if (dp[total][i])
      {
        // Remove the element
        vec.erase(vec.begin() + (last_index - 1));
        last_index = i;
        break;
      }
    }
  }

  // Do again to find the subset's sum is sum/3
  bool dp_[sum / 3 + 1][vec.size() + 1];

  // Initialize dp array
  for (int i = 0; i <= vec.size(); i++)
  {
    dp_[0][i] = true;
  }
  for (int i = 1; i <= sum / 3; i++)
  {
    dp_[i][0] = false;
  }

  // Fill the dp array
  for (int i = 1; i <= sum / 3; i++)
  {
    for (int j = 1; j <= vec.size(); j++)
    {
      dp_[i][j] = dp_[i][j - 1];
      if (i >= vec[j - 1])
      {
        dp_[i][j] = dp_[i][j] || dp_[i - vec[j - 1]][j - 1];
      }
    }
  }
  return dp_[sum / 3][vec.size()];
}
int main()
{
  std::vector<int> vec;
  int n;
  std::cin >> n;
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int a;
    std::cin >> a;
    vec.push_back(a);
  }

  std::cout << DP_Partition(vec) << std::endl;
}
