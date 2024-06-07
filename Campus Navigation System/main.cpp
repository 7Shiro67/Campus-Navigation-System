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
		cout << "图书管理系统菜单:" << endl;
		cout << "1.  建立图书信息表\n";
		cout << "2.  查看图书信息表\n";
		cout << "3.  插入图书信息\n";
		cout << "4.  删除图书信息\n";
		cout << "5.  排序图书信息\n";
		cout << "6.  统计图书数量\n";
		cout << "7.  修改图书信息\n";
		cout << "8.  查找图书信息\n";
		cout << "9.  从文件导入图书信息表\n";
		cout << "10. 导出图书信息表到文件\n";
		cout << "11. 合并图书信息表\n";
		cout << "12. 收藏图书\n";
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
			if (init_emptylist(list1))
			{
				cout << "链表创建成功\n";
			}
			else
			{
				cout << "链表创建失败\n";
			}
			break;
		case 2:
			if (!travel_list(list1))
			{
				cout << "输出失败\n";
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
			cout << "输入书的ISBN:";	cin >> b.ISBN;
			while (strlen(b.ISBN) != 13)
			{
				cout << "ISBN位数错误，请重新输入:";
				cin >> b.ISBN;
			}
			cout << "输入书的名字:";	cin >> b.book_name;
			cout << "输入书的价格:";	cin >> b.price;
			cout << "输入位置:";		cin >> pos;

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
				cout << "插入失败\n";
			}
			else
			{
				cout << "插入成功\n";
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
			cout << "输入删除位置:"; cin >> pos;
			if (!delete_node(list1, pos, b1))
			{
				cout << "删除失败\n";
			}
			else
			{
				cout << "删除成功，删除的节点的值为" << b1.ISBN << ' '
					<< b1.book_name << ' ' << b1.price << '\n';
			}
			break;
		}
		case 5:
		{
			int choice_2, choice_3;
			cout << "请选择排序方式:(1.按照价格 2.按照ISBN)" << endl;
			cin >> choice_3;

			while (true)
			{
				if (choice_3 == 1)
				{
					while (true)
					{
						cout << "请选择排序方式:(1.升序 2.降序)" << endl;
						cin >> choice_2;
						if (choice_2 == 1) {
							sort(list1, compare_price);
							cout << "排序成功！" << endl;
							break;
						}
						else if (choice_2 == 2) {
							sort(list1, compare_price2);
							cout << "排序成功！" << endl;
							break;
						}
						else
						{
							cout << "请输入合法的选项(1/2)" << endl;
							cin >> choice_2;
							continue;
						}
					}
					break;
				}
				else if (choice_3 == 2)
				{
					{
						cout << "请选择排序方式:(1.升序 2.降序)" << endl;
						cin >> choice_2;
						while (true)
						{
							if (choice_2 == 1) {
								sort(list1, compare_ISBN);
								cout << "排序成功！" << endl;
								break;
							}
							else if (choice_2 == 2) {
								sort(list1, compare_ISBN2);
								cout << "排序成功！" << endl;
								break;
							}
							else
							{
								cout << "请输入合法的选项(1/2)" << endl;
								cin >> choice_2;
								continue;
							}
						}
						break;
					}
				}
				else
				{
					cout << "请输入合法的选项(1/2)" << endl;
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
				cout << "获取数量失败\n";
			}
			cout << "图书的数量为:" << num << '\n';
			break;
		}
		case 7:
		{
			char book_name[25], book_ISBN[20];
			double book_price;
			cout << "请输入ISBN:"; cin >> book_ISBN;
			while (strlen(book_ISBN) != 13)
			{
				cout << "ISBN位数错误，请重新输入:";
				cin >> book_ISBN;
			}
			cout << "请输入修改后的书本名字:"; cin >> book_name;
			cout << "请输入修改后的书本价格:"; cin >> book_price;
			if (book_price >= 0 && change_node(list1, book_ISBN, book_name, book_price))
			{
				cout << "修改成功\n";
			}
			else
			{
				cout << "修改失败\n";
			}
			break;
		}
		case 8:
		{
			char book_ISBN[20];
			mynode* temp = nullptr;
			cout << "请输入ISBN或书名:"; cin >> book_ISBN;
			if (search_node(list1, book_ISBN, &temp) && temp != nullptr)
			{
				cout << "该书的ISBN为:" << temp->data.ISBN << "\n"
					<< "书名为:" << temp->data.book_name << "\n"
					<< "价格为:" << temp->data.price << "\n";
			}
			else
			{
				cout << "查找失败\n";
			}
			break;
		}
		case 9:
		{
			ifstream ifile;
			string s;
			string s2;
			cout << "文件列表:" << endl;
			string inputPath = "File-Input/";
			DIR* dir = opendir(inputPath.c_str());
			if (dir == nullptr)
			{
				cout << "读取失败";
				break;
			}
			struct dirent* entry;
			while (entry = readdir(dir))
			{
				if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
					cout << entry->d_name << '\n';
			}
			cout << "输入文件名称:\n";
			cin >> s;
			ifile.open(inputPath + "/" + s, ios::in);
			if (!ifile.is_open())
			{
				cout << "文件读取失败(可能是文件名称错误)" << endl;
				break;
			}
			ifile >> s2 >> s2 >> s2;
			if (add_filetolist(list1, ifile))
			{
				cout << "成功读取文件进入链表" << endl;
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
				cout << "导出" << s << "成功\n";
			else
			{
				cout << "导出失败\n";
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
			cout << "请输入收藏的书籍序号：\n";
			string stemp;
			cout << "输入你的选择:";
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
				cout << "添加成功" << '\n';
			}
			else
			{
				cout << "添加失败" << '\n';
			}
			break;
		}
		case 13:
		{
			if (!travel_list(list2))
			{
				cout << "输出失败\n";
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
			cout << "输入值出错\n";
			break;
		}
		if (run_status != 15)
		{
			string jg;
			do {
				cout << "是否要继续使用图书管理系统?(y/n)" << endl;
				cin >> jg;
				if (jg != "y" && jg != "Y" && jg != "n" && jg != "N") {
					cout << "请输入有效选项(y/n)" << endl;
				}
				if (jg == "n" || jg == "N") {
					cout << "感谢使用，再见！" << endl;
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