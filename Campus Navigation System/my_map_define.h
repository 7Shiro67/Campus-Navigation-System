#ifndef MY_MAP_DEFINE_H
#define MY_MAP_DEFINE_H

using status = int;
constexpr auto error = 0;
constexpr auto OK = 1;
#include<vector>
#include<climits>
#include<string>

typedef struct MY_NODE
{
	std::string name;
} node;

typedef struct MY_EDGE
{
	int next_node{ -1 };
	int distance{ INT_MAX };
} edge;

typedef struct MY_MATRIX_MAP
{
	int size{ 0 };
	std::vector<node> node_map;
	std::vector<std::vector<edge>> edge_map;
} AMgraph;

typedef struct MY_LIST_MAP
{
	int size{ 0 };
	std::vector<node> node_map;
	std::vector<std::vector<edge>> edge_map;
} ALgraph;


#endif // !MY_MAP_DEFINE_H
