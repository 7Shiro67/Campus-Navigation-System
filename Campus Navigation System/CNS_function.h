#ifndef CNS_FUNCTION_H
#define	CNS_FUNCTION_H

#include"my_map_define.h"
using namespace std;

Status Display_FilesList();

bool compare_edge(const K_Edge& c1, const K_Edge& c2);

Status MiniST_K(AMgraph* G, vector<K_Edge>& mst_edges, int& totalcost);

Status MiniST_K(ALgraph* G, vector<K_Edge>& mst_edges, int& totalcost);

void preorder_traversal(int node, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int& totalcost, AMgraph* G);

void preorder_traversal(int node, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int& totalcost, ALgraph* G);

Status TSP(int start_node, AMgraph* G);

Status TSP(int start_node, ALgraph* G);

vector<vector<edge>> convert_M_edge_map(ALgraph* l_G);

#endif // !CNS_FUNCTION_H

