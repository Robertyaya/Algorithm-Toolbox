#include <iostream>
#include <fstream>
#include <vector>

std::pair<int, int> ThreeWay_Partition(std::vector<int> &vec, int l, int r)
{
  std::pair<int, int> m;
  m.first = l;
  m.second = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (vec[i] < vec[l])
    {
      m.first++;
      if (vec[m.first] == vec[l]) // touch the region of m2
      {
        m.second++;

        // Triangel change
        std::swap(vec[i], vec[m.second]);
        std::swap(vec[m.second], vec[m.first]);
      }
      else
        std::swap(vec[i], vec[m.first]); // no touch the region of m2
    }
    else if (vec[i] == vec[l])
    {
      // m2 initialize
      if (m.second == l)
      {
        if (i - 1 == m.first)
          m.second = i;
        else
        {
          m.second = m.first + 1;
          std::swap(vec[i], vec[m.second]);
        }
      }
      // Update m2 value
      else
      {
        m.second++;
        std::swap(vec[i], vec[m.second]);
      }
    }
  }

  std::swap(vec[l], vec[m.first]);
  return m;
}
void ThreeWay_QuickSort(std::vector<int> &vec, int l, int r)
{
  if (l >= r)
    return;
  int k = rand() % (r - l + 1) + l;
  std::swap(vec[l], vec[k]);

  // Debug
  // for (int i = 0; i < vec.size(); i++)
  //   std::cout << vec[i] << " ";
  // std::cout << std::endl;

  std::pair<int, int> pivot = ThreeWay_Partition(vec, l, r);

  //std::cout << std::endl;

  // Debug
  // for (int i = 0; i < vec.size(); i++)
  //   std::cout << vec[i] << " ";
  // std::cout << std::endl;

  // std::cout << std::endl;

  ThreeWay_QuickSort(vec, l, pivot.first - 1);
  ThreeWay_QuickSort(vec, pivot.second + 1, r);
}
int Partition(std::vector<int> &vec, int l, int r)
{
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (vec[i] < vec[l])
    {
      j++;
      std::swap(vec[j], vec[i]);
    }
  }
  std::swap(vec[l], vec[j]);
  return j;
}
void QuickSort(std::vector<int> &vec, int l, int r)
{
  if (l >= r)
    return;
  int k = rand() % (r - l + 1) + l;
  std::swap(vec[k], vec[l]);
  int m = Partition(vec, l, r);
  QuickSort(vec, l, m - 1);
  QuickSort(vec, m + 1, r);
}

void Solve(std::vector<int> &vec)
{
  QuickSort(vec, 0, vec.size() - 1);
  //ThreeWay_QuickSort(vec, 0, vec.size() - 1);

  // Output
  for (int i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  int n;
  std::vector<int> vec;
  std::cin >> n;
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int temp;
    std::cin >> temp;
    vec.push_back(temp);
  }

  Solve(vec);
  return 0;
}
