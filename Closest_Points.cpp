#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

const int Max = 100000;

typedef struct
{
  int x;
  int y;
} Point;

void Merge(std::vector<Point> &vec, int l, int mid, int r, bool x_coor)
{
  Point point_max;

  point_max.x = 10000;
  point_max.y = 10000;

  std::vector<Point> left_vec;
  std::vector<Point> right_vec;
  left_vec.assign(vec.begin() + l, vec.begin() + mid + 1);
  right_vec.assign(vec.begin() + mid + 1, vec.begin() + r + 1);

  int left_index = 0;
  int right_index = 0;
  left_vec.push_back(point_max);
  right_vec.push_back(point_max);

  for (int i = l; i <= r; i++)
  {
    if (x_coor) // Based on x coordinate to sorting
    {
      if (left_vec[left_index].x <= right_vec[right_index].x)
      {
        vec[i] = left_vec[left_index];
        left_index++;
      }
      else if (left_vec[left_index].x > right_vec[right_index].x)
      {
        vec[i] = right_vec[right_index];
        right_index++;
      }
    }
    else // Based on y coordinate to sorting
    {
      if (left_vec[left_index].y <= right_vec[right_index].y)
      {
        vec[i] = left_vec[left_index];
        left_index++;
      }
      else if (left_vec[left_index].y > right_vec[right_index].y)
      {
        vec[i] = right_vec[right_index];
        right_index++;
      }
    }
  }
}
void MergeSort(std::vector<Point> &vec, int l, int r, bool x_coor)
{
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  MergeSort(vec, l, mid, x_coor);
  MergeSort(vec, mid + 1, r, x_coor);
  Merge(vec, l, mid, r, x_coor);
}
double Calculate_Distance(Point a, Point b)
{
  return (double)sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double BruteForce(std::vector<Point> &vec, int l, int r)
{
  double Min_distance = 0;
  for (int i = l; i <= r - 1; i++)
  {
    for (int j = i + 1; j <= r; j++)
    {
      // initialize min distance
      if (i == l && j == l + 1)
        Min_distance = Calculate_Distance(vec[i], vec[j]);
      else
      {
        if (Calculate_Distance(vec[i], vec[j]) < Min_distance)
          Min_distance = Calculate_Distance(vec[i], vec[j]);
      }
    }
  }
  return Min_distance;
}

double Min(double left, double right)
{
  if (left <= right)
    return left;
  else
    return right;
}

double ClosetDistance(std::vector<Point> &vec, int l, int r)
{
  // Represent the sub vector element is 1,2 or 3
  if (r - l <= 2)
  {
    if (r == l)
      return Max;
    else
    {
      //std::cout << "Brute: " << BruteForce(vec, l, r) << std::endl;
      return BruteForce(vec, l, r);
    }
  }
  int mid = (l + r) / 2;
  //std::cout << "mid: " << mid << std::endl;
  double Left_min = ClosetDistance(vec, l, mid);
  //std::cout << "LEft_Min: " << Left_min << std::endl;
  double Right_min = ClosetDistance(vec, mid + 1, r);
  //std::cout << "Right_Min" << Right_min << std::endl;
  return Min(Left_min, Right_min);
}

double FindStripMinimumDistance(std::vector<Point> &vec)
{
  double min_distance;
  int j;
  //std::cout << "size: " << vec.size() << std::endl;
  for (int i = 0; i < vec.size() - 1; i++)
  {
    j = i + 1;
    while (j < vec.size() && j - i <= 7)
    {
      // std::cout << "i: " << i << " "
      //           << "j: " << j << std::endl;
      if (i == 0 && j == 1)
        min_distance = Calculate_Distance(vec[i], vec[j]);
      else
      {
        if (Calculate_Distance(vec[i], vec[j]) < min_distance)
          min_distance = Calculate_Distance(vec[i], vec[j]);
      }

      j++;
    }
  }
  return min_distance;
}

double Recursive_ClosestDistance(std::vector<Point> &vec, std::vector<Point> &vec_y, int l, int r)
{
  // Base case
  if ((r - l) <= 2)
    return BruteForce(vec, l, r);

  int mid = (l + r) / 2;
  double left_min = Recursive_ClosestDistance(vec, vec_y, l, mid);
  double right_min = Recursive_ClosestDistance(vec, vec_y, mid + 1, r);
  double d = Min(left_min, right_min);

  // Find which points are in the strip O(n)
  std::vector<Point> Strip_Points_vec;
  for (int i = l; i <= r; i++)
  {
    if (abs(vec[mid].x - vec[i].x) < d)
      Strip_Points_vec.push_back(vec[i]);
  }

  // Represent d is the minimum distance
  if (Strip_Points_vec.size() == 0)
    return d;

  // Sorting base on y coordinate O(nlogn)
  //Merge(vec, l, mid, r, false); //Only use merge O(n)
  MergeSort(Strip_Points_vec, 0, Strip_Points_vec.size() - 1, false);

  // Calculate the d' O(7n)
  double d_ = FindStripMinimumDistance(Strip_Points_vec);
  return Min(d, d_);
}

void Closest_Points(std::vector<Point> &vec)
{
  std::vector<Point> vec_y(vec);
  // Soring based on x value (Merge Sort O(nlogn))
  MergeSort(vec, 0, vec.size() - 1, true);

  // Sorting based on y value first and pass into recursive, so we don't need to sorting in the recursive function
  // O(nlogn)
  MergeSort(vec_y, 0, vec_y.size() - 1, false);

  // Rescursive T(n) = 2(T/2) + O(n) + O(n) + O(nlogn)
  double min = Recursive_ClosestDistance(vec, vec_y, 0, vec.size() - 1);

  std::cout << min << std::endl;
}

int main()
{
  std::fstream fin("test.txt");
  int n;
  std::vector<Point> vec;
  std::cin >> n;
  vec.reserve(n);
  for (int i = 0; i < n; i++)
  {
    Point point_temp;
    std::cin >> point_temp.x >> point_temp.y;
    vec.push_back(point_temp);
  }

  Closest_Points(vec);
}
