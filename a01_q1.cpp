#include <iostream>
#include <list>
using namespace std;

void pushBackRandom(list<int> &inputList, int quantity)
{
    for (int i = 0; i != quantity; ++i)
    {
        int randNum = rand() % 100 + 1;
        inputList.push_back(randNum);
    }
}

void quickSort(list<int> &inputList)
{
    inputList.sort(greater<int>());
}

void printList(list<int> &inputList, list<int>::iterator it)
{
    for (it = inputList.begin(); it != inputList.end(); ++it)
    {
        if (it == inputList.begin())
        {
            cout << *it;
        }
        else
        {
            cout << " " << *it;
        }
    }
    cout << endl;
}

int main()
{
    list<int> randomList(0, 0);
    list<int>::iterator it;
    pushBackRandom(randomList, 10);
    list<int> randomListCopy = randomList;
    quickSort(randomListCopy);
    cout << "Originally created list:" << endl;
    printList(randomList, it);
    cout << "Sorted list:" << endl;
    printList(randomListCopy, it);
    return 0;
}