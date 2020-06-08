#include <iostream>
#include <vector>
#include <algorithm>

long long int Maximum_pair_product_fast_reliable(std::vector<int> &vec)
{
  long long int result;
  int index = 0;
  int size = vec.size();
  for (int i = 1; i < size; i++)
  {
    if (vec[i] > vec[index])
      index = i;
  }
  std::swap(vec[index], vec[size - 1]);

  index = 0;
  for (int j = 1; j < size - 1; j++)
  {
    if (vec[j] > vec[index])
      index = j;
  }
  std::swap(vec[index], vec[size - 2]);
  result = (long long int)(vec[size - 1]) * vec[size - 2];
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> numbers[i];
  }

  std::cout << Maximum_pair_product_fast_reliable(numbers) << "\n";
  return 0;
}
