#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int Partition(std::vector<int> &vec, int l, int r)
{
  int pivot = vec[l]; // pivot
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (vec[i] < pivot)
    {
      j++;
      std::swap(vec[j], vec[i]);
    }
  }
  std::swap(vec[l], vec[j]);
  return j; // pivot intdex
}

void RandomizedQuickSort(std::vector<int> &vec, int l, int r)
{
  if (l >= r)
    return;
  int k = (rand() % (r - l + 1)) + l; // random number between l~r
  std::swap(vec[l], vec[k]);
  int m = Partition(vec, l, r);
  RandomizedQuickSort(vec, l, m - 1);
  RandomizedQuickSort(vec, m + 1, r);
}

int Efficient_Majority_Element(std::vector<int> &vec)
{
  if (vec.size() == 1)
    return 1;

  // Sorting first (Quick sort) O(nlogn)
  RandomizedQuickSort(vec, 0, vec.size() - 1);

  // for (int i = 0; i < vec.size(); i++)
  //   std::cout << vec[i] << " ";
  // std::cout << std::endl;

  // O(n)
  int j = 0;
  int majority_count = 0;
  int max_value;
  for (int i = 1; i < vec.size(); i++)
  {
    // Update the majority count and j
    if (vec[i] != vec[j] || i == vec.size() - 1)
    {
      if (i == vec.size() - 1)
        i++;
      if (i - j > majority_count)
      {
        majority_count = i - j;
        max_value = vec[j];
      }
      j = i;
    }
  }
  //std::cout << "majority: " << max_value << std::endl;

  if (majority_count > vec.size() / 2)
    return 1;
  else
    return 0;
}

std::pair<int, int> Merge(std::pair<int, int> left_pair, std::pair<int, int> right_pair)
{
  if (left_pair.first == -1 && right_pair.first == -1)
    return left_pair;
  else if (left_pair.first != -1 && right_pair.first == -1)
    return left_pair;
  else if (left_pair.first == -1 && right_pair.first != -1)
    return right_pair;
  else
  {
    if (left_pair.first == right_pair.first)
    {
      left_pair.second += right_pair.second;
      return left_pair;
    }
    else
    {
      if (left_pair.second > right_pair.second)
        return left_pair;
      else if (left_pair.second < right_pair.second)
        return right_pair;
      else
      {
        left_pair.first = -1;
        return left_pair;
      }
    }
  }
}

std::pair<int, int> Divide_and_Conquer(std::vector<int> &vec, int l, int r)
{
  // Base case
  if (l == r)
  {
    std::pair<int, int> pa;
    pa.first = vec[l];
    pa.second = 1;
    return pa;
  }

  // Calculate the mid
  int mid = l + ((r - l) / 2);
  std::pair<int, int> left_majority = Divide_and_Conquer(vec, l, mid);
  std::pair<int, int> right_majority = Divide_and_Conquer(vec, mid + 1, r);

  // // Debug
  std::cout << "Left: " << left_majority.first << " " << left_majority.second << std::endl;
  std::cout << "Right: " << right_majority.first << " " << right_majority.second << std::endl;

  std::pair<int, int> majority = Merge(left_majority, right_majority);

  // Debug
  // std::cout << majority.first << " " << majority.second << std::endl;
  // std::cout << std::endl;
  return majority;
}

int DivideConquer_Majority_Element(std::vector<int> &vec)
{
  std::pair<int, int> pai = Divide_and_Conquer(vec, 0, vec.size() - 1);
  if (pai.first == -1)
    return 0;
  else if (pai.second < vec.size() / 2)
    return 0;
  else
    return 1;
}

int Naive_Majority_Element(std::vector<int> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    int count = 0;
    int current_element = vec[i];
    for (int j = 0; j < vec.size(); j++)
    {
      if (vec[j] == current_element)
      {
        count++;
      }
    }
    if (count > vec.size() / 2)
      return 1;
  }
  return 0;
}
int main()
{
  std::vector<int> vec;
  int n;
  std::cin >> n;
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int temp;
    std::cin >> temp;
    vec.push_back(temp);
  }

  int flag = Efficient_Majority_Element(vec);
  int flag2 = Naive_Majority_Element(vec);
  std::cout << flag << std::endl;
  // std::cout << flag2 << std::endl;
}
