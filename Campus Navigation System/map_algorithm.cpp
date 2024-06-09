#include "my_map_define.h"
#include <limits>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>

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

status one_TSP(AMgraph* G,int s)
{
	std::vector<std::vector<int>> path;
	std::vector<std::vector<int>> dis;
	Floyd(G, dis, path);
	std::vector<std::vector<int>> dp((1 << G->size), std::vector<int>(5, INT_MAX));
	dp[1][0] = 0;
	for (int s = 1; s < (1 << G->size); s++) {
		for (int i = 0; i < G->size; i++) {
			if ((s & (1 << i)) != 0) {
				for (int j = 0; j < G->size; j++) {
					if ((s & (1 << j)) != 0 && i != j) {
						dp[s][i] = std::min(dp[s][i], dp[s ^ (1 << i)][j] + dis[j][i]);
					}
				}
			}
		}
	}
	int ans = INT_MAX;
	int idx = -1;
	for (int i = 1; i < G->size; i++) {// 0是起始点，就不要加入里面了
		if (ans > dp[(1 << G->size) - 1][i] + dis[i][0]) {
			ans = dp[(1 << G->size) - 1][i] + dis[i][0];
			idx = i;
		}
	}
	std::vector<int> initP(G->size + 1);
	return OK;
}