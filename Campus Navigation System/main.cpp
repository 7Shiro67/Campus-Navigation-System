#include"CNS.h"

using namespace std;

int main()
{
	draw_ui();
	return 0;
}

void draw_ui()
{
	bool running = true;
	while (running)
	{
		cout << "----------------------------------------\n";
		cout << "图书管理系统菜单:" << endl;
		cout << "1.  地图的邻接矩阵的构建\n";
		cout << "2.  输出地图的邻接矩阵\n";
		cout << "2.  输出地图的邻接矩阵\n";
		cout << "3.  地图的邻接表的构建\n";
		cout << "4.  输出地图的邻接表\n";
		cout << "2.  导入地图数据\n";
		cout << "2.  导出地图数据\n";
		cout << "5.  地图的邻接矩阵的修改\n";
		cout << "6.  地图的邻接矩阵的删除\n";
		cout << "7.  地图的邻接表的修改\n";
		cout << "8.  地图的邻接表的删除\n";
		cout << "9.  打卡所有景点的过程中所经过的所有景点以及各段距离和总距离\n";
		cout << "10. 输出从指定点出发，到达图中所有景点的最短距离及经过的地点\n";
		cout << "11. 输出从指定的景点(起点)到达另一指定景点(终点)的最短距离，以及经过的景点\n";
		cout << "12. 输出图中所有两景点之间的最短距离\n";
		cout << "13. 查看收藏夹\n";
		cout << "14. 退出\n";
		cout << "----------------------------------------\n";
		unsigned int run_status;
		string stemp;
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
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			
			break;
		}
		case 4:
		{
			
			break;
		}
		case 5:
		{
			
			break;
		}
		case 6:
		{
			
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
			
			break;
		}
		case 13:
		{
			
			break;
		}
		case 14:
		{
			running = false;
			break;
		}
		default:
			break;
		}
	}
}