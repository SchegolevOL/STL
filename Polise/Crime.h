#pragma once
#include<iostream>
#include<string>
#include<map>

const std::map<size_t, std::string> crimes =
{
	{1,"������ �� �������"},
	{2,"���������� ��������"},
	{3,"���� �� ��������� ������"},
	{4,"����� �� �����������"},
	{5,"�������� � ����������� �����"},
	{6,"����������� �������"}
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
	
