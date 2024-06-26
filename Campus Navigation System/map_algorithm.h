#pragma once

#include "my_map_define.h"

status dfs(AMgraph* G, int start);

status dfs(ALgraph* G, int start);

status bfs(AMgraph* G, int start);

status bfs(ALgraph* G, int start);

status prim(const AMgraph* G, int i, AMgraph& G_generate);

status prim(const ALgraph* G, int i, ALgraph& G_generate);

status Kruskal(AMgraph* G, AMgraph& G_generate);

status Kruskal(ALgraph* G, ALgraph& G_generate);

status dijkstra(AMgraph* G, std::vector<int>& min_path, std::vector<int>& before, int S);

status dijkstra(ALgraph* G, std::vector<int>& min_path, std::vector<int>& before, int S);

status Floyd(AMgraph* G, std::vector<std::vector<int>>& res_dis, std::vector<std::vector<int>>& res_path);

status Floyd(ALgraph* G ,std::vector<std::vector<int>>& res_dis, std::vector<std::vector<int>>& res_path);

status oneTSP(AMgraph* G, int s, std::vector<int>& new_path);

double show_difference_TSP(AMgraph* G, int& cnt1, int& cnt2);

template<typename T>
status show_hot_place_activation(T* G, const unordered_map<std::string, std::string>& map,
	int s, const vector<vector<int>>& dis);
