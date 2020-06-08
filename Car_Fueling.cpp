#include <iostream>
#include <fstream>
#include <vector>

int MinRefills(std::vector<int> vec, int Max_Distance, int Fulltank_Distance)
{
  vec.push_back(Max_Distance);
  int current_index = 0;
  int fuel_index = 0;
  int Num_Fuil = 0;

  for (int i = 0; i < vec.size(); i++)
  {
    // Car can't reach the next fuel station
    if (vec[i + 1] - vec[i] > Fulltank_Distance)
      return -1;

    if (vec[i] - vec[fuel_index] >= Fulltank_Distance)
    {
      Num_Fuil++;
      if (vec[i] - vec[fuel_index] == Fulltank_Distance)
        fuel_index = i;
      else
        fuel_index = i - 1;
    }
  }
  return Num_Fuil;
}

int main()
{
  // Input file initialize
  std::ifstream file("test.txt");
  std::vector<int> vec;
  int d, m, n, temp;
  int Min_Refills;
  std::cin >> d >> m >> n;
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> temp;
    vec.push_back(temp);
  }

  Min_Refills = MinRefills(vec, d, m);
  std::cout << Min_Refills << std::endl;

  return 0;
}
