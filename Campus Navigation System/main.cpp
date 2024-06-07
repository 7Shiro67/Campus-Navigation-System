#include"CNS.h"

int main()
{
	bool running = true;
	int ne_stats = 0;
	while (running)
	{
		if (ne_stats == 0)
		{
			system("cls");
			draw_sign(ne_stats, peo);
		}
		else if (ne_stats == 1)
		{
			system("cls");
			draw_ui(ne_stats, peo);
		}
		else if (ne_stats == 2)
		{
			running = false;
		}
	}
	return 0;
}

void draw_ui(int& next_status)

	bool running = true;
	ifstream ifile;
	ifile.open("collection/" + ptemp.name + ".txt");
	if (ifile.is_open())
	{
		add_filetolist(list2, ifile);
		ifile.close();
	}
	while (running)
	{
		cout << "----------------------------------------\n";
		cout << "ͼ�����ϵͳ�˵�:" << endl;
		cout << "1.  ����ͼ����Ϣ��\n";
		cout << "2.  �鿴ͼ����Ϣ��\n";
		cout << "3.  ����ͼ����Ϣ\n";
		cout << "4.  ɾ��ͼ����Ϣ\n";
		cout << "5.  ����ͼ����Ϣ\n";
		cout << "6.  ͳ��ͼ������\n";
		cout << "7.  �޸�ͼ����Ϣ\n";
		cout << "8.  ����ͼ����Ϣ\n";
		cout << "9.  ���ļ�����ͼ����Ϣ��\n";
		cout << "10. ����ͼ����Ϣ���ļ�\n";
		cout << "11. �ϲ�ͼ����Ϣ��\n";
		cout << "12. �ղ�ͼ��\n";
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
			if (init_emptylist(list1))
			{
				cout << "�������ɹ�\n";
			}
			else
			{
				cout << "������ʧ��\n";
			}
			break;
		case 2:
			if (!travel_list(list1))
			{
				cout << "���ʧ��\n";
			}
			break;
		case 3:
		{
			book b{};
			int pos;
			mynode* temp;
			bool flag = true;
			if (list1.head->next == nullptr)
			{
				cout << "it is a empty list\n";
			}
			if (export2_list(list1, cout) == oneERROR)
			{
				cout << "list is exported failed\n";
			}
			cout << "�������ISBN:";	cin >> b.ISBN;
			while (strlen(b.ISBN) != 13)
			{
				cout << "ISBNλ����������������:";
				cin >> b.ISBN;
			}
			cout << "�����������:";	cin >> b.book_name;
			cout << "������ļ۸�:";	cin >> b.price;
			cout << "����λ��:";		cin >> pos;

			if (b.price < 0)
			{
				flag = false;
			}
			if (list1.head != nullptr && search_node(list1, b.ISBN, &temp))
			{
				if (temp != nullptr && strcmp(b.book_name, temp->data.book_name) == 0 && b.price == temp->data.price)
				{
					flag = false;
				}
			}
			if (!flag || !insert_list(list1, pos, b))
			{
				cout << "����ʧ��\n";
			}
			else
			{
				cout << "����ɹ�\n";
			}
			break;
		}
		case 4:
		{
			int pos;
			book b1;
			if (export2_list(list1, cout) == oneERROR)
			{
				cout << "list is exported failed\n";
			}
			cout << "����ɾ��λ��:"; cin >> pos;
			if (!delete_node(list1, pos, b1))
			{
				cout << "ɾ��ʧ��\n";
			}
			else
			{
				cout << "ɾ���ɹ���ɾ���Ľڵ��ֵΪ" << b1.ISBN << ' '
					<< b1.book_name << ' ' << b1.price << '\n';
			}
			break;
		}
		case 5:
		{
			int choice_2, choice_3;
			cout << "��ѡ������ʽ:(1.���ռ۸� 2.����ISBN)" << endl;
			cin >> choice_3;

			while (true)
			{
				if (choice_3 == 1)
				{
					while (true)
					{
						cout << "��ѡ������ʽ:(1.���� 2.����)" << endl;
						cin >> choice_2;
						if (choice_2 == 1) {
							sort(list1, compare_price);
							cout << "����ɹ���" << endl;
							break;
						}
						else if (choice_2 == 2) {
							sort(list1, compare_price2);
							cout << "����ɹ���" << endl;
							break;
						}
						else
						{
							cout << "������Ϸ���ѡ��(1/2)" << endl;
							cin >> choice_2;
							continue;
						}
					}
					break;
				}
				else if (choice_3 == 2)
				{
					{
						cout << "��ѡ������ʽ:(1.���� 2.����)" << endl;
						cin >> choice_2;
						while (true)
						{
							if (choice_2 == 1) {
								sort(list1, compare_ISBN);
								cout << "����ɹ���" << endl;
								break;
							}
							else if (choice_2 == 2) {
								sort(list1, compare_ISBN2);
								cout << "����ɹ���" << endl;
								break;
							}
							else
							{
								cout << "������Ϸ���ѡ��(1/2)" << endl;
								cin >> choice_2;
								continue;
							}
						}
						break;
					}
				}
				else
				{
					cout << "������Ϸ���ѡ��(1/2)" << endl;
					cin >> choice_3;
					continue;
				}
			}
			break;
		}
		case 6:
		{
			int  num;
			if (!make_cnt(list1, num))
			{
				cout << "��ȡ����ʧ��\n";
			}
			cout << "ͼ�������Ϊ:" << num << '\n';
			break;
		}
		case 7:
		{
			char book_name[25], book_ISBN[20];
			double book_price;
			cout << "������ISBN:"; cin >> book_ISBN;
			while (strlen(book_ISBN) != 13)
			{
				cout << "ISBNλ����������������:";
				cin >> book_ISBN;
			}
			cout << "�������޸ĺ���鱾����:"; cin >> book_name;
			cout << "�������޸ĺ���鱾�۸�:"; cin >> book_price;
			if (book_price >= 0 && change_node(list1, book_ISBN, book_name, book_price))
			{
				cout << "�޸ĳɹ�\n";
			}
			else
			{
				cout << "�޸�ʧ��\n";
			}
			break;
		}
		case 8:
		{
			char book_ISBN[20];
			mynode* temp = nullptr;
			cout << "������ISBN������:"; cin >> book_ISBN;
			if (search_node(list1, book_ISBN, &temp) && temp != nullptr)
			{
				cout << "�����ISBNΪ:" << temp->data.ISBN << "\n"
					<< "����Ϊ:" << temp->data.book_name << "\n"
					<< "�۸�Ϊ:" << temp->data.price << "\n";
			}
			else
			{
				cout << "����ʧ��\n";
			}
			break;
		}
		case 9:
		{
			ifstream ifile;
			string s;
			string s2;
			cout << "�ļ��б�:" << endl;
			string inputPath = "File-Input/";
			DIR* dir = opendir(inputPath.c_str());
			if (dir == nullptr)
			{
				cout << "��ȡʧ��";
				break;
			}
			struct dirent* entry;
			while (entry = readdir(dir))
			{
				if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
					cout << entry->d_name << '\n';
			}
			cout << "�����ļ�����:\n";
			cin >> s;
			ifile.open(inputPath + "/" + s, ios::in);
			if (!ifile.is_open())
			{
				cout << "�ļ���ȡʧ��(�������ļ����ƴ���)" << endl;
				break;
			}
			ifile >> s2 >> s2 >> s2;
			if (add_filetolist(list1, ifile))
			{
				cout << "�ɹ���ȡ�ļ���������" << endl;
			}
			ifile.close();
			break;
		}
		case 10:
		{
			ofstream ofile;
			int i = 1;
			char s[50];
			ifstream f;
			do
			{
				f.close();
				sprintf_s(s, 50, "File-output\\export%d.txt", i);
				i++;
				f.open(s);
			} while (f.good());
			f.close();
			ofile.open(s);
			if (export_list(list1, ofile))
				cout << "����" << s << "�ɹ�\n";
			else
			{
				cout << "����ʧ��\n";
			}
			ofile.close();
			break;
		}
		case 11:
			Merge_file(list1);
			break;
		case 12:
		{
			int serial;
			if (export2_list(list1, cout) == oneERROR)
			{
				cout << "list is exported failed\n";
			}
			cout << "�������ղص��鼮��ţ�\n";
			string stemp;
			cout << "�������ѡ��:";
			cin >> serial;
			mynode* node;
			if (find_n_list(list1, serial, node) && node != nullptr)
			{
				mynode* travel_node = list2.head;
				while (travel_node->next)
				{
					travel_node = travel_node->next;
				}
				mynode* temp = new mynode;
				travel_node->next = temp;
				temp->data = node->data;
				temp->next = nullptr;
				cout << "��ӳɹ�" << '\n';
			}
			else
			{
				cout << "���ʧ��" << '\n';
			}
			break;
		}
		case 13:
		{
			if (!travel_list(list2))
			{
				cout << "���ʧ��\n";
			}
			break;
		}
		case 14:
		{
			running = false;
			ofstream ofile;
			ofile.open("collection/" + ptemp.name + ".txt", ios::trunc);
			export_list(list2, ofile);
			next_status = 0;
			delete_list(list1);
			break;
		}
		default:
			cout << "����ֵ����\n";
			break;
		}
		if (run_status != 15)
		{
			string jg;
			do {
				cout << "�Ƿ�Ҫ����ʹ��ͼ�����ϵͳ?(y/n)" << endl;
				cin >> jg;
				if (jg != "y" && jg != "Y" && jg != "n" && jg != "N") {
					cout << "��������Чѡ��(y/n)" << endl;
				}
				if (jg == "n" || jg == "N") {
					cout << "��лʹ�ã��ټ���" << endl;
					running = false;
					ofstream ofile;
					ofile.open("collection/" + ptemp.name + ".txt", ios::trunc);
					export_list(list2, ofile);
					next_status = 0;
					delete_list(list1);
				}
				system("cls");
			} while (jg != "y" && jg != "Y" && jg != "n" && jg != "N");
		}
	}
}