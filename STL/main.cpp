#include <iostream>
#include <Windows.h>
#include <array>
#include <vector>
#include<deque>
#include<list>
#include<forward_list>
using namespace std;

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_LIST
//#define STL_FORVARD_LIST




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
    try
    {
        throw "My Exaption";
        for (size_t i = 0; i < vec.size(); i++) cout << vec.at(i) << tab;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    catch (const char& e)
    {
        std::cerr << e;
    }
    catch (...)
    {

        std::cerr << "Eror";
    }
    cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;
    vec.push_back(10);
    for (size_t i = 0; i < vec.size(); i++) cout << vec.at(i) << tab; cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;
    vec.shrink_to_fit();
    for (size_t i = 0; i < vec.size(); i++) cout << vec.at(i) << tab; cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;
    vec.reserve(20);
    for (size_t i = 0; i < vec.size(); i++) cout << vec.at(i) << tab; cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;
    vec.resize(5);
    for (size_t i = 0; i < vec.size(); i++) cout << vec.at(i) << tab; cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;
    vec.assign({ 1,2,4,8,16,32,64 });

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end();it++) 
        cout << *it << tab; 
    cout << endl;

    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;
    vec.insert(vec.begin() + 5, 100);
    for (size_t i = 0; i < vec.size(); i++) cout << vec.at(i) << tab; cout << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max Size: " << vec.max_size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "\n---------------------------------------------------------" << endl;







#endif // STL_VECTOR

#ifdef STL_DEQUE
    //deque - это контенер который хранит данные в виде списка динамических массивов
    //в отличии от вектора он не переопределяет выделенную память при добовлении 
    //значение а выделяет еще одну облость памяти и связывает выделенные области 
    //памяти в список
    deque <int> deq = { 1,2,3,5,8,13,21,34 };
    deq.push_front(0);
    for (int i : deq)
        cout << i << tab;
    cout << endl;
#endif // STL_DEQUE
#ifdef STL_LIST
    std::list<int>my_list = { 1,2,3,4,5,6,7,8,9,10 };
    int data;
    int index;

    for (int i : my_list)cout << i<<tab; cout << endl;
    cout << "В ведите значение : "; cin >> data;
    cout << "В индекс : "; cin >> index;
    std::list<int>::iterator it;

    if (index < my_list.size() / 2)
    {
        it = my_list.begin();
        for (size_t i = 0; i < index; i++)
            it++;
    }
    else 
    {
        it = my_list.end();
        for (size_t i = index+1; i <= my_list.size(); i++)
            it--;
    }
    my_list.insert(it, data);
    for (int i : my_list)cout << i << tab; cout << endl;
#endif // STL_LIST
#ifdef STL_FORVARD_LIST
    forward_list<int>my_f_list = { 1,2,3,5,8,13,21,34 };
    int data;
    int index;
    for (int i : my_f_list)cout << i << tab; cout << endl;
    cout << "В ведите значение : "; cin >> data;
    cout << "В индекс : "; cin >> index;
    std::forward_list<int>::iterator it = my_f_list.begin();
    for (size_t i = 0; i < index-1; i++)it++;
    my_f_list.insert_after(it,data);
    for (int i : my_f_list)cout << i << tab; cout << endl;
#endif // STL_FORVARD_LIST



    return 0;
}

