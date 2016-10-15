#include <iostream>
#include <deque>
using namespace std;
const int target = 10000;
int main ()
{
    int n;
    // Запоминаем 1-ый список в деке.
    deque <int> list1;
    cin >> n;
    while (n --)
    {
       int a;
       cin >> a;
       list1.push_back (a);
    }
    // Второй список запоминать не будем, а считать будем на лету.
    cin >> n;
    int a1, a2;
    int from_where = 3; // флаги. биты 0 и 1 откуда читать, первый список, или второй соответственно
    bool res = false;
    while (!res)
    {
       if (from_where & 1) //читаем из 1-го списка
       {
          if (list1.size ()==0)
             break;
          a1 = list1.front ();
          list1.pop_front ();
       }
       if (from_where & 2) //читаем из 2-го списка
       {
          if (n==0)
             break;
          cin >> a2;
          n --;
       }
       int sum = a1 + a2;
       from_where = sum < target ? 1 : 2; // если сумма меньше нужной, то след. читаем из 1-го списка, иначе из 2-го
       res = sum == target;
    }
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}
