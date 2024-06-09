#include"CNS.h"

using namespace std;

void draw_ui();

int main()
{
	draw_ui();
	return 0;

}

void draw_ui()
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
		cout << "3.  地图的邻接表的构建\n";
		cout << "4.  输出地图的邻接表\n";
		cout << "5.  导入地图数据为邻接矩阵\n";
		cout << "6.  导入地图数据为邻接表\n";
		cout << "7.  导出地图数据\n";
		cout << "8.  地图的邻接矩阵的修改\n";
		cout << "9.  地图的邻接矩阵的删除\n";
		cout << "10. 地图的邻接表的修改\n";
		cout << "11. 地图的邻接表的删除\n";
		cout << "12. 打卡所有景点的过程中所经过的所有景点以及各段距离和总距离(邻接矩阵)\n";
		cout << "13. 打卡所有景点的过程中所经过的所有景点以及各段距离和总距离(邻接表)\n";
		cout << "14. 输出从指定点出发，到达图中所有景点的最短距离及经过的地点\n";
		cout << "15. 输出从指定的景点(起点)到达另一指定景点(终点)的最短距离，以及经过的景点\n";
		cout << "16. 输出图中所有两景点之间的最短距离\n";
		cout << "17. 退出\n";
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
			create_M_map(m_G);
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
			create_L_map(l_G);
			break;
		}
		case 4:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			show_L_map(l_G);
			break;
		}
		case 5:
		{
			Display_FilesList();
			if (!check_map_null(m_G))
			{
				break;
			}
			import_M_map(m_G);
			break;
		}
		case 6:
		{
			Display_FilesList();
			if (!check_map_null(l_G))
			{
				break;
			}
			import_L_map(l_G);
			break;
		}
		case 7:
		{
			
			break;
		}
		case 8:
		{
			
			break;
		}
		case 9:
		{
			
			break;
		}
		case 10:
		{
			
			break;
		}
		case 11:
			
			break;
		case 12:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			string name;
			int start = -1;
			cin >> name;
			for (int i = 0; i < m_G->node_map.size(); i++)
			{
				if (m_G->node_map[i].name == name) 
				{
					start = i;
					break;
				}
			}
			TSP(start,m_G);
		}
		case 13:
		{
			break;
		}
		case 17:
		{
			running = false;
			break;
		}
		default:
			break;
		}
	}
}