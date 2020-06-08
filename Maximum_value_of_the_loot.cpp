#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

bool comparison(std::pair<int, int> &a, std::pair<int, int> &b)
{
  return ((double)a.first / a.second) > ((double)b.first / b.second);
}

double Efficent_Knapsack(std::vector<std::pair<int, int>> &vec, int total_weight)
{
  double Max_Value = 0;
  int weight;

  // Sorting first
  std::sort(vec.begin(), vec.end(), comparison);

  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i].second < total_weight)
    {
      weight = vec[i].second;
    }
    else
    {
      weight = total_weight;
    }

    Max_Value += weight * ((double)(vec[i].first) / (vec[i].second));
    total_weight -= weight;
    if (total_weight == 0)
      break;
  }

  return Max_Value;
}

int main()
{
  std::vector<std::pair<int, int>> vec;
  int weight, value, total_size, total_weight;
  double Maximum_Value;

  std::cin >> total_size >> total_weight;

  for (int i = 0; i < total_size; i++)
  {
    std::cin >> weight >> value;
    vec.push_back(std::make_pair(weight, value));
  }
  std::cout << Efficent_Knapsack(vec, total_weight) << std::endl;

  return 0;
}
