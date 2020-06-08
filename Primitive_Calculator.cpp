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
void Primitive_Calculator_DP(int number)
{
  // a+1, 3a, 4a
  std::vector<int> DP;
  std::vector<int> DP_process;
  DP.reserve(number);
  for (int i = 1; i <= number; i++)
  {
    // initialize
    if (i == 1)
    {
      DP.push_back(0); // initialize DP[0]
      DP.push_back(0); // initialzie DP[1]
    }
    else
    {
      std::vector<int> ans;
      ans.reserve(3);
      //std::cout << i << std::endl;
      if (i - 1 >= 1)
        ans.push_back(DP.at(i - 1) + 1);
      if (i % 2 == 0)
        ans.push_back(DP.at(i / 2) + 1);
      if (i % 3 == 0)
        ans.push_back(DP.at(i / 3) + 1);

      DP.push_back(Min(ans));
    }
  }

  std::cout << DP[DP.size() - 1] << std::endl;

  // Fill the DP_process
  int index = DP.size() - 1;
  int DP_value = DP[DP.size() - 1];
  DP_process.push_back(index);
  while (index > 1)
  {
    // Find the next DP_value
    for (int i = index - 1; i >= 1; i--)
    {
      if (DP[i] == DP_value - 1)
      {
        // Check
        if (i == index - 1 || (index % 3 == 0 && i == index / 3) || (index % 2 == 0 && i == index / 2))
        {
          index = i;
          DP_value = DP[index];
          DP_process.push_back(index);
          break;
        }
      }
    }
  }

  for (int i = DP_process.size() - 1; i >= 0; i--)
    std::cout << DP_process[i] << " ";

  std::cout << std::endl;
}

void Primitive_Calculator_Greedy(int number)
{
  std::vector<int> Greedy;

  while (number >= 1)
  {
    Greedy.push_back(number);
    if (number % 3 == 0)
      number /= 3;
    else if (number % 2 == 0)
      number /= 2;
    else
      number -= 1;
  }
  std::cout << Greedy.size() - 1 << std::endl;
  for (int i = Greedy.size() - 1; i >= 0; i--)
    std::cout << Greedy[i] << " ";
  std::cout << std::endl;
}
int main()
{
  int number;
  std::cin >> number;
  //Primitive_Calculator_Greedy(number);
  Primitive_Calculator_DP(number);
}
