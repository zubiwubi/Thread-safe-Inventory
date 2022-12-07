/*Assignment 7: Thread-safe Inventory
Written by Zubaydah Koelemeij
06/12/2022*/


#include "Inventory.h"

int main() 
{
    Inventory inventory;

    thread T1(&Inventory::addItem, &inventory);
    thread T2(&Inventory::addItem, &inventory);
    thread T3(&Inventory::removeItem, &inventory);
    thread T4(&Inventory::addItem, &inventory);


    T1.join();
    T2.join();
    T3.join();
    T4.join();

    auto list = inventory.Get();

    for (auto i : list) 
    {
        cout << "Net: " << i << endl;
    }
}