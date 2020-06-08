#include <iostream>
#include <stdio.h>
#include <vector>

std::vector<int> Max_Num_Prizes(int n)
{
  int total_sum = 0;
  int i = 1;
  std::vector<int> output_vec;
  while (total_sum < n)
  {
    total_sum += i;
    if (n - total_sum > i || n == total_sum)
    {
      output_vec.push_back(i);
    }
    else
    {
      total_sum -= i;
    }

    i++;
  }
  return output_vec;
}

int main()
{
  int n;
  std::vector<int> output;

  std::cin >> n;
  output = Max_Num_Prizes(n);
  std::cout << output.size() << std::endl;
  for (int i = 0; i < output.size(); i++)
    std::cout << output[i] << " ";
  std::cout << std::endl;

  return 0;
}
