#include "my_map_define.h"
#include<iostream>
#include<iomanip>

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
	if (!check_map_null((void*)G))
	{
		return error;
	}
	for (int i = 0; i < G->node_map.size();i++)
	{
		std::cout << i + 1 << "\t" << G->node_map[i].name << '\n';
	}
	std::cout << '\n';
	std::vector<std::vector<edge>> edge_map = G->edge_map;
	for (auto& i : edge_map)
	{
		for (auto& j : i)
		{
			if (j.distance == INT_MAX)
			{
				j.distance = -1;
			}
		}
	}
	std::cout << std::left << std::setw(4) << 0 << ' ';
	for (int i = 0; i < G->size; i++)
	{
		std::cout << std::left << std::setw(4) << i + 1 << ' ';
	}
	std::cout << '\n';
	for(int i = 0; i < G->size;i++)
	{
		std::cout << std::left << std::setw(4) << i + 1 << ' ';
		for (int j = 0; j < G->size; j++)
		{
			std::cout << std::left << std::setw(4) << edge_map[i][j].distance << ' ';
		}
		std::cout << '\n';
	}
	return OK;
}

status update_map_m_size(AMgraph* G)
{
	G->size = G->node_map.size();
	return OK;
}

status update_map_l_size(ALgraph* G)
{
	G->size = G->node_map.size();
	return OK;
}

status show_L_map(const ALgraph* G)
{
	if (!check_map_null((void*)G))
	{
		return error;
	}
	for (int i = 0; i < G->node_map.size(); i++)
	{
		std::cout << i + 1 << "\t" << G->node_map[i].name << '\n';
	}
	std::cout << '\n';
	std::vector<std::vector<edge>> edge_map = G->edge_map;
	for (int i = 0; i < G->size; i++)
	{
		std::cout  << i + 1;
		for (int j = 0; j < edge_map[i].size(); j++)
		{
			std::cout << "|" << edge_map[i][j].distance << "->" << edge_map[i][j].next_node + 1;
		}
		std::cout << '\n';
	}
	return OK;
}