#include "my_map_define.h"
#include "my_map.h"
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <unordered_map>

namespace fs = std::filesystem;

status import_M_map(AMgraph* G,std::vector<std::string> v_s)
{
	int i;
	std::string filename;
	std::cin >> i;
	filename = v_s[i];
	std::ifstream ifile(filename);
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
	ifile.close();
	return OK;
}

status import_L_map(ALgraph* G, std::vector<std::string> v_s)
{
	int i;
	std::string filename;
	std::cin >> i;
	filename = v_s[i];
	std::ifstream ifile(filename);
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
	ifile.close();
	return OK;
}

status export_M_map(AMgraph* G)
{
	int i = 1;
	std::stringstream ss;
	ss << "export_M(" << i << ").txt";
	if (fs::exists(ss.str()))
	{
		i++;
		ss.clear();
		ss << "export_M(" << i << ").txt";
	}
	std::ofstream fout( "/导出/" + ss.str());
	for (int i = 0; i < G->node_map.size(); i++)
	{
		fout << i + 1 << "\t" << G->node_map[i].name << '\n';
	}
	fout << '\n';
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
	fout << std::left << std::setw(4) << 0 << ' ';
	for (int i = 0; i < G->size; i++)
	{
		fout << std::left << std::setw(4) << i + 1 << ' ';
	}
	fout << '\n';
	for (int i = 0; i < G->size; i++)
	{
		fout << std::left << std::setw(4) << i + 1 << ' ';
		for (int j = 0; j < G->size; j++)
		{
			fout << std::left << std::setw(4) << edge_map[i][j].distance << ' ';
		}
		fout << '\n';
	}
	fout.close();
	return OK;
}

status export_L_map(ALgraph* G)
{
	int i = 1;
	std::stringstream ss;
	ss << "export_L(" << i << ").txt";
	if (fs::exists(ss.str()))
	{
		i++;
		ss.str("");
		ss << "export_L(" << i << ").txt";
	}
	std::ofstream fout("/导出/" + ss.str());
	for (int i = 0; i < G->node_map.size(); i++)
	{
		fout << i + 1 << "\t" << G->node_map[i].name << '\n';
	}
	fout << '\n';
	std::vector<std::vector<edge>> edge_map = G->edge_map;
	for (int i = 0; i < G->size; i++)
	{
		fout << i + 1;
		for (int j = 0; j < edge_map[i].size(); j++)
		{
			fout << "|" << edge_map[i][j].distance << "->" << edge_map[i][j].next_node + 1;
		}
		fout << '\n';
	}
	fout.close();
	return OK;
}

status import_introduction(std::unordered_map<std::string,std::string>& introduction)
{
	std::string filename = "简介/input.txt";
	std::ifstream ifile(filename);
	std::string s_temp;
	if (!ifile.is_open())
	{
		return error;
	}
	else
	{
		std::string key, value;
		while (!ifile.eof())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{ s_temp };
			ss >> key >> value;
			introduction[key] = value;
		}
	}
	ifile.close();
	return OK;
}

status import_activation(std::unordered_map<std::string, std::string>& activation)
{
	std::string filename = "简介/input1.txt";
	std::ifstream ifile(filename);
	std::string s_temp;
	if (!ifile.is_open())
	{
		return error;
	}
	else
	{
		std::string key, value;
		while (!ifile.eof())
		{
			std::getline(ifile, s_temp);
			if (s_temp.empty())
			{
				break;
			}
			std::stringstream ss{ s_temp };
			ss >> key >> value;
			activation[key] = value;
		}
	}
	return OK;
}
