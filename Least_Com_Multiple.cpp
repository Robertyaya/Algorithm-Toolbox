#include <iostream>
#include <stdio.h>

long long int Naive_LCM(int a, int b)
{
  long long int mul = std::max(a, b);
  while (true)
  {
    if (mul % a == 0 && mul % b == 0)
      break;
    mul++;
  }
  return mul;
}

long long int Fast_LCM(int a, int b)
{
  int base = std::max(a, b);
  long long int mul = 0;

  // The max one is a*b
  for (int i = 1; i <= std::min(a, b); i++)
  {
    mul = (long long)(base)*i;

    if (mul % std::min(a, b) == 0)
      break;
  }
  return mul;
}

int main()
{
  long long int Ans = 0;
  int a, b;

  while (true)
  {
    scanf("%d", &a);
    scanf("%d", &b);

    Ans = Fast_LCM(a, b);
    std::cout << Ans << std::endl;
  }

  return 0;
}
