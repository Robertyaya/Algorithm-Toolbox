#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

long long Max_Adver_Revenue(std::vector<int> &vec_a, std::vector<int> &vec_b)
{
  long long Revenue = 0;

  // Sorting first
  std::sort(vec_a.begin(), vec_a.end());
  std::sort(vec_b.begin(), vec_b.end());

  for (int i = 0; i < vec_a.size(); i++)
  {
    Revenue += vec_a[i] * vec_b[i];
  }
  return Revenue;
}

int main()
{
  std::fstream file("test.txt");
  int size;
  std::vector<int> vec_a, vec_b;
  std::cin >> size;
  vec_a.reserve(size);
  vec_b.reserve(size);

  // Read the data
  for (int i = 0; i < size; i++)
  {
    int temp_a;
    std::cin >> temp_a;
    vec_a.push_back(temp_a);
  }
  for (int i = 0; i < size; i++)
  {
    int temp_b;
    std::cin >> temp_b;
    vec_b.push_back(temp_b);
  }

  std::cout << Max_Adver_Revenue(vec_a, vec_b) << std::endl;

  return 0;
}
