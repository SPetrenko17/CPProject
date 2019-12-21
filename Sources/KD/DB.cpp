#include "Base/BaseDB.h"
#include "KDTree.h"
#include "SearchEngine.h"
#include "Base/BaseComporator.h"
#include "DBManager.h"
#include "DB.h"


DB::DB(mongocxx::v_noabi::collection collection){

	db_manager = new DBManager(collection);

	if(kd_tree_key.empty()){
		data_structure = (KDTree*)db_manager->get_free_container();
		kd_tree_key = data_structure->id;
	}
	else{
		data_structure = (KDTree*)db_manager->get_container(kd_tree_key);
	}

	((KDTree*)data_structure)->db_manager = db_manager;
	((KDTree*)data_structure)->max_containers_count = max_containers_count;
	search_engine = new SearchEngine((KDTree*)data_structure, (DBManager*)db_manager);
}

DB::~DB(){
	delete db_manager;
	delete data_structure;
	delete search_engine;	
}

void DB::add(const std::vector<double>& key, const std::string& data, BaseComporator *cmp){
	((KDTree*)data_structure)->add(key, data, cmp);
}

void DB::set_max_containers_count(const size_t &max_containers_count_){
	max_containers_count = max_containers_count_;
}

size_t DB::get_max_containers_count(){
	return max_containers_count;
}

void DB::set_kd_tree_key(std::string kd_tree_key_){
	kd_tree_key = kd_tree_key_;
}

std::string DB::get_kd_tree_key(){
	return kd_tree_key;
}