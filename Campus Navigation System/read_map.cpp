#include "my_map_define.h"
#include "my_map.h"
#include <fstream>
#include <string>
#include <sstream>

status import_M_map(AMgraph* G)
{
	std::ifstream ifile("./南校简易地图数据v1.0.txt");
	std::string s_temp;
	if (!ifile.is_open())
	{
		return error;
	}
	else
	{
		int row{ -1 }, column{ -1 };
		while (!ifile.fail())
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
		update_map_size(G);
		G->edge_map.resize(G->size);
		for (auto& i : G->edge_map)
		{
			i.resize(G->size);
		}
		std::getline(ifile, s_temp);
		while (!ifile.fail())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{ s_temp };
			ss >> row >> column;
			ss >> G->edge_map[row][column].distance;
		}
	}
}

status import_L_map(ALgraph* G);

status export_M_map(AMgraph* G);

status export_L_map(ALgraph* G);
