#ifndef MY_MAP_DEFINE_H
#define MY_MAP_DEFINEH

#include<vector>
#include<climits>

typedef struct MY_NODE
{
	const char name[100];

} node;

typedef struct MY_EDGE
{
	int next_node{ -1 };
	int distance{ INT_MAX };
} edge;

typedef struct MY_MATRIX_MAP
{
	std::vector<node> node_map;
	std::vector<std::vector<edge>> edge_map;
} AMgraph;

typedef struct MY_LIST_MAP
{
	std::vector<node> node_map;
	std::vector<std::vector<edge>> edge_map;
} ALgraph;


#endif // !MY_MAP_DEFINE_H
