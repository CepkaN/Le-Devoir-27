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
	std::cout << "Введите название фильма : ";
	std::getline(std::cin, f.title);
	std::cout << "Введите год : ";
	std::cin >> f.year;
	std::cin.ignore();
	std::cout << "Введите жанр фильма : ";
	std::getline(std::cin,f.genre );
	std::cout << "Введите продолжительность фильма : ";
	std::cin >> f.duration;
	std::cout << "Введите стоимость фильма : ";
	std::cin >> f.price;
	std::cin.ignore();
	std::cout << "\n\n";
	return f;
}
 void show_movie(movies& f) {
	 std::cout << "\t" << f.title << "\nжанр : " << f.genre << "\nгод :   " << f.year << "\nпродолжительность : " << f.duration << "\nстоимость : " << f.price<<"\n\n";
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
	 int n; std::cout << "\nВыберите, какую информацию о фильме нужно обновить : \n1. Название.\n2. Год выхода.\n3. Жанр.\n4. Продолжительность.\n";
	 std::cout << "5. Цена за диск.\n";
	 std::cin >> n;
	 std::string ti ;int y=0;std::string ge;unsigned int dur=0;unsigned int pri=0;
	 switch (n) {
	 case 1: std::cout << "Введите новое название фильма : ";
		 std::getline(std::cin, ti);
		 f.title = ti;
		 std::cout << "Информация обновлена.\n"; break;
	 case 2:std::cout << "Введите новый год : ";
		 std::cin >> y;
		 f.year=y;
		 std::cout << "Информация обновлена.\n"; break;;
	 case 3:std::cout << "Введите новый жанр фильма : ";
		 std::getline(std::cin, ge);
		 f.genre = ge;
		 std::cout << "Информация обновлена.\n"; break;;
	 case 4:std::cout << "Введите новую продолжительность фильма : ";
		 std::cin >> dur;
		 f.duration = dur;
		 std::cout << "Информация обновлена.\n"; break;;
	 case 5:std::cout << "Введите новую цену фильма : ";
		 std::cin >> pri;
		 f.price = pri;
		 std::cout << "Информация обновлена.\n"; break;;
	 default: std::cout << "Такой операции несуществует.";
	 }
 }
int main() {
	setlocale(LC_ALL, "Russian");
	// Задача 1.
	std::cout << "Задача 1.\n";
	movies film = vvod_vyvod();
	movies film1 = vvod_vyvod();
	movies film2 = vvod_vyvod();
	show_movie(film);
	show_movie(film1);
	show_movie(film2);
	// Задача 2.
	std::cout << "\nЗадача 2.\nСамый дорогой фильм : \n";
	movies film3 = expensive(film, film1, film2);
	show_movie(film3);
	// Задача 3.
	std::cout << "\nЗадача 3.\n";
	update_info(film3);
	show_movie(film3);

	return 0;
}