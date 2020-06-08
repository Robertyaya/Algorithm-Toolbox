#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool comparison(std::pair<int, int> &a, std::pair<int, int> &b)
{
  return a.first < b.first;
}

std::vector<int> Collecting_Signatures(std::vector<std::pair<int, int>> &vec)
{
  // Sorting first
  std::sort(vec.begin(), vec.end(), comparison);
  bool base_flag = true;
  std::vector<int> output;
  int upper_bound, lower_bound;

  lower_bound = vec[0].first;
  upper_bound = vec[0].second;

  for (int i = 1; i < vec.size(); i++)
  {
    if (vec[i].first > upper_bound)
    {
      output.push_back(upper_bound);
      lower_bound = vec[i].first;
      upper_bound = vec[i].second;
    }
    else
    {
      // Update the lower bound and upper bound
      if (vec[i].first > lower_bound)
        lower_bound = vec[i].first;
      if (vec[i].second < upper_bound)
        upper_bound = vec[i].second;
    }

    // The last element
    if (i == vec.size() - 1)
      output.push_back(upper_bound);
  }
  return output;
}

int main()
{
  std::fstream file("test.txt");
  std::vector<std::pair<int, int>> vec_segment;
  std::vector<int> Series;

  int size;
  std::cin >> size;

  for (int i = 0; i < size; i++)
  {
    int a, b;
    std::cin >> a >> b;
    vec_segment.push_back(std::make_pair(a, b));
  }

  Series = Collecting_Signatures(vec_segment);

  std::cout << Series.size() << std::endl;
  for (int i = 0; i < Series.size(); i++)
  {
    std::cout << Series[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
