#include"CNS.h"

using namespace std;

void draw_ui1();
void draw_ui2();

int main()
{
	bool running = true;
	while (running)
	{
		cout << "请输入你的选择:" << endl;
		cout << "1.邻接表" << endl;
		cout << "2.邻接矩阵" << endl;
		cout << "3.退出" << endl;
		int run_status;
		cin >> run_status;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "输入错误，请重新输入" << endl;
			cin >> run_status;
		}
		system("cls");
		if (run_status == 1)
		{
			draw_ui1();
		}
		else if (run_status == 2)
		{
			draw_ui2();
		}
		else if(run_status == 3)
		{
			running = false;
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}return 0;
}

void draw_ui1()
{
	bool running = true;
	AMgraph* m_G{};
	ALgraph* l_G{};
	while (running)
	{
		cout << "----------------------------------------\n";
		cout << "图书管理系统菜单:" << endl;
		cout << "1.  地图的邻接表的构建\n";
		cout << "2.  输出地图的邻接表\n";
		cout << "3.  导入地图数据为邻接表\n";
		cout << "4.  导出地图数据\n";
		cout << "5.  地图的邻接表的修改\n";
		cout << "6.  地图的邻接表的删除\n";
		cout << "7.  地图的邻接表的插入\n";
		cout << "8.  打卡所有景点的过程中所经过的所有景点以及各段距离和总距离\n";
		cout << "9.  输出从指定点出发，到达图中所有景点的最短距离及经过的地点\n";
		cout << "10. 输出从指定的景点(起点)到达另一指定景点(终点)的最短距离，以及经过的景点\n";
		cout << "11. 输出图中所有两景点之间的最短距离\n";
		cout << "12. 退出\n";
		cout << "----------------------------------------\n";
		unsigned int run_status;
		cout << "输入你的选择:";
		cin >> run_status;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "输入错误，请重新输入" << endl;
			cin >> run_status;
		}
		system("cls");
		switch (run_status)
		{
		case 1:
		{
			if (create_L_map(l_G))
			{
				cout << "邻接表创建成功"<<endl;
			}
			break;
		}
		case 2:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			show_L_map(l_G);
			break;
		}
		case 3:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			Display_FilesList();
			cout << "请输入文件名:";
			if (import_L_map(l_G))
			{
				cout << "导入成功" << endl;
			}
			break;
		}
		case 4:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			export_L_map(l_G);
			break;
		}
		case 5:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			int choice = 0;
			cout << "请输入你要修改的选项（1：边，2：点）：" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				cout << "请输入修改后边的值以及边的起点和终点（用空格隔开）" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				change_L_edge(l_G, src2, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				cout << "请输入修改顶点的序号以及修改成的名称（用空格隔开）" << endl;
				cin >> pos >> val;
				pos--;
				change_L_node(l_G, val, pos);
			}
			else
			{
				cout << "输入数值错误" << endl;
			}
			break;
		}
		case 6:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			int choice = 0;
			cout << "请输入你要删除的选项（1：边，2：点）：" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int  start, end;
				cout << "请输入要删除的边的起点和终点（用空格隔开）" << endl;
				cin >> start >> end;
				start--, end--;
				delete_L_edge(l_G, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				cout << "请输入要删除的顶点的序号" << endl;
				cin >> pos;
				pos--;
				delete_L_node(l_G, pos);
			}
			else
			{
				cout << "输入数值错误" << endl;
			}
			break;
		}
		case 7:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			int choice = 0;
			cout << "请输入你要插入的选项（1：边，2：点）：" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				cout << "请输入要插入的边的值以及边的起点和终点（用空格隔开）:" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				insert_L_edge(l_G, src2, start, end);
			}
			else if (choice == 2)
			{
				string val;
				cout << "请输入插入顶点的名称（用空格隔开）:" << endl;
				cin  >> val;
				node temp{ val };
				insert_L_node(l_G, temp);
			}
			else
			{
				cout << "输入数值错误" << endl;
			}
			break;
		}
		case 8:
		{
			if (!check_map_null(l_G))
			{
				export_L_map(l_G);
				break;
			}
			int start = -1;
			cout << "景点列表:" << endl;
			for (int i = 0; i < l_G->node_map.size(); i++)
			{
				cout << i << ". " << fixed << l_G->node_map[i].name << endl;
			}
			cout << "请输入起始点的序号: ";
			cin >> start;
			TSP(start, l_G);
			break;
		}
		case 9:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			show_node(l_G);
			cout << "请输入顶点序号" << endl;
			int start;
			cin >> start;
			start--;
			vector<int> min_path(l_G->size, INT_MAX);
			vector<int> before(l_G->size, -1);
			dijkstra(l_G, min_path, before, start);
			for (int i = 0; i < l_G->size; i++)
			{
				if (i != start)
				{
					cout << l_G->node_map[i].name << " : " << min_path[i] << endl;
					int temp = i;
					vector<int> temp_v;
					while (temp != start)
					{
						temp_v.push_back(temp);
						temp = before[temp];
					}
					temp_v.push_back(start);
					reverse(temp_v.begin(), temp_v.end());
					for (auto& i : temp_v)
					{
						cout << i + 1 << ' ';
					}
					cout << '\n';
				}
			}
			break;
		}
		case 10:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			show_node(l_G);
			cout << "请输入起点顶点序号" << endl;
			int start;
			cin >> start;
			cout << "请输入终点顶点序号" << endl;
			int end;
			cin >> end;
			start--;
			end--;
			vector<int> min_path(l_G->size, INT_MAX);
			vector<int> before(l_G->size, -1);
			dijkstra(l_G, min_path, before, start);
			cout << l_G->node_map[end].name << " : " << min_path[end] << endl;
			int temp = end;
			vector<int> temp_v;
			while (temp != start)
			{
				temp_v.push_back(temp);
				temp = before[temp];
			}
			temp_v.push_back(start);
			reverse(temp_v.begin(), temp_v.end());
			for (auto& i : temp_v)
			{
				cout << i + 1 << ' ';
			}
			cout << '\n';
			break;
		}
		case 11:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			std::vector<std::vector<int>> res_dis;
			std::vector<std::vector<int>> path;
			Floyd(l_G, res_dis, path);
			for (int i = 0; i < l_G->node_map.size(); i++)
			{
				std::cout << i + 1 << "\t" << l_G->node_map[i].name << '\n';
			}
			std::cout << '\n';
			std::vector<std::vector<int>> edge_map = res_dis;
			for (auto& i : edge_map)
			{
				for (auto& j : i)
				{
					if (j == INT_MAX)
					{
						j = -1;
					}
				}
			}
			std::cout << std::left << std::setw(4) << 0 << ' ';
			for (int i = 0; i < edge_map.size(); i++)
			{
				std::cout << std::left << std::setw(4) << i + 1 << ' ';
			}
			std::cout << '\n';
			for (int i = 0; i < edge_map.size(); i++)
			{
				std::cout << std::left << std::setw(4) << i + 1 << ' ';
				for (int j = 0; j < edge_map.size(); j++)
				{
					std::cout << std::left << std::setw(4) << edge_map[i][j] << ' ';
				}
				std::cout << '\n';
			}
			break;
		}
		case 12:
		{
			running = false;
			break;
		}
		case 13:
		{
			
			break;
		}
		case 14:
		{
			
		}
		default:
			break;
		}
	}
}

