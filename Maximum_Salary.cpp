#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

bool comparison(std::string a, std::string b)
{
  std::string a_str;
  std::string b_str;

  a_str = a + b;
  b_str = b + a;
  return std::stoi(a_str) > std::stoi(b_str);
}

std::string LargestNumber(std::vector<std::string> &vec)
{
  std::sort(vec.begin(), vec.end(), comparison);
  std::stringstream ret;
  for (size_t i = 0; i < vec.size(); i++)
  {
    ret << vec[i];
  }
  std::string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::vector<std::string> vec;
  std::fstream file("test.txt");
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    std::cin >> temp;
    vec.push_back(std::to_string(temp));
  }
  std::cout << LargestNumber(vec) << std::endl;

  return 0;
}
