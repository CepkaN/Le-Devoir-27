#include<iostream>
#include<string>

struct movies {
	std::string title="empty";
	int year=0;
	std::string genre="empty";
	unsigned int duration=0;
	unsigned int price = 0;
};
 movies vvod_vyvod() {
	 movies f;
	std::cout << "������� �������� ������ : ";
	std::getline(std::cin, f.title);
	std::cout << "������� ��� : ";
	std::cin >> f.year;
	std::cin.ignore();
	std::cout << "������� ���� ������ : ";
	std::getline(std::cin,f.genre );
	std::cout << "������� ����������������� ������ : ";
	std::cin >> f.duration;
	std::cout << "������� ��������� ������ : ";
	std::cin >> f.price;
	std::cin.ignore();
	std::cout << "\n\n";
	return f;
}
 void show_movie(movies& f) {
	 std::cout << "\t" << f.title << "\n���� : " << f.genre << "\n��� :   " << f.year << "\n����������������� : " << f.duration << "\n��������� : " << f.price<<"\n\n";
 }
 movies expensive(movies f,movies fi,movies fil) {
	 int max=(f.price > (fi.price > fil.price ? fi.price : fil.price) ? f.price : (fi.price > fil.price ? fi.price : fil.price));
	 movies brr;
	 if (max == f.price)
		 brr = f;
	 else if (max == fi.price)
		 brr = fi;
	 else
		 brr = fil;
	 return brr;
 }
 void update_info(movies &f) {
	 int n; std::cout << "\n��������, ����� ���������� � ������ ����� �������� : \n1. ��������.\n2. ��� ������.\n3. ����.\n4. �����������������.\n";
	 std::cout << "5. ���� �� ����.\n";
	 std::cin >> n;
	 std::string ti ;int y=0;std::string ge;unsigned int dur=0;unsigned int pri=0;
	 switch (n) {
	 case 1: std::cout << "������� ����� �������� ������ : ";
		 std::getline(std::cin, ti);
		 f.title = ti;
		 std::cout << "���������� ���������.\n"; break;
	 case 2:std::cout << "������� ����� ��� : ";
		 std::cin >> y;
		 f.year=y;
		 std::cout << "���������� ���������.\n"; break;;
	 case 3:std::cout << "������� ����� ���� ������ : ";
		 std::getline(std::cin, ge);
		 f.genre = ge;
		 std::cout << "���������� ���������.\n"; break;;
	 case 4:std::cout << "������� ����� ����������������� ������ : ";
		 std::cin >> dur;
		 f.duration = dur;
		 std::cout << "���������� ���������.\n"; break;;
	 case 5:std::cout << "������� ����� ���� ������ : ";
		 std::cin >> pri;
		 f.price = pri;
		 std::cout << "���������� ���������.\n"; break;;
	 default: std::cout << "����� �������� ������������.";
	 }
 }
int main() {
	setlocale(LC_ALL, "Russian");
	// ������ 1.
	std::cout << "������ 1.\n";
	movies film = vvod_vyvod();
	movies film1 = vvod_vyvod();
	movies film2 = vvod_vyvod();
	show_movie(film);
	show_movie(film1);
	show_movie(film2);
	// ������ 2.
	std::cout << "\n������ 2.\n����� ������� ����� : \n";
	movies film3 = expensive(film, film1, film2);
	show_movie(film3);
	// ������ 3.
	std::cout << "\n������ 3.\n";
	update_info(film3);
	show_movie(film3);

	return 0;
}