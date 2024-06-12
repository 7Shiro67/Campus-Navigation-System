#include "my_map_define.h"
#include "map_algorithm2.h"
#include <limits>
#include<iostream>
#include<queue>
#include<algorithm>

struct K_edge
{
	int start;
	int end;
	int distance;
};

void dfs_m(AMgraph* G, int pos, std::vector<bool>& visited)
{
	std::cout << pos << ' ';
	visited[pos] = true;
	for (int i = 0; i < G->edge_map[pos].size(); i++)
	{
		if (G->edge_map[pos][i].distance != INT_MAX && !visited[pos])
		{
			dfs_m(G, i, visited);
		}
	}
}

void dfs_l(ALgraph* G, int pos, std::vector<bool>& visited)
{
	std::cout << pos << ' ';
	visited[pos] = true;
	for (int i = 0; i < G->edge_map[pos].size(); i++)
	{
		if (!visited[pos])
		{
			dfs_l(G, i, visited);
		}
	}
}

status dfs(AMgraph* G,int start)
{
	std::vector<bool> visited(G->size,false);
	dfs_m(G, start,visited);
	return OK;
}

status dfs(ALgraph* G, int start)
{
	std::vector<bool> visited(G->size, false);
	dfs_l(G, start, visited);
	return OK;
}

status bfs(AMgraph* G,int start)
{
	std::vector<bool> visited(G->size, false);
	std::queue<int> temp;
	int pos = start;
	temp.push(0);
	while (!temp.empty())
	{
		pos = temp.front();
		std::cout << pos << ' ';
		temp.pop();
		for (int i = 0; i < G->edge_map[pos].size(); i++)
		{
			if (G->edge_map[pos][i].distance != INT_MAX && !visited[i])
			{
				temp.push(i);
			}
		}
	}
	return OK;
}

status bfs(ALgraph* G, int start)
{
	std::vector<bool> visited(G->size, false);
	std::queue<int> temp;
	int pos = start;
	temp.push(0);
	while (!temp.empty())
	{
		pos = temp.front();
		std::cout << pos << ' ';
		temp.pop();
		for (int i = 0; i < G->edge_map[pos].size(); i++)
		{
			if (!visited[i])
			{
				temp.push(i);
			}
		}
	}
	return OK;
}

bool check_end_prim(const std::vector<int>& closededge)
{
	bool res = true;
	for (auto& i : closededge)
	{
		if (i != -1)
		{
			res = false;
		}
	}
	return res;
}

status prim(const AMgraph* G,int pos, AMgraph& G_generate)
{
	std::vector<K_edge> edges_res;
	std::vector<int> closededge(G->size,INT_MAX);
	while (!check_end_prim(closededge))
	{
		closededge[pos] = -1;
		for (int i = 0; i < G->edge_map[pos].size(); i++)
		{
			if (i != pos)
			{
				if (G->edge_map[pos][i].distance < closededge[i])
				{
					closededge[i] = G->edge_map[pos][i].distance;
				}
			}
		}
		int temp_pos = -1;
		int min = INT_MAX;
		for (int i = 0; i < closededge.size(); i++)
		{
			if (closededge[i] < min && closededge[i] != -1)
			{
				min = closededge[i];
				temp_pos = i;
			}
		}
		pos = temp_pos;
		for (int one = 0; one < G->edge_map[pos].size(); one++)
		{
			if (G->edge_map[pos][one].distance == closededge[pos])
			{
				edges_res.push_back({ pos,one,closededge[pos] });
				break;
			}
		}
	}
	return OK;
}

status prim(ALgraph* G, int pos, ALgraph& G_generate)
{
	std::vector<int> closededge(G->size, INT_MAX);
	while (!check_end_prim(closededge))
	{
		closededge[pos] = -1;
		for (int i = 0; i < G->edge_map[pos].size(); i++)
		{
			if (i != pos)
			{
				if (G->edge_map[pos][i].distance < closededge[i])
				{
					closededge[G->edge_map[pos][i].next_node] = G->edge_map[pos][i].distance;
				}
			}
		}
		int temp_pos = -1;
		int min = INT_MAX;
		for (int i = 0; i < closededge.size(); i++)
		{
			if (closededge[i] < min && closededge[i] != -1)
			{
				min = closededge[i];
				temp_pos = i;
			}
		}
	}
	return OK;
}

