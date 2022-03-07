#include <iostream>
#include<Windows.h>
#include <array>
#include<vector>

using namespace std;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#ifdef STL_ARRAY
    std :: array<int, 6> arr = { 1,2,3,1,3,4 };
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;
#endif // STL_ARRAY
    
#ifdef STL_VECTOR
    //vector - это контенер, который хранит данные в виде динамического массива
    std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
    for (size_t i = 0; i < vec.size(); i++) cout << vec[i] << tab;
    cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.push_back(10);
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
#endif // STL_VECTOR





    return 0;
}

