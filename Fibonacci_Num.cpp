#include <iostream>
#include <vector>
#include <stdio.h>

// Not efficient algorithm due to recursive
long long FibRecurs(long long N)
{
  if (N == 0)
    return 0;
  else if (N == 1)
    return 1;
  else
  {
    return FibRecurs(N - 1) + FibRecurs(N - 2);
  }
}

// More efficient algorithm
long long FibList(long long N)
{
  std::vector<long long int> vec;
  vec.reserve(N + 1);
  vec.push_back(0);
  vec.push_back(1);

  if (N > 1)
  {
    for (int i = 2; i <= N; i++)
    {
      vec[i] = vec[i - 1] + vec[i - 2];
    }
  }

  return vec[N];
}

int Fiblist_mod(long long n, int m)
{
  // Find the Pisano period when mod m
  std::vector<long long> Pis_vec;
  int Pisano_period_num;

  // Vector initialize
  Pis_vec.push_back(0);
  Pis_vec.push_back(1);
  int count = 2;

  while (true)
  {
    //Update the next Pisano_Number vector
    Pis_vec.push_back((Pis_vec[count - 1] + Pis_vec[count - 2]) % m);

    if (Pis_vec[count - 1] == 0 && Pis_vec[count] == 1)
    {
      Pis_vec.pop_back();
      Pis_vec.pop_back();
      break;
    }

    count++;
  }
  Pisano_period_num = Pis_vec.size();
  return Pis_vec[n % Pisano_period_num];
}

// F0+F1+....Fn
int Last_Digit_Fib_sum(long long n)
{
  // Find the Pisano period when mod 10
  std::vector<long long> Pis_vec;
  long long sum = 0;

  Pis_vec.push_back(0);
  Pis_vec.push_back(1);

  for (int i = 2; i <= n; i++)
  {
    // Update Pis vector
    Pis_vec.push_back((Pis_vec[i - 1] + Pis_vec[i - 2]) % 10);
  }
  for (int i = 0; i < Pis_vec.size(); i++)
  {
    sum += Pis_vec[i];
  }
  return sum % 10;
}

// Fm + Fm+1 + Fm+2 + ... Fn
// m<=n
int Last_Digit_Fib_sum2(long long m, long long n)
{
  // Find the Pisano period when mod 10
  std::vector<long long> Pis_vec;
  long long sum = 0;

  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  Pis_vec.push_back(0);
  Pis_vec.push_back(1);

  for (int i = 2; i <= n; i++)
  {
    // Update Pis vector
    Pis_vec.push_back((Pis_vec[i - 1] + Pis_vec[i - 2]) % 10);
  }
  for (int i = m; i < Pis_vec.size(); i++)
  {
    sum += Pis_vec[i];
  }
  return sum % 10;
}

int Last_Digit_Fib_SquareSum(long long n)
{
  // Find the Pisano period when mod 10
  std::vector<long long> Pis_vec;
  long long size;
  long long sum = 0;

  Pis_vec.push_back(0);
  Pis_vec.push_back(1);

  int count = 2;
  while (true)
  {
    // Update Pis vector
    Pis_vec.push_back((Pis_vec[count - 1] + Pis_vec[count - 2]) % 10);

    // Find the period
    if (Pis_vec[count - 1] == 0 && Pis_vec[count] == 1)
    {
      Pis_vec.pop_back();
      Pis_vec.pop_back();
      break;
    }
    count++;
  }

  // Calculate the square sum of vector
  size = Pis_vec.size();
  int remainder = n % size;

  sum = Pis_vec[remainder] * (Pis_vec[remainder] + Pis_vec[remainder - 1]);

  return sum % 10;
}

int main()
{
  //====== Fibonacci num, enter the n and calculate the Fn =======//
  // long long N, Fn;

  // while (true)
  // {
  //   scanf("%lld", &N);

  //   // Due to the vector is begin in zero
  //   Fn = FibList(N);
  //   std::cout << "Fn= " << Fn << std::endl;
  // }

  // return 0;

  // ===== Fibonacci num, enter n and m to calculate the remainder of Fn when divided by m ========//
  // long long int n;
  // int m, remainder;
  // std::cin >> n >> m;
  // remainder = Fiblist_mod(n, m);
  // std::cout << remainder << std::endl;

  // return 0;

  // ====== Last Digit of the Sum of Fibonacci Numbers ======//
  // Task. Given an integer n, find the last digit of the sum F0+F1+...+Fn;
  // long long int n, m;
  // int last_digit;
  // std::cin >> m >> n;
  // std::cout << Last_Digit_Fib_sum2(m, n) << std::endl;

  // return 0;

  //======= Last Digit of the Sum of Squares of Fibonacci Numbers
  long long int n;
  int last_digit;
  std::cin >> n;
  std::cout << Last_Digit_Fib_SquareSum(n) << std::endl;
  return 0;
}
