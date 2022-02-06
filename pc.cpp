#include <iostream>

using namespace std;
#define BUFFERSIZE 3

int itemsCount = 0, x = 0;
void producer();
void consumer();

int main()
{
  cout << "1. Producer" << endl;
  cout << "2. Consumer" << endl;
  cout << "3. Exit" << endl;

  int choice;
  while (true)
  {
    cout << "Enter your choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
      producer();
      break;
    case 2:
      consumer();
      break;
    case 3:
      exit(0);
      break;
    }
  }

  return 0;
}

void producer()
{

  if (itemsCount >= BUFFERSIZE)
  {
    cout << "Buffer is full!" << endl;
    return;
  }
  itemsCount++;
  x++;
  cout << "Added item " << x << " by producer." << endl;
}

void consumer()
{
  if (itemsCount <= 0)
  {
    cout << "Buffer is empty!" << endl;
    return;
  }

  cout << "Removed item " << x << " by consumer." << endl;
  itemsCount--;
  x--;
  cout << "Consumer" << endl;
}