void draw_ui2()
{
	bool running = true;
	AMgraph* m_G{};
	ALgraph* l_G{};
	while (running)
	{
		cout << "----------------------------------------\n";
		cout << "图书管理系统菜单:" << endl;
		cout << "1.  地图的邻接矩阵的构建\n";
		cout << "2.  输出地图的邻接矩阵\n";
		cout << "3.  导入地图数据为邻接矩阵\n";
		cout << "4.  导出地图数据\n";
		cout << "5.  地图的邻接矩阵的修改\n";
		cout << "6.  地图的邻接矩阵的删除\n";
		cout << "7.  地图的邻接矩阵的插入\n";
		cout << "8.  打卡所有景点的过程中所经过的所有景点以及各段距离和总距离\n";
		cout << "9.  输出从指定点出发，到达图中所有景点的最短距离及经过的地点\n";
		cout << "10. 输出从指定的景点(起点)到达另一指定景点(终点)的最短距离，以及经过的景点\n";
		cout << "11. 输出图中所有两景点之间的最短距离\n";
		cout << "12. 退出\n";
		cout << "----------------------------------------\n";
		unsigned int run_status;
		cout << "输入你的选择:";
		cin >> run_status;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "输入错误，请重新输入" << endl;
			cin >> run_status;
		}
		system("cls");
		switch (run_status)
		{
		case 1:
		{
			if (create_M_map(m_G))
			{
				cout << "邻接矩阵创建成功"<<endl;
			}
			break;
		}
		case 2:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			show_M_map(m_G);
			break;
		}
		case 3:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			Display_FilesList();
			cout << "请输入文件名:";
			if (import_M_map(m_G))
			{
				cout << "导入成功" << endl;
			}
			break;
		}
		case 4:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			export_M_map(m_G);
			break;
		}
		case 5:
		{
			Display_FilesList();
			if (!check_map_null(m_G))
			{
				break;
			}
			int choice = 0;
			cout << "请输入你要修改的选项（1：边，2：点）：" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				cout << "请输入修改后边的值以及边的起点和终点（用空格隔开）" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				change_M_edge(m_G, src2, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				cout << "请输入修改顶点的序号以及修改成的名称（用空格隔开）" << endl;
				cin >> pos >> val;
				pos--;
				change_M_node(m_G, val, pos);
			}
			else
			{
				cout << "输入数值错误" << endl;
			}
			break;
		}
		case 6:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			int choice = 0;
			cout << "请输入你要删除的选项（1：边，2：点）：" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int  start, end;
				cout << "请输入要删除的边的起点和终点（用空格隔开）" << endl;
				cin >> start >> end;
				start--, end--;
				delete_M_edge(m_G, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				cout << "请输入要删除的顶点的序号" << endl;
				cin >> pos;
				pos--;
				delete_M_node(m_G, pos);
			}
			else
			{
				cout << "输入数值错误" << endl;
			}
			break;
		}
		case 7:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			int choice = 0;
			cout << "请输入你要插入的选项（1：边，2：点）：" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				cout << "请输入要插入的边的值以及边的起点和终点（用空格隔开）:" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				insert_M_edge(m_G, src2, start, end);
			}
			else if (choice == 2)
			{
				string val;
				cout << "请输入插入顶点的名称（用空格隔开）:" << endl;
				cin >> val;
				node temp{ val };
				insert_M_node(m_G, temp);
			}
			else
			{
				cout << "输入数值错误" << endl;
			}
			break;
		}
		case 8:
		{
			if (!check_map_null(m_G))
			{
				break;
			}	
			int start = -1;
			cout << "景点列表:" << endl;
			for (int i = 0; i < m_G->node_map.size(); i++)
			{
				cout<<i<<". "<<fixed<<m_G->node_map[i].name<<endl;
			}
			cout << "请输入起始点的序号: ";
			cin >> start;
			TSP(start, m_G);
			break;
		}
		case 9:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			show_node(m_G);
			cout << "请输入顶点序号" << endl;
			int start;
			cin >> start;
			start--;
			vector<int> min_path(m_G->size, INT_MAX);
			vector<int> before(m_G->size, -1);
			dijkstra(m_G, min_path, before, start);
			for (int i = 0; i < m_G->size; i++)
			{
				if (i != start)
				{
					cout << m_G->node_map[i].name << " : " << min_path[i] << endl;
					int temp = i;
					vector<int> temp_v;
					while (temp != start)
					{
						temp_v.push_back(temp);
						temp = before[temp];
					}
					temp_v.push_back(start);
					reverse(temp_v.begin(), temp_v.end());
					for (auto& i : temp_v)
					{
						cout << i + 1 << ' ';
					}
					cout << '\n';
				}
			}
			break;
		}
		case 10:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			show_node(m_G);
			cout << "请输入起点顶点序号" << endl;
			int start;
			cin >> start;
			cout << "请输入终点顶点序号" << endl;
			int end;
			cin >> end;
			start--;
			end--;
			vector<int> min_path(m_G->size, INT_MAX);
			vector<int> before(m_G->size, -1);
			dijkstra(m_G, min_path, before, start);
			cout << m_G->node_map[end].name << " : " << min_path[end] << endl;
			int temp = end;
			vector<int> temp_v;
			while (temp != start)
			{
				temp_v.push_back(temp);
				temp = before[temp];
			}
			temp_v.push_back(start);
			reverse(temp_v.begin(), temp_v.end());
			for (auto& i : temp_v)
			{
				cout << i + 1 << ' ';
			}
			cout << '\n';
			break;
		}
		case 11:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			std::vector<std::vector<int>> res_dis;
			std::vector<std::vector<int>> path;
			Floyd(m_G, res_dis, path);
			for (int i = 0; i < m_G->node_map.size(); i++)
			{
				std::cout << i + 1 << "\t" << m_G->node_map[i].name << '\n';
			}
			std::cout << '\n';
			std::vector<std::vector<int>> edge_map = res_dis;
			for (auto& i : edge_map)
			{
				for (auto& j : i)
				{
					if (j == INT_MAX)
					{
						j = -1;
					}
				}
			}
			std::cout << std::left << std::setw(4) << 0 << ' ';
			for (int i = 0; i < edge_map.size(); i++)
			{
				std::cout << std::left << std::setw(4) << i + 1 << ' ';
			}
			std::cout << '\n';
			for (int i = 0; i < edge_map.size(); i++)
			{
				std::cout << std::left << std::setw(4) << i + 1 << ' ';
				for (int j = 0; j < edge_map.size(); j++)
				{
					std::cout << std::left << std::setw(4) << edge_map[i][j] << ' ';
				}
				std::cout << '\n';
			}
			break;
		}
		case 12:
		{

		
			running = false;
			break;
		}
		case 13:
		{
			vector<int> path;
			int i;
			cin >> i;
			TSP(m_G, i, path);
			int sum = 0;
			for (int i = 0; i < path.size() - 1; i++)
			{
				cout << m_G->edge_map[path[i]][path[i + 1]].distance << '\n';
				sum += m_G->edge_map[path[i]][path[i + 1]].distance;
			}
			cout << sum;
			break;
		}
		case 14:
		{
			break;
		}
		default:
			break;
		}
	}
}