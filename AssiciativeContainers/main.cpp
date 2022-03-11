#include <iostream>
#include <Windows.h>
#include<set>
#include<map>
#include<list>
using namespace std;

#define tab "\t"

//#define STL_SET
//#define STL_MAP

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef STL_SET
	//set - уникальное дерево
	//multiset - не уникальное дерево
	std::set<int>my_set = { 50,25,75,16,32,64,80 };
	for (std::set<int>::iterator it = my_set.begin();it!=my_set.end();++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	std::multiset<int>my_mset = { 50,25,75,16,32,64,80,7,7,7,7,7 };
	for (std::multiset<int>::iterator it = my_mset.begin(); it != my_mset.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	//map - бинарное дерево поиска уникальное
	//multimap - бинарное дерево поиска не уникальное
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(1,"Monday"),
		std::pair<int, std::string>(2,"Tuesday"),
		std::pair<int, std::string>(3,"Wadnesday"),
		std::pair<int, std::string>(4,"Thursday"),//или
		{5,"Friday"},
		{6,"Saturday"}
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
		cout << it->first << tab << it->second << endl;

	std::multimap<int, std::string> m_week =
	{
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(1,"Monday"),
		std::pair<int, std::string>(2,"Tuesday"),
		std::pair<int, std::string>(3,"Wadnesday"),
		std::pair<int, std::string>(4,"Thursday"),//или
		{5,"Friday"},
		std::pair<int, std::string>(1,"Monday"),
		{6,"Saturday"}
	};
	for (std::map<int, std::string>::iterator it = m_week.begin(); it != m_week.end(); it++)
		cout << it->first << tab << it->second << endl;
#endif // STL_MAP

	std::map<std::string, std::list<std::string>> dictionary
	{

		{"splise",{"сваривание","сращивание","свадьба"}},
		{"reconnaissance",{"разведка","ознакомление","рекогносцировка"}},
		{"pencil",{"карандаш"}},
		{"haus",{"дом","палата"}}
	};
	for (std::map< std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width(20);
		cout << std::left;
		cout << it->first << " :\t";
		for (std::string i : it->second)cout << i << " , "; cout << "\b\b;\n";
	}
	
	cout << "----------------------------------------------------------" << endl;
	for (std::pair< std::string, std::list<std::string>>i: dictionary)
	{
		cout.width(20);
		cout << std::left;
		cout << i.first << " :\t";
		for (std::string j : i.second)cout << j << " , "; cout << "\b\b;\n";
	}

	return 0;
}