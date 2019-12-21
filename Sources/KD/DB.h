#pragma once
#include <vector>
#include <string>

#include "Base/BaseDB.h"
#include "KDTree.h"
#include "SearchEngine.h"
#include "DBManager.h"

class DB: public BaseDB{
public:
	DB(mongocxx::v_noabi::collection conection);
	~DB();

	void add(const std::vector<double>& key, const std::string& data, BaseComporator *cmp);
	
	void set_max_containers_count(const size_t &max_containers_count);
	size_t get_max_containers_count();

	void set_kd_tree_key(std::string kd_tree_key);
	std::string get_kd_tree_key();

private:

	size_t max_containers_count = 3;
	std::string kd_tree_key;
};
