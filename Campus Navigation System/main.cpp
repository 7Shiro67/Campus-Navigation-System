#include"CNS.h"

using namespace std;

void draw_ui1();
void draw_ui2();


int main()
{
	bool running = true;
	while (running)
	{
		cout << "���������ѡ��:" << endl;
		cout << "1.�ڽӱ�" << endl;
		cout << "2.�ڽӾ���" << endl;
		cout << "3.�˳�" << endl;
		int run_status;
		cin >> run_status;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "�����������������" << endl;
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
			cout << "�������" << endl;
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
		cout << "ͼ�����ϵͳ�˵�:" << endl;
		cout << "1.  ��ͼ���ڽӱ�Ĺ���\n";
		cout << "2.  �����ͼ���ڽӱ�\n";
		cout << "3.  �����ͼ����Ϊ�ڽӱ�\n";
		cout << "4.  ������ͼ����\n";
		cout << "5.  ��ͼ���ڽӱ���޸�\n";
		cout << "6.  ��ͼ���ڽӱ��ɾ��\n";
		cout << "7.  ��ͼ���ڽӱ�Ĳ���\n";
		cout << "8.  �����о���Ĺ����������������о����Լ����ξ�����ܾ���\n";
		cout << "9.  �����ָ�������������ͼ�����о������̾��뼰�����ĵص�\n";
		cout << "10. �����ָ���ľ���(���)������һָ������(�յ�)����̾��룬�Լ������ľ���\n";
		cout << "11. ���ͼ������������֮�����̾���\n";
		cout << "12. �������ļ��\n";
		cout << "14. ����������Ż�Ƽ�\n";
		cout << "15. �˳�\n";
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
			if (create_L_map(l_G))
			{
				cout << "�ڽӱ����ɹ�"<<endl;
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
			free(l_G);
			create_L_map(l_G);
			vector<string> v_s;
			Display_FilesList(v_s);
			cout << "�������ļ������:";
			if (import_L_map(l_G,v_s))
			{
				cout << "����ɹ�" << endl;
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
			cout << "��������Ҫ�޸ĵ�ѡ�1���ߣ�2���㣩��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				show_node(l_G);
				cout << "�������޸ĺ�ߵ�ֵ�Լ��ߵ������յ㣨�ÿո������" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				change_L_edge(l_G, src2, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				show_node(l_G);
				cout << "�������޸Ķ��������Լ��޸ĳɵ����ƣ��ÿո������" << endl;
				cin >> pos >> val;
				pos--;
				change_L_node(l_G, val, pos);
			}
			else
			{
				cout << "������ֵ����" << endl;
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
			cout << "��������Ҫɾ����ѡ�1���ߣ�2���㣩��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int  start, end;
				show_node(l_G);
				cout << "������Ҫɾ���ıߵ������յ㣨�ÿո������" << endl;
				cin >> start >> end;
				start--, end--;
				delete_L_edge(l_G, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				show_node(l_G);
				cout << "������Ҫɾ���Ķ�������" << endl;
				cin >> pos;
				pos--;
				delete_L_node(l_G, pos);
			}
			else
			{
				cout << "������ֵ����" << endl;
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
			cout << "��������Ҫ�����ѡ�1���ߣ�2���㣩��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				show_node(l_G);
				cout << "������Ҫ����ıߵ�ֵ�Լ��ߵ������յ㣨�ÿո������:" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				insert_L_edge(l_G, src2, start, end);
			}
			else if (choice == 2)
			{
				string val;
				show_node(l_G);
				cout << "��������붥������ƣ��ÿո������:" << endl;
				cin  >> val;
				node temp{ val };
				insert_L_node(l_G, temp);
			}
			else
			{
				cout << "������ֵ����" << endl;
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
			cout << "�����б�:" << endl;
			for (int i = 0; i < l_G->node_map.size(); i++)
			{
				cout << i << ". " << fixed << l_G->node_map[i].name << endl;
			}
			cout << "��������ʼ������: ";
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
			cout << "�����붥�����" << endl;
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
			cout << "��������㶥�����" << endl;
			int start;
			cin >> start;
			cout << "�������յ㶥�����" << endl;
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
			show_node(m_G);
			unordered_map<string, string> temp;
			if (!import_introduction(temp))
			{
				cout << "�����ļ�ʧ��" << endl;
				break;
			}
			cout << "��������Ҫ��ѯ���ĵص�����" << endl;
			int i;
			cin >> i;
			string temp_s = m_G->node_map[i - 1].name;
			cout << temp[temp_s] << endl;
			break;
		}
		case 13:
		{
			if (!check_map_null(l_G))
			{
				break;
			}
			show_node(l_G);
			cout << "�����뾰�����" << endl;
			int start;
			cin >> start;
			vector<vector<int>> dis;
			vector<vector<int>> path;
			Floyd(l_G, dis, path);
			unordered_map<string, string> activation;
			import_activation(activation);
			show_hot_place_activation<ALgraph>(l_G, activation, start, dis);
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

void draw_ui2()
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
		cout << "3.  �����ͼ����Ϊ�ڽӾ���\n";
		cout << "4.  ������ͼ����\n";
		cout << "5.  ��ͼ���ڽӾ�����޸�\n";
		cout << "6.  ��ͼ���ڽӾ����ɾ��\n";
		cout << "7.  ��ͼ���ڽӾ���Ĳ���\n";
		cout << "8.  �����о���Ĺ����������������о����Լ����ξ�����ܾ���\n";
		cout << "9.  �����ָ�������������ͼ�����о������̾��뼰�����ĵص�\n";
		cout << "10. �����ָ���ľ���(���)������һָ������(�յ�)����̾��룬�Լ������ľ���\n";
		cout << "11. ���ͼ������������֮�����̾���\n";
		cout << "12. �������ļ��\n";
		cout << "13. �й�ѡ��8����һ��ʵ�ָ�������+̰��ʵ��\n";
		cout << "14. ��С�������븥������ʵ�ֵĶԱ�\n";
		cout << "15. ����������Ż�Ƽ�\n";
		cout << "16. �˳�\n";
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
			if (create_M_map(m_G))
			{
				cout << "�ڽӾ��󴴽��ɹ�"<<endl;
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
			free(m_G);
			create_M_map(m_G);
			vector<string> v_s;
			Display_FilesList(v_s);
			cout << "�������ļ������:";
			if (import_M_map(m_G,v_s))
			{
				cout << "����ɹ�" << endl;
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
			if (!check_map_null(m_G))
			{
				break;
			}
			int choice = 0;
			cout << "��������Ҫ�޸ĵ�ѡ�1���ߣ�2���㣩��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				cout << "�������޸ĺ�ߵ�ֵ�Լ��ߵ������յ㣨�ÿո������" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				change_M_edge(m_G, src2, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				cout << "�������޸Ķ��������Լ��޸ĳɵ����ƣ��ÿո������" << endl;
				cin >> pos >> val;
				pos--;
				change_M_node(m_G, val, pos);
			}
			else
			{
				cout << "������ֵ����" << endl;
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
			cout << "��������Ҫɾ����ѡ�1���ߣ�2���㣩��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int  start, end;
				cout << "������Ҫɾ���ıߵ������յ㣨�ÿո������" << endl;
				cin >> start >> end;
				start--, end--;
				delete_M_edge(m_G, start, end);
			}
			else if (choice == 2)
			{
				int pos;
				string val;
				cout << "������Ҫɾ���Ķ�������" << endl;
				cin >> pos;
				pos--;
				delete_M_node(m_G, pos);
			}
			else
			{
				cout << "������ֵ����" << endl;
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
			cout << "��������Ҫ�����ѡ�1���ߣ�2���㣩��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				int src, start, end;
				edge src2;
				cout << "������Ҫ����ıߵ�ֵ�Լ��ߵ������յ㣨�ÿո������:" << endl;
				cin >> src >> start >> end;
				start--, end--;
				src2.distance = src;
				insert_M_edge(m_G, src2, start, end);
			}
			else if (choice == 2)
			{
				string val;
				cout << "��������붥������ƣ��ÿո������:" << endl;
				cin >> val;
				node temp{ val };
				insert_M_node(m_G, temp);
			}
			else
			{
				cout << "������ֵ����" << endl;
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
			cout << "�����б�:" << endl;
			for (int i = 0; i < m_G->node_map.size(); i++)
			{
				cout<<i<<". "<<fixed<<m_G->node_map[i].name<<endl;
			}
			cout << "��������ʼ������: ";
			cin >> start;
			int totalcost;
			TSP(start, m_G, totalcost,1);
			break;
		}
		case 9:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			show_node(m_G);
			cout << "�����붥�����" << endl;
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
			cout << "��������㶥�����" << endl;
			int start;
			cin >> start;
			cout << "�������յ㶥�����" << endl;
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
			show_node(m_G);
			unordered_map<string, string> temp;
			if (!import_introduction(temp))
			{
				cout << "�����ļ�ʧ��" << endl;
				break;
			}
			cout << "��������Ҫ��ѯ���ĵص�����" << endl;
			int i;
			cin >> i;
			string temp_s = m_G->node_map[i - 1].name;
			cout << temp[temp_s] << endl;
			break;
		}
		case 13:
		{
			vector<int> path;
			int i;
			cin >> i;
			oneTSP(m_G, i, path);
			int sum = 0;
			for (int i = 0; i < path.size() - 1; i++)
			{
				cout << m_G->edge_map[path[i]][path[i + 1]].distance << ' ';
				sum += m_G->edge_map[path[i]][path[i + 1]].distance;
			}
			cout << sum << '\n';
			break;
		}
		case 14:
		{
			int cnt1, cnt2;
			double res = show_difference_TSP(m_G,cnt1,cnt2);
			cout << "��С�������㷨���ŵ������" << cnt1 << "��" << endl;
			cout << "���·���㷨���ŵ������" << cnt2 << "��" << endl;
			cout << res << endl;
			break;
		}
		case 15:
		{
			if (!check_map_null(m_G))
			{
				break;
			}
			show_node(m_G);
			cout << "�����뾰�����" << endl;
			int start;
			cin >> start;
			vector<vector<int>> dis;
			vector<vector<int>> path;
			Floyd(m_G, dis, path);
			unordered_map<string, string> activation;
			import_activation(activation);
			show_hot_place_activation<AMgraph>(m_G, activation, start, dis);
			break;
		}
		case 16:
		{
			running = false;
			break;
		}
		default:
			break;
		}
	}
}
