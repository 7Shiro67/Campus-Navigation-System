#include"CNS.h"


using namespace std;
namespace fs = filesystem;

Status ImportList()
{
	cout << endl;
	cout << "文件列表:" << endl;
	string inputPath = "File-input/";
	try
	{
		for (const auto& entry : fs::directory_iterator(inputPath))
		{
			if (entry.is_regular_file()) {
				cout << entry.path().filename().string() << endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		cerr << "出错:" << e.what() << endl;
	}
	cout << endl;

}

Status Creace_Edges(AMgraph& G)
{
	vector<K_Edge>Edges;
	int pos = 0;
	for (int i = 0; i < G.edge_map.size(); i++)
	{
		for (int j = 0; j < G.edge_map[i].size()-i; j++)
		{
			Edges[pos].head = i;
			Edges[pos].tail = j;
			Edges[pos].cost = G.edge_map[i][j].distance;
		}
	}
}

Status Creace_Edges(ALgraph& L)
{

}

Status MiniSpanTree(AMgraph &G)
{

}

