#include <iostream>
#include <vector>
#include <fstream>

int Partition(std::vector<int> &vec, int l, int m, int r)
{
  int index = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (vec[i] <= vec[l])
    {
      index++;
      std::swap(vec[index], vec[i]);
    }
  }
  std::swap(vec[l], vec[index]);
  return index;
}
void Random_QuickSort(std::vector<int> &vec, int l, int r)
{
  if (l >= r)
    return;
  int m = (rand() % (r - l + 1)) + l;
  std::swap(vec[l], vec[m]);
  int pivot = Partition(vec, l, m, r);
  Random_QuickSort(vec, l, pivot - 1);
  Random_QuickSort(vec, pivot + 1, r);
}

int Binary_Search(std::vector<int> &vec, int l, int r, int key)
{
  if (l > r) // represent can't find the key
    return l - 1;
  int mid = (l + r) / 2;

  if (vec[mid] == key)
    return mid;
  else if (key < vec[mid])
    return Binary_Search(vec, l, mid - 1, key);
  else
    return Binary_Search(vec, mid + 1, r, key);
}

// Total O(4nlogn) = O(nlogn)
void Efficient_Method(std::vector<std::pair<int, int>> &seg, std::vector<int> &pots)
{
  std::vector<int> start_points_vec;
  std::vector<int> end_points_vec;
  std::vector<int> result;

  int index;

  start_points_vec.reserve(seg.size());
  end_points_vec.reserve(seg.size());
  result.reserve(pots.size());

  for (int i = 0; i < seg.size(); i++)
  {
    start_points_vec.push_back(seg[i].first);
    end_points_vec.push_back(seg[i].second);
  }

  // Sorting start_points_vec O(nlogn)
  Random_QuickSort(start_points_vec, 0, start_points_vec.size() - 1);
  // Sorting end_points_vec O(nlogn)
  Random_QuickSort(end_points_vec, 0, end_points_vec.size() - 1);

  //Search the points, return the value which bigger then key
  // Total O(2nlogn);
  for (int i = 0; i < pots.size(); i++)
  {
    int count = 0;

    // Find the start vector
    int key_index = Binary_Search(start_points_vec, 0, start_points_vec.size() - 1, pots[i]);
    if (key_index < 0)
      key_index = 0;
    if (start_points_vec[key_index] == pots[i])
    {
      // Find the "upper bound" of same value
      while (start_points_vec[key_index] == pots[i])
      {
        key_index++;
      }
      count = start_points_vec.size() - key_index;
    }
    else if (start_points_vec[key_index] > pots[i])
      count = start_points_vec.size() - key_index;
    else
      count = start_points_vec.size() - key_index - 1;

    // Find the end vector
    key_index = Binary_Search(end_points_vec, 0, end_points_vec.size() - 1, pots[i]);
    if (key_index < 0)
      key_index = 0;

    if (end_points_vec[key_index] == pots[i])
    {
      // Find the "lower bound" of the same value
      while (end_points_vec[key_index] == pots[i])
      {
        key_index--;
      }
      count += (key_index + 1);
    }
    else if (end_points_vec[key_index] < pots[i])
      count += (key_index + 1);
    else
      count += key_index;

    result.push_back(start_points_vec.size() - count);
  }

  for (int i = 0; i < result.size(); i++)
    std::cout << result[i] << " ";
  std::cout << std::endl;
}

// O(n^2)
void Naive_Method(std::vector<std::pair<int, int>> &seg, std::vector<int> &pots)
{
  std::vector<int> count_vec;
  count_vec.reserve(pots.size());
  int count = 0;
  for (int i = 0; i < pots.size(); i++)
  {
    for (int j = 0; j < seg.size(); j++)
    {
      if (pots[i] >= seg[j].first && pots[i] <= seg[j].second)
        count++;
    }
    count_vec.push_back(count);
    count = 0;
  }

  // Print the answer
  for (int i = 0; i < count_vec.size(); i++)
    std::cout << count_vec[i] << " ";
  std::cout << std::endl;
}
int main()
{
  std::vector<std::pair<int, int>> segments;
  std::vector<int> points;
  int s, p;
  std::cin >> s >> p;
  segments.reserve(s);
  points.reserve(p);

  for (int i = 0; i < s; i++)
  {
    int l, r;
    std::pair<int, int> temp_pair;
    std::cin >> l >> r;
    temp_pair = std::make_pair(l, r);
    segments.push_back(temp_pair);
  }

  for (int i = 0; i < p; i++)
  {
    int point;
    std::cin >> point;
    points.push_back(point);
  }

  Efficient_Method(segments, points);

  return 0;
}
