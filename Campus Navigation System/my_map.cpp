#include "my_map_define.h"
#include<iostream>

status create_M_map(AMgraph*& G)
{
	G = new AMgraph;
	if (G == nullptr)
	{
		return error;
	}
	else
	{
		return OK;
	}
}

status create_L_map(ALgraph*& G)
{
	G = new ALgraph;
	if (G == nullptr)
	{
		return error;
	}
	else
	{
		return OK;
	}
}

status check_map_null(void* G)
{
	if (!G)
	{
		std::cout << "Î´´´½¨µØÍ¼" << '\n';
		return error;
	}
	return OK;
}

status show_M_map(const AMgraph* G)
{
	if (check_map_null((void*)G))
	{
		return error;
	}
	for (auto &i : G->node_map)
	{
		std::cout << i.name << ' ' << '|' << ' ';
	}
	std::cout << '\n';
	for(int i = 0; i < G->size;i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			std::cout << G->edge_map[i][j].distance << ' ' << '|' << ' ';
		}
		std::cout << '\n';
	}
	return OK;
}

status update_map_size(AMgraph* G)
{
	G->size = G->node_map.size();
	return OK;
}


status show_L_map(const ALgraph* G)
{
	if (check_map_null((void*)G))
	{
		return error;
	}
	for (int i = 0; i < G->node_map.size(); i++)
	{
		std::cout << G->node_map[i].name << ' ';
		std::vector<edge> edges = G->edge_map[i];
		for (int j = 0; j < edges.size(); j++)
		{
			std::cout << edges[j].distance << ' ' << edges[j].next_node << ' ';
		}
		std::cout << '\n';
	}
	return OK;
}