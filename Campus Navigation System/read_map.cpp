#include "my_map_define.h"
#include "my_map.h"
#include <fstream>
#include <string>
#include <sstream>

status import_M_map(AMgraph* G)
{
	std::ifstream ifile("./南校简易地图数据v1.1.txt");
	std::string s_temp;
	int temp{};
	if (!ifile.is_open())
	{
		return error;
	}
	else
	{
		int row{ -1 }, column{ -1 };
		while (!ifile.eof())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{s_temp};
			int i{0};
			G->node_map.push_back({});
			ss >> i >> G->node_map.back().name;
		}
		update_map_m_size(G);
		G->edge_map.resize(G->size);
		for (auto& i : G->edge_map)
		{
			i.resize(G->size);
		}
		std::getline(ifile, s_temp);
		while (!ifile.eof())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{ s_temp };
			ss >> row >> column;
			row--, column--;
			ss >> temp;
			G->edge_map[row][column].distance = temp;
			G->edge_map[column][row].distance = temp;
		}
	}
	return OK;
}

status import_L_map(ALgraph* G)
{
	std::ifstream ifile("./南校简易地图数据v1.1.txt");
	std::string s_temp;
	int temp{};
	if (!ifile.is_open())
	{
		return error;
	}
	else
	{
		int start{ -1 }, end{ -1 };
		while (!ifile.eof())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{ s_temp };
			int i{ 0 };
			G->node_map.push_back({});
			ss >> i >> G->node_map.back().name;
		}
		update_map_l_size(G);
		G->edge_map.resize(G->size);
		std::getline(ifile, s_temp);
		while (!ifile.eof())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{ s_temp };
			ss >> start >> end;
			start--, end--;
			ss >> temp;
			G->edge_map[start].push_back({ end,temp });
			G->edge_map[end].push_back({ start,temp });
		}
	}
	return OK;
}

status export_M_map(AMgraph* G)
{

	return OK;
}

status export_L_map(ALgraph* G)
{
	return OK;
}
