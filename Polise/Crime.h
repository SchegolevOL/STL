#pragma once
#include<iostream>
#include<string>
#include<map>

const std::map<size_t, std::string> crimes =
{
	{1,"проезд на красный"},
	{2,"привышение скорости"},
	{3,"езда по встречной полосе"},
	{4,"дрифт на перекрестке"},
	{5,"парковка в неположеном месте"},
	{6,"оскорбление офицера"}
};

class Crime
{
	size_t id;
	std::string plase;
public:
	size_t get_id()const
	{
		return id;
	}
	const std::string& get_plase()const
	{
		return plase;
	}
	Crime(size_t id, const std::string& plase) :id(id), plase(plase) {}

	~Crime(){}

};

std::ostream& operator << (std::ostream& os, const Crime& obj);
	
