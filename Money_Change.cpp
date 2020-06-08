#include <iostream>
#include <vector>

int Money_Change(int money)
{
  int max_coin = 10;
  int med_coin = 5;
  int min_coin = 1;
  int coin_num = 0;
  while (money > 0)
  {
    if (money >= max_coin)
    {
      money -= max_coin;
      coin_num++;
    }
    else if (money >= med_coin)
    {
      money -= med_coin;
      coin_num++;
    }
    else
    {
      money -= min_coin;
      coin_num++;
    }
  }
  return coin_num;
}

int main()
{
  int money;
  std::cin >> money;
  std::cout << Money_Change(money) << std::endl;

  return 0;
}
