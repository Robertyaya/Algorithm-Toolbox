#include <iostream>
#include <vector>
#include <fstream>

const int Max = 10000000;

void Merge(std::vector<int> &vec, int l, int mid, int r, int &count)
{
  std::vector<int> left_vec;
  std::vector<int> right_vec;
  left_vec.assign(vec.begin() + l, vec.begin() + mid + 1);
  right_vec.assign(vec.begin() + mid + 1, vec.begin() + r + 1);

  left_vec.insert(left_vec.end(), Max);
  right_vec.insert(right_vec.end(), Max);

  int index_left = 0;
  int index_right = 0;
  for (int i = l; i <= r; i++)
  {
    if (left_vec[index_left] <= right_vec[index_right])
    {
      vec[i] = left_vec[index_left];
      index_left++;
    }
    else
    {
      vec[i] = right_vec[index_right];
      index_right++;

      if (left_vec[index_left] != Max)
      {
        // Count the inversion num
        for (int j = index_left; j < left_vec.size() - 1; j++)
        {
          if (left_vec[j] > right_vec[index_right - 1])
            count++;
        }
      }
    }
  }
}
void MergeSort(std::vector<int> &vec, int l, int r, int &count)
{
  if (l >= r)
    return;
  else
  {
    int mid = (l + r) / 2;
    MergeSort(vec, l, mid, count);
    MergeSort(vec, mid + 1, r, count);
    Merge(vec, l, mid, r, count);
  }
}
void Number_Inversion(std::vector<int> &vec)
{
  int count = 0;
  MergeSort(vec, 0, vec.size() - 1, count);

  std::cout << count << std::endl;
}

int main()
{
  std::fstream fin("test.txt");
  std::vector<int> vec;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    std::cin >> temp;
    vec.push_back(temp);
  }
  Number_Inversion(vec);
}
