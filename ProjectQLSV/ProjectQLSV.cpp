#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
struct Students {
	std::string name;
	int age;
	float point;
};
struct Node {
	Students student;
	Node* next;
};
struct LinkedList {
	Node* head;
	int length;
};
void clear() {
	std::cout << "Press any key to continue . . .";
	char x;
	x = _getch();
	if (x >= 0 && x <= 127)
		std::system("cls");
}
void print(LinkedList list) {
	if (list.head == NULL) {
		std::cout << "Chua Co Thong Tin Sinh Vien !\n";
		clear();
		return;
	}
	std::cout << "[1] In Danh Sach Sinh Vien\n";
	Node* p = list.head;
	int stt = 1;
	std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
	std::cout << "\t\t\t|" << std::setfill(' ') << " STT    |" << " Ho Ten             |" << " Tuoi    |" << " Diem   |\n";
	while (p != NULL) {
		std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
		std::cout << "\t\t\t|" << std::setfill(' ') << std::setw(1) << " " << std::setw(7) << std::left << stt++
			<< std::setw(2) << "|" << std::setw(19) << p->student.name
			<< std::setw(2) << "|" << std::setw(8) << p->student.age
			<< std::setw(2) << "|" << std::setw(7) << p->student.point
			<< std::setw(2) << "|" << std::right << "\n";
		p = p->next;
	}
	std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
	clear();
}
void add(LinkedList* list, Students student) {
	Node* node = new Node({ student, NULL });
	list->length++;
	if (list->head == NULL) {
		list->head = node;
		return;
	}
	Node* p = list->head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void add(LinkedList* list) {
	std::string name;
	int age;
	float point;
	std::cout << "[2] Them Sinh Vien\n";
	std::cout << "\t(!) Nhap Ten: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "\t(!) Nhap Tuoi: ";
	std::cin >> age;
	std::cout << "\t(!) Nhap Diem: ";
	std::cin >> point;
	Node* node = new Node({ name, age, point, NULL });
	list->length++;
	if (list->head == NULL) {
		list->head = node;
		std::cout << "Da Them Sinh Vien Co Ten " << name << " Tuoi " << age << " Diem " << point << "\n";
		clear();
		return;
	}
	Node* p = list->head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
	std::cout << "Da Them Sinh Vien Co Ten " << name << " Tuoi " << age << " Diem " << point << "\n";
	clear();
}
void correct(LinkedList* list) {
	Node* p = list->head;
	bool check = true;
	while (check) {
		std::cout << "[3] Sua Thong Tin Sinh Vien\n";
		std::cout << "\t(!) Nhap So Thu Tu Sinh Vien Can Sua: ";
		int index; std::cin >> index;
		if (index > 0 && index <= list->length) {
			index = index - 1;
			int i = 0;
			while (p != NULL) {
				if (i == index) {
					int command;
					std::cout << "\t(!) 1 - Sua Ten\n"
						<< "\t(!) 2 - Sua Tuoi\n"
						<< "\t(!) 3 - Sua Diem\n"
						<< "\tMoi Nhap Lenh: ";
					std::cin >> command;
					if (command == 1) {
						std::string new_Name;
						std::cout << "\t(?) Nhap Ten Moi: ";
						std::cin.ignore();
						std::getline(std::cin, new_Name);
						p->student.name = new_Name;
						clear();
					}
					else if (command == 2) {
						int new_Age;
						std::cout << "\t(?) Nhap Tuoi Moi: ";
						std::cin >> new_Age;
						p->student.age = new_Age;
						clear();
					}
					else if (command == 3) {
						float new_Point;
						std::cout << "\t(?) Nhap Diem Moi: ";
						std::cin >> new_Point;
						p->student.point = new_Point;
						clear();
					}
					check = false;
					break;
				}
				p = p->next;
				i++;
			}
		}
		else std::cout << "Khong Ton Tai Vi Tri Nay Vui Long Nhap Lai !!\n";
	}
}
void remove(LinkedList* list) {
	int index;
	bool check = true;
	std::cout << "[4] Xoa Sinh Vien\n";
	while (check) {
		std::cout << "\t(?) Nhap So Thu Tu Sinh Vien Can Xoa: ";
		std::cin >> index;
		if (index > 0 && index <= list->length) {
			index = index - 1;
			list->length--;
			if (index == 0) {
				list->head = list->head->next;
				std::cout << "\t(!) Da Xoa Sinh Vien Co STT La " << 1 << "\n";
				clear();
				return;
			}
			int i = 1;
			Node* p = list->head->next;
			Node* p_back = list->head;
			while (p != NULL) {
				if (i == index) {
					p_back->next = p->next;
					std::cout << "(!) Da Xoa Sinh Vien Co STT La " << index + 1 << "\n";
					clear();
					return;
				}
				i++;
				p_back = p;
				p = p->next;
			}
		}
		else
			std::cout << "Khong Ton Tai Vi Tri Nay Vui Long Nhap Lai !!\n";
	}
}
void find(LinkedList list) {
	Node* p = list.head;
	std::cout << "[5] Tim Kiem\n";
	std::string character;
	std::cin.ignore();
	std::cout << "\t(?) Nhap Ki Tu: ";
	std::getline(std::cin, character);
	int length = 0;
	Students list_sv[100];
	while (p != NULL) {
		int i = (p->student.name).find(character);
		if (i != std::string::npos) {
			list_sv[length++] = p->student;
		}
		p = p->next;
	}
	std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
	std::cout << "\t\t\t|" << std::setfill(' ') << " STT    |" << " Ho Ten             |" << " Tuoi    |" << " Diem   |\n";
	for (int i = 0; i < length; i++) {
		std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
		std::cout << "\t\t\t|" << std::setfill(' ') << std::setw(1) << " " << std::setw(7) << std::left << i + 1
			<< std::setw(2) << "|" << std::setw(19) << list_sv[i].name
			<< std::setw(2) << "|" << std::setw(8) << list_sv[i].age
			<< std::setw(2) << "|" << std::setw(7) << list_sv[i].point
			<< std::setw(2) << "|" << std::right << "\n";
	}
	std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
	clear();
}
std::string get_name(std::string s) {
	int i = s.find(" ");
	if (i == std::string::npos)
		return s;
	for (int a = s.size(); a > 0; a--) {
		s = s.substr(i + 1, s.size());
		break;
	}
	return s;
}
void sort(LinkedList* list) {
	std::cout << "[6] Sap Xep\n";
	std::cout << "\t(1) Sap Xep Theo Ten\n"
		<< "\t(2) Sap Xep Theo Tuoi\n"
		<< "\t(3) Sap Xep Theo Diem\n";
	int command;
	std::cout << "\t(?) Moi Nhap Lenh:";
	std::cin >> command;
	if (command == 1) {
		for (Node* p = list->head; p != NULL; p = p->next) {
			Node* min = p;
			for (Node* q = p; q != NULL; q = q->next) {
				if (get_name(q->student.name) < get_name(min->student.name))
					min = q;
			}
			std::string temp_name = min->student.name;
			min->student.name = p->student.name;
			p->student.name = temp_name;
			int temp_age = min->student.age;
			min->student.age = p->student.age;
			p->student.age = temp_age;
			float temp_point = min->student.point;
			min->student.point = p->student.point;
			p->student.point = temp_point;
		}
		clear();
	}
	else if (command == 2) {
		for (Node* p = list->head; p != NULL; p = p->next) {
			Node* min = p;
			for (Node* q = p; q != NULL; q = q->next) {
				if (q->student.age < min->student.age) {
					min = q;
				}
			}
			std::string temp_name = min->student.name;
			min->student.name = p->student.name;
			p->student.name = temp_name;
			int temp_age = min->student.age;
			min->student.age = p->student.age;
			p->student.age = temp_age;
			float temp_point = min->student.point;
			min->student.point = p->student.point;
			p->student.point = temp_point;
		}
		clear();
	}
	else if (command == 3) {
		for (Node* p = list->head; p != NULL; p = p->next) {
			Node* min = p;
			for (Node* q = p; q != NULL; q = q->next) {
				if (q->student.point < min->student.point) {
					min = q;
				}
			}
			std::string temp_name = min->student.name;
			min->student.name = p->student.name;
			p->student.name = temp_name;
			int temp_age = min->student.age;
			min->student.age = p->student.age;
			p->student.age = temp_age;
			float temp_point = min->student.point;
			min->student.point = p->student.point;
			p->student.point = temp_point;
		}
		clear();
	}
}
void statistic(LinkedList list) {
	Node* p = list.head;
	std::cout << "[7] Thong Ke\n";
	std::cout << "\t(!) Diem Trung Binh Cua Ca Lop La: ";
	float sum_points = 0;
	float max_point = -1e9;
	Students list_sv_max_point[100];
	int length = 0;
	while (p != NULL) {
		if (p->student.point > max_point) {
			max_point = p->student.point;
		}
		sum_points += p->student.point;
		p = p->next;
	}
	std::cout << sum_points / list.length << "\n";
	std::cout << "\t(!) Ti Le Sinh Vien Gioi La: ";
	float sum = 0;
	Node* q = list.head;
	while (q != NULL) {
		if (q->student.point == max_point) {
			list_sv_max_point[length++] = q->student;
		}
		if (q->student.point >= 8)
			sum += q->student.point;
		q = q->next;
	}
	float svg = (sum / sum_points) * 100;
	std::cout << svg << "%" << "\n";
	std::cout << "\t(!) Ti Le Sinh Vien Kha La: ";
	float sum2 = 0;
	Node* z = list.head;
	while (z != NULL) {
		if (z->student.point >= 4 && z->student.point < 8)
			sum2 += z->student.point;
		z = z->next;
	}
	float svk = (sum2 / sum_points) * 100;
	std::cout << svk << "%" << "\n";
	std::cout << "\t(!) Ti Le Sinh Vien Kem La: " << 100 - (svg + svk) << "%\n";
	std::cout << "\t(!) Sinh Vien Co Diem Cao Nhat La: \n";
	std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
	std::cout << "\t\t\t|" << std::setfill(' ') << " STT    |" << " Ho Ten             |" << " Tuoi    |" << " Diem   |\n";
	for (int i = 0; i < length; i++) {
		std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
		std::cout << "\t\t\t|" << std::setfill(' ') << std::setw(1) << " " << std::setw(7) << std::left << i + 1
			<< std::setw(2) << "|" << std::setw(19) << list_sv_max_point[i].name
			<< std::setw(2) << "|" << std::setw(8) << list_sv_max_point[i].age
			<< std::setw(2) << "|" << std::setw(7) << list_sv_max_point[i].point
			<< std::setw(2) << "|" << std::right << "\n";
	}
	std::cout << "\t\t\t+" << std::setfill('-') << std::setw(9) << "+" << std::setw(21) << "+" << std::setw(10) << "+" << std::setw(10) << "+\n";
	clear();
}
void save(LinkedList list) {
	std::ofstream output("input.txt");
	Node* p = list.head;
	while (p != NULL) {
		output << p->student.name << ";" << p->student.age << ";" << p->student.point << "\n";
		p = p->next;
	}
	std::cout << "(!) Du Lieu Da Duoc Luu Thanh Cong !!\n";
	clear();
}
void load_data(std::string filename, LinkedList* list) {
	std::ifstream input("input.txt");
	std::string temp;
	while (std::getline(input, temp)) {
		Students student;
		int i = temp.find(';');
		student.name = temp.substr(0, i);
		temp = temp.substr(i + 1);
		i = temp.find(';');
		student.age = stoi(temp.substr(0, i));
		temp = temp.substr(i + 1);
		i = temp.find(';');
		student.point = stof(temp.substr(0, i));
		add(list, student);
	}
}
int main() {
	LinkedList list = { NULL, 0 };
	load_data("input.txt", &list);
	Node* p = list.head;
	while (true) {
		int command;
		std::cout << "============== MENU ================\n"
			<< "|| 1 - In Danh Sach Sinh Vien     ||\n"
			<< "|| 2 - Them                       ||\n"
			<< "|| 3 - Sua                        ||\n"
			<< "|| 4 - Xoa                        ||\n"
			<< "|| 5 - Tim Kiem                   ||\n"
			<< "|| 6 - Sap Xep                    ||\n"
			<< "|| 7 - Thong Ke                   ||\n"
			<< "|| 8 - Sao Luu                    ||\n"
			<< "|| 9 - Thoat                      ||\n"
			<< "====================================\n"
			<< "Moi Nhap Lenh: ";
		std::cin >> command;
		if (command == 1) {
			print(list);
		}
		else if (command == 2) {
			add(&list);
		}
		else if (command == 3) {
			correct(&list);
		}
		else if (command == 4) {
			remove(&list);
		}
		else if (command == 5) {
			find(list);
		}
		else if (command == 6) {
			sort(&list);
		}
		else if (command == 7) {
			statistic(list);
		}
		else if (command == 8) {
			save(list);
		}
		else if (command == 9) {
			std::cout << "Do you want exit ?\n";
			std::cout << "[!] 1 - Save\n";
			std::cout << "[!] 2 - Don't Save\n";
			int command;
			std::cout << "Nhap Lua Chon: ";
			std::cin >> command;
			if (command == 1) {
				save(list);
				break;
			}
			else if (command == 2) {
				break;
			}
		}
		else
			std::cout << "Khong Ton Tai Lenh Nay Vui Long Nhap Lai !!\n";
	}
}