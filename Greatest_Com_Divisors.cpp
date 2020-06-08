#include <iostream>
#include <stdio.h>
#include <iomanip>

int NaiveGCD(int a, int b)
{
  int best = 0;
  for (int i = 1; i <= std::min(a, b); i++)
  {
    if (a % i == 0 && b % i == 0)
      best = i;
  }
  return best;
}

// GCD(a,b) = GCD(a',b) = GCD(a,b')
int EuclidGCD(int a, int b)
{
  int remainder;
  if (b == 0)
    return a;
  remainder = a % b;
  return EuclidGCD(b, remainder);
}

int main()
{
  int a, b, best;
  std::cin >> a >> b;
  std::cout << std::fixed << std::setprecision(5) << EuclidGCD(a, b) << std::endl;
  return 0;
}
