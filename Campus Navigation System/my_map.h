#ifndef MY_MAP_H
#define MY_MAP_H
#include "my_map_define.h"

status create_M_map(AMgraph*& G);
status create_L_map(ALgraph*& G);
status check_map_null(void* G);
status show_M_map(const AMgraph* G);
status show_L_map(const ALgraph* G);
status update_map_m_size(AMgraph* G);
status update_map_l_size(ALgraph* G);
status find_pos_node(AMgraph* G, const std::string s,int& i);
status find_pos_node(ALgraph* G, const std::string s,int& i);
status change_M_node(AMgraph* G, const std::string des_str, const int& i);
status change_L_node(ALgraph* G, const std::string des_str, const int& i);
status insert_M_node(AMgraph* G, const node& src);
status insert_L_node(AMgraph* G, const node& src);
status change_M_edge(AMgraph* G, const edge& src, const int& start, const int& end);
status change_L_edge(ALgraph* G, const edge& src, const int& start, const int& end);
status delete_M_edge(AMgraph* G, const int& start, const int& end);
status delete_L_edge(ALgraph* G, const int& start, const int& end);
status insert_M_edge(AMgraph* G, const edge& src, const int& start, const int& end);
status insert_L_edge(AMgraph* G, const edge& src, const int& start, const int& end);

#endif // !MY_MAP_H
