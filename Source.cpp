#include <iostream>
#include <ostream>
#include <malloc.h>
#include <cmath>

using namespace std;

class Square
{
public:

    int operator()(const int number) const 
    {
        return number * number * number;
    }
};

class Massif
{
public:

    int* operator()(int arr[], int size, const int number) const 
    {

        int* mass = new int[size];
        int j = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] <= number)
                continue;

            mass[j] = arr[i];
            j++;
        }

        int* cutedMass = new int[j];
        for (int i = 0; i < j; i++)
        {
            cutedMass[i] = mass[i];
        }

        return cutedMass;
    }
};

class DeleteDiapason
{
public:
    int* operator()(int num_arr[], int start, int end) const 
    {

        if (start > end)
            return nullptr;

        int* range = new int[end - start];
        int j = 0;

        for (int i = start; i < end; i++)
        {
            range[j] = num_arr[i];
            j++;
        }

        return range;
    }
};

int main()
{
    Square square_num;
    cout << square_num(4) << endl;

    Massif array;
    int temp[15] = { 8,6,3,5,9,1,2,4,7,2,9,4,1,2,3 };
    int* arr = array(temp, 15, 5);

    for (int i = 0; i < sizeof(arr); i++)
        cout << arr[i] << " ";

    cout << endl;
    DeleteDiapason diapason;
    int* del = diapason(temp, 2, 8);

    for (int i = 0; i < 6; i++)
        cout << del[i] << " ";

    return 0;
}