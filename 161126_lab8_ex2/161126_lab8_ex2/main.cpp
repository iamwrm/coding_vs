#define N 10
#include <iostream>
#include "player.h"
using namespace std;

int main()
{
    player p1;
    while (1)
    {
        p1.ini();
        p1.show(1);

        cin.get();
    }
}