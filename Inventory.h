/*Assignment 7: Thread-safe Inventory
Written by Zubaydah Koelemeij
06/12/2022*/

#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
using namespace std;

class Inventory
{
public:
    mutex mutexLock;
    vector<string> inventoryList;
    Inventory() {}

    void addItem()
    {
        const std::lock_guard<std::mutex> lock(mutexLock);

        inventoryList.push_back("item");
    }

    void removeItem()
    {
        const std::lock_guard<std::mutex> lock(mutexLock);

        if (!inventoryList.empty())
        {
            inventoryList.pop_back();
        }
    }

    vector<string> Get() {
        return inventoryList;
    }
};