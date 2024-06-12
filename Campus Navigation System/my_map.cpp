#include "my_map_define.h"
#include<iostream>
#include<iomanip>

status create_M_map(AMgraph*& G)	// 创建邻接矩阵
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

status create_L_map(ALgraph*& G)	// 创建邻接表
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

status check_map_null(void* G)	// 检查图是否为空
{
	if (!G)
	{
		std::cout << "未创建地图" << '\n';
		return error;
	}
	return OK;
}

status show_node(const AMgraph* G)
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
	return OK;
}


status show_node(const ALgraph* G)
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

status update_map_m_size(AMgraph* G)	// 更新邻接矩阵图的节点数
{
	G->size = G->node_map.size();
	return OK;
}

status update_map_l_size(ALgraph* G)	// 更新邻接表图的节点数
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
status find_pos_node(AMgraph* G,const std::string s,int& pos)
{
	for (int i = 0; i < G->node_map.size(); i++)
	{
		if (G->node_map[i].name == s)
		{
			pos = i;
			return OK;
		}
	}
	pos = -1;
	return error;
}

status find_pos_node(ALgraph* G, const std::string s, int& pos)
{
	for (int i = 0; i < G->node_map.size(); i++)
	{
		if (G->node_map[i].name == s)
		{
			pos = i;
			return OK;
		}
	}
	pos = -1;
	return error;
}

status find_pos_edge(AMgraph* G, const std::string start, const std::string end, int& row,int& column)
{
	row = -1, column = -1;
	for (int i = 0; i < G->node_map.size(); i++)	// 遍历节点找到指定节点的位置
	{
		if (G->node_map[i].name == start)
		{
			row = i;
		}
		else if(G->node_map[i].name == end)
		{
			column = i;
		}
	}
	if (row != -1 && column != -1)
	{
		return OK;
	}
	return error;
}

status find_pos_edge(ALgraph* G, const std::string start, const std::string end, int& row, int& column)
{
	row = -1, column = -1;
	for (int i = 0; i < G->node_map.size(); i++)
	{
		if (G->node_map[i].name == start)
		{
			row = i;
		}
		else if (G->node_map[i].name == end)
		{
			column = i;
		}
	}
	if (row != -1 && column != -1)
	{
		return OK;
	}
	return error;
}

status change_M_node(AMgraph* G, const std::string des_str, const int& i)
{
	G->node_map[i].name = des_str;
	return OK;
}
status change_L_node(ALgraph* G, const std::string des_str, const int& i)
{
	G->node_map[i].name = des_str;
	return OK;
}
status delete_M_node(AMgraph* G, const int& i)
{
	G->node_map.erase(G->node_map.begin() + i);
	G->edge_map.erase(G->edge_map.begin() + i);
	for (int k = 0; k < G->edge_map.size(); k++)
	{
		G->edge_map[k].erase(G->edge_map[k].begin() + i);
	}
	update_map_m_size(G);
	return OK;
}
status delete_L_node(ALgraph* G, const int& i) //邻接表节点的删除
{
	G->node_map.erase(G->node_map.begin() + i);
	G->edge_map.erase(G->edge_map.begin() + i);
	for (int k = 0; k < G->edge_map.size(); k++)
	{
		for (int l = 0; l < G->edge_map[k].size(); l++)
		{
			if (G->edge_map[k][l].next_node == i)
			{
				G->edge_map[k].erase(G->edge_map[k].begin() + l);
				l--;
			}
			else if(G->edge_map[k][l].next_node > i)
			{
				G->edge_map[k][l].next_node--;
			}
		}
	}
	update_map_l_size(G);
	return OK;
}
status insert_M_node(AMgraph* G, const node& src)// 插入新的顶点
{
	G->node_map.push_back(src);
	update_map_m_size(G);
	G->edge_map.resize(G->size);
	for (int i = 0; i < G->edge_map.size(); i++)
	{
		G->edge_map[i].resize(G->size);
	}
	return OK;
}

status insert_L_node(ALgraph* G, const node& src) // 在邻接表图插入新的顶点
{
	G->node_map.push_back(src);
	update_map_l_size(G);
	G->edge_map.resize(G->size);
	return OK;
}
status change_M_edge(AMgraph* G, const edge& src, const int& start, const int& end) // 修改邻接矩阵图边的距离
{
	G->edge_map[start][end] = src;
	G->edge_map[end][start] = src;
	return OK;
}
status change_L_edge(ALgraph* G, const edge& src, const int& start, const int& end) // 修改邻接表图边的距离
{
	edge temp = src;
	temp.next_node = end;
	for (int i = 0; i < G->edge_map[start].size() - 1; i++)
	{
		if (G->edge_map[start][i].next_node == end)
		{
			G->edge_map[start][i] = temp;
		}
	}
	temp.next_node = start;
	for (int i = 0; i < G->edge_map[end].size() - 1; i++)
	{
		if (G->edge_map[end][i].next_node == start)
		{
			G->edge_map[end][i] = temp;
		}
	}
	return OK;
}

status delete_M_edge(AMgraph* G, const int& start, const int& end) // 邻接矩阵图边的删除
{
	G->edge_map[start][end].distance = INT_MAX;
	G->edge_map[end][start].distance = INT_MAX;
	return OK;
}

status delete_L_edge(ALgraph* G, const int& start, const int& end) // 邻接表图边的删除
{
	for (int i = 0; i < G->edge_map[start].size(); i++)
	{
		if (G->edge_map[start][i].next_node == end)
		{
			G->edge_map[start].erase(G->edge_map[start].begin() + i);
		}
	}
	for (int i = 0; i < G->edge_map[end].size(); i++)
	{
		if (G->edge_map[end][i].next_node == start)
		{
			G->edge_map[end].erase(G->edge_map[end].begin() + i);
		}
	}
	return OK;
}

status insert_M_edge(AMgraph* G, const edge& src, const int& start, const int& end) // 在邻接矩阵图插入新的边
{
	G->edge_map[start][end] = src;
	G->edge_map[end][start] = src;
	return OK;
}
status insert_L_edge(ALgraph* G, const edge& src, const int& start,const int& end) // 在邻接表图插入新的边
{
	edge temp = src;
	temp.next_node = end;
	G->edge_map[start].push_back(temp);
	temp.next_node = start;
	G->edge_map[end].push_back(temp);
	return OK;
}