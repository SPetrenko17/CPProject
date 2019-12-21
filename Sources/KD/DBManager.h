#pragma once

#include <string>
#include <memory>

#include <bsoncxx/builder/stream/document.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "Base/BaseDBManager.h"
#include "Base/BaseContainer.h"
#include "Container.h"

class DBManager: public BaseDBManager{
public:

	DBManager(mongocxx::v_noabi::collection collection_);

	void save_container(BaseContainer *container_ptr);

	BaseContainer* get_container(const std::string &id);
	BaseContainer* get_free_container();

private:

	mongocxx::v_noabi::collection collection;
};