status Kruskal(AMgraph* G,AMgraph& G_generate)
{
	std::vector<K_edge> res;
	std::vector<K_edge> edges;
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(G->edge_map[i][j].distance != INT_MAX)
			edges.push_back({i,j,G->edge_map[i][j].distance});
		}
	}
	std::sort(edges.begin(), edges.end(), 
		[](K_edge a, K_edge b)->bool {return a.distance > b.distance; });
	std::vector<int> vexset(G->size, 0);
	for (int i = 0; i < vexset.size(); i++)
	{
		vexset[i] = i;
	}
	for (int i = 0; i < edges.size(); i++)
	{
		if (vexset[edges[i].start] != vexset[edges[i].end])
		{
			res.push_back(edges[i]);
		}
		int temp = vexset[edges[i].start];
		for (int j = 0; j < vexset.size(); j++)
		{
			if (vexset[j] == temp)
			{
				vexset[j] = vexset[edges[j].end];
			}
		}
	}
	return OK;
}

status Kruskal(ALgraph* G,ALgraph& G_generate)
{
	std::vector<K_edge> res;
	std::vector<K_edge> edges;
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->edge_map[i].size(); j++)
		{
			if (G->edge_map[i][j].next_node > i)
				edges.push_back({ i,G->edge_map[i][j].next_node,G->edge_map[i][j].distance});
		}
	}
	std::sort(edges.begin(), edges.end(),
		[](K_edge a, K_edge b)->bool {return a.distance > b.distance; });
	std::vector<int> vexset(G->size, 0);
	for (int i = 0; i < vexset.size(); i++)
	{
		vexset[i] = i;
	}
	for (int i = 0; i < edges.size(); i++)
	{
		if (vexset[edges[i].start] != vexset[edges[i].end])
		{
			res.push_back(edges[i]);
		}
		int temp = vexset[edges[i].start];
		for (int j = 0; j < vexset.size(); j++)
		{
			if (vexset[j] == temp)
			{
				vexset[j] = vexset[edges[j].end];
			}
		}
	}
	return OK;
}

status dijkstra(AMgraph* G,std::vector<int>& min_path,std::vector<int>& before,int S)
{
	min_path[S] = 0;
	std::vector<bool> is_arrived(G->size, false);
	is_arrived[S] = true;
	int temp = S;
	for (int j = 0; j < G->size; j++)
	{
		for (int i = 0; i < G->edge_map[temp].size(); i++)
		{
			if (!is_arrived[i] && G->edge_map[temp][i].distance != INT_MAX &&
				min_path[temp] + G->edge_map[temp][i].distance < min_path[i])
			{
				min_path[i] = min_path[temp] + G->edge_map[temp][i].distance;
				before[i] = temp;
			}
		}
		int min_pos = -1;
		int min = INT_MAX;
		for (int i = 0; i < min_path.size(); i++)
		{
			if (!is_arrived[i] && min_path[i] < min)
			{
				min = min_path[i];
				min_pos = i;
			}
		}
		if (min_pos == -1)
		{
			break;
		}
		is_arrived[min_pos] = true;
		temp = min_pos;
	}
	return OK;
}

status dijkstra(ALgraph* G, std::vector<int>& min_path, std::vector<int>& before, int S)
{
	min_path[S] = 0;
	std::vector<bool> is_arrived(G->size, false);
	is_arrived[S] = true;
	int temp = S;
	for (int j = 0; j < G->size; j++)
	{
		for (int i = 0; i < G->edge_map[temp].size(); i++)
		{
			edge temp1 = G->edge_map[temp][i];
			if (!is_arrived[temp1.next_node] && min_path[temp] + temp1.distance < min_path[temp1.next_node])
			{
				min_path[temp1.next_node] = min_path[temp] + temp1.distance;
				before[temp1.next_node] = temp;
			}
		}
		int min_pos = -1;
		int min = INT_MAX;
		for (int i = 0; i < min_path.size(); i++)
		{
			if (!is_arrived[i] && min_path[i] < min)
			{
				min = min_path[i];
				min_pos = i;
			}
		}
		if (min_pos == -1)
		{
			break;
		}
		is_arrived[min_pos] = true;
		temp = min_pos;
	}
	return OK;
}

