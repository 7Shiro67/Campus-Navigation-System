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
		cout << "ͼ�����ϵͳ�˵�:" << endl;
		cout << "1.  ��ͼ���ڽӾ���Ĺ���\n";
		cout << "2.  �����ͼ���ڽӾ���\n";
		cout << "2.  �����ͼ���ڽӾ���\n";
		cout << "3.  ��ͼ���ڽӱ�Ĺ���\n";
		cout << "4.  �����ͼ���ڽӱ�\n";
		cout << "2.  �����ͼ����\n";
		cout << "2.  ������ͼ����\n";
		cout << "5.  ��ͼ���ڽӾ�����޸�\n";
		cout << "6.  ��ͼ���ڽӾ����ɾ��\n";
		cout << "7.  ��ͼ���ڽӱ���޸�\n";
		cout << "8.  ��ͼ���ڽӱ��ɾ��\n";
		cout << "9.  �����о���Ĺ����������������о����Լ����ξ�����ܾ���\n";
		cout << "10. �����ָ�������������ͼ�����о������̾��뼰�����ĵص�\n";
		cout << "11. �����ָ���ľ���(���)������һָ������(�յ�)����̾��룬�Լ������ľ���\n";
		cout << "12. ���ͼ������������֮�����̾���\n";
		cout << "13. �鿴�ղؼ�\n";
		cout << "14. �˳�\n";
		cout << "----------------------------------------\n";
		unsigned int run_status;
		string stemp;
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