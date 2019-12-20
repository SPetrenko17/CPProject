#include <string>
#include <vector>

#include "Base/BaseSearchEngine.h"
#include "KDTree.h"
#include "DBManager.h"
#include "SearchEngine.h"


SearchEngine::SearchEngine(const KDTree* data_structure, const DBManager* db_manager):
	BaseSearchEngine(data_structure, db_manager){};

std::vector<std::string> SearchEngine::get_best_match(const std::vector<double> &key){
	return(((KDTree*)data_structure)->neighbor_search(key));
}
/*
std::vector<std::string> SearchEngine::range_search(const std::vector<double> &key){
	return(((KDTree*)data_structure)->neighbor_search(key));
}*/