status Floyd(AMgraph* G, std::vector<std::vector<int>>& res_dis, std::vector<std::vector<int>>& res_path)
{
	std::vector<std::vector<int>> dis(G->size,std::vector<int>(G->size,0));
	std::vector<std::vector<int>> path(G->size, std::vector<int>(G->size,0));
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (i != j)
			{
				dis[i][j] = G->edge_map[i][j].distance;
			}
		}
	}
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (i == j || dis[i][j] == INT_MAX)
			{
				path[i][j] = -1;
			}
			else
			{
				path[i][j] = i;
			}
		}
	}
	for (int k = 0; k < G->size; k++)
	{
		for (int i = 0; i < G->size; i++)
		{
			for (int j = 0; j < G->size; j++)
			{
				if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	res_dis = dis;
	res_path = path;
	return OK;
}

status Floyd(ALgraph* G, std::vector<std::vector<int>>& res_dis, std::vector<std::vector<int>>& res_path)
{
	std::vector<std::vector<int>> dis(G->size, std::vector<int>(G->size, 0));
	std::vector<std::vector<int>> path(G->size, std::vector<int>(G->size, 0));
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->edge_map[i].size(); j++)
		{
			edge temp = G->edge_map[i][j];
			dis[i][temp.next_node] = temp.distance;
		}
	}
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (i != j && dis[i][j] == 0)
			{
				dis[i][j] = INT_MAX;
			}
		}
	}
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (i == j || dis[i][j] == INT_MAX)
			{
				path[i][j] = -1;
			}
			else
			{
				path[i][j] = i;
			}
		}
	}
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			for (int k = 0; k < G->size; k++)
			{
				if (dis[j][i] != INT_MAX && dis[i][k] != INT_MAX && dis[j][i] + dis[i][k] < dis[j][k])
				{
					dis[j][k] = dis[j][i] + dis[i][k];
					path[j][k] = i;
				}
			}
		}
	}
	res_dis = dis;
	res_path = path;
	return OK;
}

int find_min_pos(const std::vector<int>& min_path,  const std::vector<bool>& is_arrived)
{
	int pos = -1;
	int min = INT_MAX;
	for (int i = 0; i < min_path.size(); i++)
	{
		if (!is_arrived[i] && min_path[i] < min)
		{
			min = min_path[i];
			pos = i;
		}
	}
	return pos;
}

std::vector<int> find_path(const std::vector<std::vector<int>>& path, int s, int e)
{
	std::vector<int> res;
	res.push_back(e);
	while (path[s][e] != s)
	{
		e = path[s][e];
		res.push_back(e);
	}
	res.push_back(s);
	std::reverse(res.begin(), res.end());
	return res;
}

status oneTSP(AMgraph* G,int s,std::vector<int>& new_path)
{
	std::vector<std::vector<int>> dis;
	std::vector<std::vector<int>> path;
	Floyd(G, dis, path);
	std::vector<bool> visited(G->size, false);
	visited[s] = true;
	new_path.push_back(s);
	int temp = s;
	while (true)
	{
		int min_pos = find_min_pos(dis[temp], visited);
		if (min_pos == -1)
		{
			break;
		}
		std::vector<int> temp1 = find_path(path, temp, min_pos);
		std::vector<int>::iterator itor = temp1.begin() + 1;
		while (itor != temp1.end())
		{
			new_path.push_back(*itor);
			visited[*itor] = true;
			itor++;
		}
		temp = min_pos;
	}
	std::vector<int> temp1 = find_path(path, new_path.back(), s);
	std::vector<int>::iterator itor = temp1.begin() + 1;
	while (itor != temp1.end())
	{
		new_path.push_back(*itor);
		itor++;
	}
	return OK;
}

double show_difference_TSP(AMgraph* G, int& cnt1, int& cnt2)
{
	int cnt = 0;
	for (int i = 0; i < G->size; i++)
	{
		int totalcost;
		TSP(i, G, totalcost, 0);
		std::vector<int> path;
		oneTSP(G, i, path);
		int sum = 0;
		for (int i = 0; i < path.size() - 1; i++)
		{
			sum += G->edge_map[path[i]][path[i + 1]].distance;
		}
		if (totalcost < sum)
		{
			cnt++;
		}
	}
	cnt1 = cnt;
	cnt2 = G->size - cnt;
	return cnt * 1.0 / cnt2;
}

template<typename T>
status show_hot_place_activation(T* G,const unordered_map<std::string,std::string>& map,
	int s,const vector<vector<int>>& dis)
{
	int pos = -1;
	int min = INT_MAX;
	for (int i = 0; i < dis[s].size(); i++)
	{
		if (dis[s][i] < min)
		{
			pos = i;
			min = dis[s][i];
		}
	}
	string temp = G->node_map[pos].name;
	cout << "最近景点为:" << temp << '\n'
		<< "活动为：" << map.at(temp) << endl;
	return OK;
}

template status show_hot_place_activation<AMgraph>(AMgraph* G, const unordered_map<std::string, std::string>& map,
	int s, const vector<vector<int>>& dis);

template status show_hot_place_activation<ALgraph>(ALgraph* G, const unordered_map<std::string, std::string>& map,
	int s, const vector<vector<int>>& dis);