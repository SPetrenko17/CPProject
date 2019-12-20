#pragma once

#include <vector>

#include <bsoncxx/builder/basic/sub_document.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "Base/BaseContainer.h"


class Container:public BaseContainer{
public:

	Container(const std::string &id_);

	void save(bsoncxx::builder::basic::sub_document &document);
	void load(const bsoncxx::v_noabi::document::element& document_reader);

	std::vector<double> get_key();
	std::string get_data();

	void set_key(const std::vector<double>& key_);
	void set_data(const std::string& data_);

private:

	std::vector<double> key;
	std::string data;
};
