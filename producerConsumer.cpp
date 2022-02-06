#include <iostream>
using namespace std;

#define N 5
int count = 0;

void producer()
{
  int item;
  while (true)
  {
    item = produce_item();
    while (count = N)
      insert_item(item);
    count = count + 1;
    if (count == 1)
  }
}

void consumer()
{
  int item;
  while (true)
  {
    while (count == 0)
      item = remove_item()
          count = count - 1;
    if (count == N - 1)
    }
}