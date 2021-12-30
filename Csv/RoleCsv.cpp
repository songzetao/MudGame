#include "RoleCsv.h"
#include "../Engine/Utility.h"

map<int, CRole*>* RoleCsv::makeAllRoleMap()
{
	map<int, CRole*>* res = new map<int, CRole*>();
	for (auto it = csv_data->begin(); it != csv_data->end(); it++) {
		CRole* role = new CRole();
		auto vs = it->second;
		role->id = it->first;

		role->name = convStrCell("name", vs);
		role->showname = convStrCell("showname", vs);
		res->insert(pair<int, CRole*>(role->id, role));
	}
	return res;
}

map<int, CRole*>* RoleCsv::makeRoleMap()
{
    return new map<int, CRole*>();
}
