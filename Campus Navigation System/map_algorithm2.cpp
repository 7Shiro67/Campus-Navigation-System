#include "CNS.h"

using namespace std;
namespace fs = filesystem;

Status Display_FilesList(vector<string>& v_s)
{
	string inputPath = "./";
	for (const auto& entry : fs::directory_iterator(inputPath))
	{
		if (entry.is_regular_file())
		{
			if (entry.path().filename().extension() == ".txt")
			{
				v_s.push_back(entry.path().filename().string());
			}
		}
	}
	cout << "文件列表:" << endl;
	for (int i = 0; i < v_s.size(); i++)
	{
		cout <<i << ":" << v_s[i] << "\n";
	}
	return OK;
}

// 辅助函数：比较边的权重，用于排序
bool compare_edge(const K_Edge& c1, const K_Edge& c2) 
{
    return c1.cost < c2.cost;
}

// 使用Kruskal算法计算最小生成树（MST）并返回边和总权重
Status MiniST_K(AMgraph* G, vector<K_Edge>& mst_edges, int& totalcost) 
{
    vector<K_Edge> Edges;

    // 将图的所有边添加到Edges向量中
    for (int i = 0; i < G->edge_map.size(); i++) {
        for (int j = 0; j < G->edge_map[i].size(); j++) {
            if (G->edge_map[i][j].distance != INT_MAX) {
                K_Edge new_edge = { i, j, G->edge_map[i][j].distance };
                Edges.push_back(new_edge);
            }
        }
    }

    // 按照边的权重升序排序
    sort(Edges.begin(), Edges.end(), compare_edge);

    vector<int> vexset;
    bool flag = true;

    // 初始化顶点集合
    for (int i = 0; i < G->node_map.size(); i++) {
        vexset.push_back(i);
    }

    // Kruskal算法：选择边并构建最小生成树
    for (const auto& e : Edges) {
        int v1 = e.head;
        int v2 = e.tail;
        int vs1 = vexset[v1];
        int vs2 = vexset[v2];
        if (vs1 != vs2) {
            mst_edges.push_back(e);
            for (int j = 0; j < vexset.size(); j++) 
            {
                if (vexset[j] == vs2) 
                {
                    vexset[j] = vs1;
                }
            }
        }
    }
    return OK;
}

// 另一版本的MiniST_K函数，适用于ALgraph
Status MiniST_K(ALgraph* G, vector<K_Edge>& mst_edges, int& totalcost) 
{
    vector<K_Edge> Edges;

    // 将图的所有边添加到Edges向量中
    for (int i = 0; i < G->edge_map.size(); i++) 
    {
        for (int j = 0; j < G->edge_map[i].size(); j++) 
        {
            if (G->edge_map[i][j].distance != INT_MAX) 
            {
                K_Edge new_edge = { i, j, G->edge_map[i][j].distance };
                Edges.push_back(new_edge);
            }
        }
    }

    // 按照边的权重升序排序
    sort(Edges.begin(), Edges.end(), compare_edge);

    vector<int> vexset;
    bool flag = true;

    // 初始化顶点集合
    for (int i = 0; i < G->node_map.size(); i++) 
    {
        vexset.push_back(i);
    }

    // Kruskal算法：选择边并构建最小生成树
    for (const auto& e : Edges) {
        int v1 = e.head;
        int v2 = e.tail;
        int vs1 = vexset[v1];
        int vs2 = vexset[v2];
        if (vs1 != vs2) {
            mst_edges.push_back(e);
            for (int j = 0; j < vexset.size(); j++) 
            {
                if (vexset[j] == vs2) {
                    vexset[j] = vs1;
                }
            }
        }
    }
    return OK;
}

