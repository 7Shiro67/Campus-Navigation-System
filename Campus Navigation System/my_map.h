#ifndef MY_MAP_H
#define MY_MAP_H
#include "my_map_define.h"

status create_M_map(AMgraph*& G);
status create_L_map(ALgraph*& G);
status check_map_null(void* G);
status show_M_map(const AMgraph* G);
status show_L_map(const ALgraph* G);
status update_map_size(AMgraph* G);

#endif // !MY_MAP_H
