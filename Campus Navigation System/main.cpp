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
		cout << "ͼ�����ϵͳ�˵�:" << endl;
		cout << "1.  ��ͼ���ڽӾ���Ĺ���\n";
		cout << "2.  �����ͼ���ڽӾ���\n";
		cout << "3.  ��ͼ���ڽӱ�Ĺ���\n";
		cout << "4.  �����ͼ���ڽӱ�\n";
		cout << "5.  �����ͼ����Ϊ�ڽӾ���\n";
		cout << "6.  �����ͼ����Ϊ�ڽӱ�\n";
		cout << "7.  ������ͼ����\n";
		cout << "8.  ��ͼ���ڽӾ�����޸�\n";
		cout << "9.  ��ͼ���ڽӾ����ɾ��\n";
		cout << "10. ��ͼ���ڽӱ���޸�\n";
		cout << "11. ��ͼ���ڽӱ��ɾ��\n";
		cout << "12. �����о���Ĺ����������������о����Լ����ξ�����ܾ���(�ڽӾ���)\n";
		cout << "13. �����о���Ĺ����������������о����Լ����ξ�����ܾ���(�ڽӱ�)\n";
		cout << "14. �����ָ�������������ͼ�����о������̾��뼰�����ĵص�\n";
		cout << "15. �����ָ���ľ���(���)������һָ������(�յ�)����̾��룬�Լ������ľ���\n";
		cout << "16. ���ͼ������������֮�����̾���\n";
		cout << "17. �˳�\n";
		cout << "----------------------------------------\n";
		unsigned int run_status;
		cout << "�������ѡ��:";
		cin >> run_status;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "�����������������" << endl;
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