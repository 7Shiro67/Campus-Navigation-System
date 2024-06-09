#include"CNS.h"


using namespace std;
namespace fs = filesystem;


Status Display_FilesList()
{
	cout << endl;
	cout << "ÎÄ¼þÁÐ±í:" << endl;
	string inputPath = "./";

	for (const auto& entry : fs::directory_iterator(inputPath))
	{
		if (entry.is_regular_file()) {
			cout << entry.path().filename().string() << endl;
		}
	}

	return OK;
}

bool compare_edge(const K_Edge& c1, const K_Edge& c2)
{
	return c1.cost < c2.cost;
}

Status MiniST_K_G(AMgraph* G,vector<K_Edge> &mst_edges,int &totalcost)
{
	vector<K_Edge> Edges;
	for (int i = 0; i < G->edge_map.size(); i++)
	{
		for (int j = 0; j < G->edge_map[i].size(); j++)
		{
			if (G->edge_map[i][j].distance!=INT_MAX)
			{
				K_Edge new_edge = { i,j,G->edge_map[i][j].distance };
				Edges.push_back(new_edge);
			}
		}
	}
	
	sort(Edges.begin(), Edges.end(), compare_edge);

	vector<int> vexset;
	bool flag = true;
	for (int i = 0; i < G->node_map.size(); i++)
	{
		vexset.push_back(i);
	}
	for (const auto& e :Edges)
	{
		int v1 = e.head;
		int v2 = e.tail;
		int vs1 = vexset[v1];
		int vs2 = vexset[v2];
		if (vs1 != vs2)
		{
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


void preorder_traversal(int node, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int& totalcost, AMgraph* G) {
	visited[node] = true;
	for (int neighbor : adj_list[node]) {
		if (!visited[neighbor]) {
			totalcost += G->edge_map[node][neighbor].distance;
			cout << "Edge: " << G->node_map[node].name << " -> " << G->node_map[neighbor].name << " (Distance: " << G->edge_map[node][neighbor].distance << ")" << endl;
			preorder_traversal(neighbor, adj_list, visited, totalcost, G);
			totalcost += G->edge_map[neighbor][node].distance;
			cout << "Edge: " << G->node_map[neighbor].name << " -> " << G->node_map[node].name << " (Distance: " << G->edge_map[neighbor][node].distance << ")" << endl;
		}
	}


}

Status TSP(int start_node,AMgraph* G)
{
	vector<K_Edge> mst_edges;
	int totalcost = 0;
	Status status = MiniST_K_G(G, mst_edges, totalcost);

	if (status == OK) {
		cout << "Minimum Spanning Tree constructed successfully." << endl;

		unordered_map<int, vector<int>> adj_list;
		for (const auto& edge : mst_edges) {
			adj_list[edge.head].push_back(edge.tail);
			adj_list[edge.tail].push_back(edge.head);
		}

		vector<bool> visited(G->node_map.size(), false);
		vector<int> tour;
		cout << "TSP Path: "<<endl;
		preorder_traversal(start_node, adj_list, visited, totalcost,G);

		cout << "Total Cost: " << totalcost << endl;
	}
	else {
		cout << "Error in constructing Minimum Spanning Tree." << endl;
	}
	return OK;
}