// 先序遍历最小生成树，用于TSP问题
void preorder_traversal(int node, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int& totalcost, AMgraph* G, int flag) 
{
    visited[node] = true;
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            totalcost += G->edge_map[node][neighbor].distance;
            if (flag)
                cout << left << setw(10) << G->node_map[node].name << " -> " << left << setw(10) << G->node_map[neighbor].name << right << setw(10) << " (距离: " << G->edge_map[node][neighbor].distance << ")" << endl;
            preorder_traversal(neighbor, adj_list, visited, totalcost, G, flag);
            totalcost += G->edge_map[neighbor][node].distance;
            if (flag)
                cout << left << setw(10) << G->node_map[neighbor].name << " -> " << left << setw(10) << G->node_map[node].name << right << setw(10) << " (距离: " << G->edge_map[neighbor][node].distance << ")" << endl;
        }
    }
}

// 另一版本的先序遍历函数，适用于ALgraph
void preorder_traversal(int node, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int& totalcost, ALgraph* G) 
{
    visited[node] = true;
    for (int neighbor : adj_list[node]) {
        if (!visited[neighbor]) {
            totalcost += G->edge_map[node][neighbor].distance;
            cout << left << setw(10) << G->node_map[node].name << " -> " << left << setw(10) << G->node_map[neighbor].name << right << setw(10) << " (距离: " << G->edge_map[node][neighbor].distance << ")" << endl;
            preorder_traversal(neighbor, adj_list, visited, totalcost, G);
            totalcost += G->edge_map[neighbor][node].distance;
            cout << left << setw(10) << G->node_map[neighbor].name << " -> " << left << setw(10) << G->node_map[node].name << right << setw(10) << " (距离: " << G->edge_map[neighbor][node].distance << ")" << endl;
        }
    }
}

// 基于最小生成树的旅行商问题（TSP）求解函数，适用于AMgraph
Status TSP(int start_node, AMgraph* G, int& totalcost, int flag) 
{
    vector<K_Edge> mst_edges;
    totalcost = 0;
    Status status = MiniST_K(G, mst_edges, totalcost);

    if (status == OK) {
        if (flag == 1) {
            cout << "最小生成树构建成功" << endl;
        }
        unordered_map<int, vector<int>> adj_list;
        for (const auto& edge : mst_edges) {
            adj_list[edge.head].push_back(edge.tail);
            adj_list[edge.tail].push_back(edge.head);
        }

        vector<bool> visited(G->node_map.size(), false);
        vector<int> tour;
        if (flag == 1) {
            cout << "打卡路径: " << endl;
        }
        preorder_traversal(start_node, adj_list, visited, totalcost, G, flag);

        if (flag == 1) {
            cout << "总距离: " << totalcost << endl;
        }
    }
    else {
        cout << "构建最小生成树时出现错误." << endl;
    }
    return OK;
}

// 基于最小生成树的旅行商问题（TSP）求解函数，适用于ALgraph
Status TSP(int start_node, ALgraph* G) 
{
    G->edge_map = convert_M_edge_map(G);  // 将邻接表转换为邻接矩阵
    vector<K_Edge> mst_edges;
    int totalcost = 0;
    Status status = MiniST_K(G, mst_edges, totalcost);

    if (status == OK) {
        cout << "最小生成树构建成功." << endl;

        unordered_map<int, vector<int>> adj_list;
        for (const auto& edge : mst_edges) {
            adj_list[edge.head].push_back(edge.tail);
            adj_list[edge.tail].push_back(edge.head);
        }

        vector<bool> visited(G->node_map.size(), false);
        vector<int> tour;
        cout << "打卡路径: " << endl;
        preorder_traversal(start_node, adj_list, visited, totalcost, G);

        cout << "总距离: " << totalcost << endl;
    }
    else {
        cout << "构建最小生成树时出现错误." << endl;
    }
    return OK;
}

// 将邻接表图转换为邻接矩阵图
vector<vector<edge>> convert_M_edge_map(ALgraph* l_G) 
{
    vector<vector<edge>> edge_map(l_G->node_map.size(), vector<edge>(l_G->node_map.size()));

    for (int i = 0; i < l_G->size; i++) {
        for (int j = 0; j < l_G->edge_map[i].size(); j++) {
            edge temp = l_G->edge_map[i][j];
            edge_map[i][temp.next_node].distance = temp.distance;
        }
    }
    return edge_map;
}


