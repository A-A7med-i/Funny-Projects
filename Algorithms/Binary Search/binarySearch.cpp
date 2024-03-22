#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int *numbers, int sz, int target)
{

    int low = 0;
    int high = sz - 1;

    sort(numbers, numbers + sz);

    while (high >= low)
    {

        int mid = (high + low) / 2;

        if (numbers[mid] == target)
            return mid;

        else if (numbers[mid] > target)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}