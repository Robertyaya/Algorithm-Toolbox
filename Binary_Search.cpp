#include <iostream>
#include <vector>
#include <fstream>

int Binary_Search(std::vector<int> &a_vec, int low, int high, int key)
{
  // Can't find the key in a_vec
  if (high < low)
    return -1;
  int mid = low + (high - low) / 2;
  if (key == a_vec[mid])
    return mid;
  else if (key < a_vec[mid])
    return Binary_Search(a_vec, low, mid - 1, key);
  else
    return Binary_Search(a_vec, mid + 1, high, key);
}

void solve(std::vector<int> &a_vec, std::vector<int> &b_vec)
{
  std::vector<int> index;
  index.reserve(b_vec.size());

  for (int i = 0; i < b_vec.size(); i++)
  {
    // Binary Search
    int key = b_vec[i];
    int high_index = a_vec.size() - 1;
    int low_index = 0;
    int ind = Binary_Search(a_vec, low_index, high_index, key);
    index.push_back(ind);
  }

  for (int i = 0; i < index.size(); i++)
    std::cout << index[i] << " ";
  std::cout << std::endl;
}

// The goal in this code is to implement the binary search algorithm
int main()
{
  int n, k;
  std::vector<int> a_vec;
  std::vector<int> b_vec;

  std::cin >> n;
  a_vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int a;
    std::cin >> a;
    a_vec.push_back(a);
  }

  std::cin >> k;
  b_vec.reserve(k);
  for (int i = 0; i < k; i++)
  {
    int b;
    std::cin >> b;
    b_vec.push_back(b);
  }

  solve(a_vec, b_vec);
}
