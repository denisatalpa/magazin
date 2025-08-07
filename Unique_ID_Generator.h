#pragma once
#include <set>

class Unique_ID_Generator
{
private:
	static Unique_ID_Generator* instance;

	std::set<int> ID_folosite;
	std::set<int> ID_refolosibile;
	Unique_ID_Generator() {}

public:
	static Unique_ID_Generator* get_instance();
	~Unique_ID_Generator();

	int generate_ID();
	void delete_ID(int ID);
};