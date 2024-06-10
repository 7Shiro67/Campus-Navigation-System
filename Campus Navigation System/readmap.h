#ifndef READ_MAP_H
#define READ_MAP_H
#include "my_map_define.h"

status import_M_map(AMgraph* G, std::vector<std::string> v_s);

status import_L_map(ALgraph* G, std::vector<std::string> v_s);

status export_M_map(AMgraph* G);

status export_L_map(ALgraph* G);

status import_introduction(std::unordered_map<std::string, std::string>& introduction);

#endif // !READ_MAP_H
