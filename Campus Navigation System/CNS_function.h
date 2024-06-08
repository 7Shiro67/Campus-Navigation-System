#ifndef CNS_FUNCTION_H
#define	CNS_FUNCTION_H

#include"my_map_define.h"
using namespace std;

Status Display_FilesList();

bool compare_edge(const K_Edge& c1, const K_Edge& c2);

Status MiniST_K_G(AMgraph* G, std::vector<K_Edge>& mst_edges, int& totalcost);

void preorder_traversal(int node, unordered_map<int, vector<int>>& adj_list, vector<bool>& visited, int& totalcost, AMgraph* G);

Status TSP(int start_node, AMgraph* G);

#endif // !CNS_FUNCTION_H
