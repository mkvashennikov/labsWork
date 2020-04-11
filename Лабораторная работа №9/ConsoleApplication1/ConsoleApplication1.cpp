#include <iostream>
#include "time.h"
#include <string>
#include "windows.h"
using namespace std;

class Modem {
public:
	Modem();
	void set_Name(string name);
	void set_NameManufacturer(string name);
	void set_Speed(int speed);
	void set_Price(int price);
	void set_Connection4G();

	string const get_Name();
	string const get_Manufacturer();
	int const get_Speed();
	int const get_Price();
	bool const get_Connection();
	bool operator== (const Modem& right);
	bool operator!= (const Modem& right);
	Modem& operator=(Modem& right);
	Modem& operator++();
	Modem& operator--();
	bool operator<(const Modem& right);
protected:
	string name;
	string name_manufacturer;
	int speed;
	int price;
	bool connection_4G;
};

Modem::Modem() {
	name = "";
	name_manufacturer = "";
	speed = 0;
	price = 0;
	connection_4G = false;
}
bool Modem::operator==(const Modem& right) {
	if (this->speed == right.speed && this->price == right.price) {
		return true;
	}
	return false;
}
bool Modem::operator!=(const Modem& right) {
	if (this->speed != right.speed || this->price != right.price) {
		return true;
	}
	return false;
}
Modem& Modem::operator=(Modem& right) {
	this->name = right.get_Name();
	this->name_manufacturer = right.get_Manufacturer();
	this->connection_4G = right.get_Connection();
	this->speed = right.get_Speed();
	this->price = right.get_Price();
	return *this;
}
Modem& Modem::operator++() {
	this->price++;
	this->speed++;
	return *this;
}
Modem& Modem::operator--() {
	this->price--;
	this->speed--;
	return *this;
}
bool Modem::operator<(const Modem& right) {
	return this->price < right.price;
}
void Modem::set_Name(string name) {
	this->name = name;
}
void Modem::set_NameManufacturer(string name) {
	name_manufacturer = name;
}
void Modem::set_Speed(int speed) {
	this->speed = speed;
}
void Modem::set_Price(int price) {
	this->price = price;
}
void Modem::set_Connection4G() {
	connection_4G = true;
}
string const Modem::get_Name() {
	return this->name;
}
string const Modem::get_Manufacturer() {
	return this->name_manufacturer;
}
int const Modem::get_Speed() {
	return this->speed;
}
int const Modem::get_Price() {
	return this->price;
}
bool const Modem::get_Connection() {
	return this->connection_4G;
}

class NetworkAdapter {
	public:
		NetworkAdapter();
		void set_range(float r);
		void set_bluetooth_version(float bl_v);
		const float get_range();
	protected:
		string name;
		string name_manufacturer;
		string interface_;
		float range;
		float bluetooth_version;
};

NetworkAdapter::NetworkAdapter() {
	name = "";
	name_manufacturer = "";
	interface_ = "USB";
	range = 5.1;
	bluetooth_version = 3.0;
}
void NetworkAdapter::set_range(float r) {
	range = r;
}
void NetworkAdapter::set_bluetooth_version(float bl_v) {
	bluetooth_version = bl_v;
}
const float NetworkAdapter::get_range() {
	return range;
}

class Repeater {
	public:
		Repeater();
		void set_min_Distance(float min_d);
		void set_max_Distance(float max_d);
	protected:
		string name;
		string name_manufacturer;
		float min_distance;
		float max_distance;
};

Repeater::Repeater() {
	name = "";
	name_manufacturer = "";
	min_distance = 0;
	max_distance = 0;
}
void Repeater::set_min_Distance(float min_d) {
	min_distance = min_d;
}
void Repeater::set_max_Distance(float max_d) {
	max_distance = max_d;
}

class NetworkDevice: public Modem, public NetworkAdapter, public Repeater{
	public:
		NetworkDevice();
		friend std::ostream& operator<<(std::ostream& cout, const NetworkDevice& modem);
		void set_avg_distance(float min_d, float max_d);
	private:
		float average_distance;
};

NetworkDevice::NetworkDevice() {
	Modem::name = "empty_name";
	Modem::name_manufacturer = "empty_name";
	min_distance = 20.6;
	max_distance = 100.33;
	average_distance = (min_distance + max_distance) / 2;
	range = 5.7;
}
void NetworkDevice::set_avg_distance(float min_d, float max_d){
	average_distance = (min_d + max_d) / 2;
}
std::ostream& operator<<(std::ostream& cout, const NetworkDevice& device) {
	string str1 = device.Modem::name;
	string str2 = device.Modem::name_manufacturer;
	string str3 = to_string(device.speed);
	string str4 = to_string(device.price);
	bool con = device.connection_4G;
	string str5;
	if (con) str5 = "доступен 4G";
	else str5 = "недоступен 4G";
	string str6 = to_string((int)device.average_distance);
	string str7 = to_string(device.range);
	cout << str1 << ", " << str2 << ", " << str3 << "Мбит/с, " << str4 << "руб., " << str5 << ", " << str6 <<" метров, " << str7 << " range";
	return cout;
}

template <class T>
class Vector {
public:
	Vector(int c);
	~Vector();
	T& operator [](const int current);
	void OutFullInf(int current);
	void BubbleSort();
	bool Price_Filter(int min_price, int max_pricem, int current);
	bool operator==(const Vector& right);
	bool operator!=(const Vector& right);
	Vector& operator=(const Vector& right);
	Vector& operator++();
	Vector& operator--();
private:
	T* x;
	int b;
};

template <class T>
Vector<T>::Vector(int c) {
	b = c;
	x = new T[b];
}
template <class T>
Vector<T>::~Vector() {
	delete[]x;
}
template <class T>
T& Vector<T>::operator [](const int current) {
	return x[current];
}
template <class T>
bool Vector<T>::operator==(const Vector& right) {
	return this->x == right.x;
}
template <class T>
bool Vector<T>::operator!=(const Vector& right) {
	return this->x != right.x;
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector& right) {
	this->x = right.x;
	return *this;
}
template <class T>
Vector<T>& Vector<T>::operator++() {
	this->x++;
	return *this;
}
template <class T>
Vector<T>& Vector<T>::operator--() {
	this->x--;
	return *this;
}
template <class T>
void Vector<T>::OutFullInf(int current) {
	cout << x[current] << endl;
}
template <class T>
void Vector<T>::BubbleSort() {
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b - 1; j++) {
			if (x[j] < x[j + 1]) {
				T temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}
template <class T>
bool Vector<T>::Price_Filter(int min_price, int max_price, int current) {
	if (x[current].get_Price() >= min_price && x[current].get_Price() <= max_price) {
		return true;
	}
	return false;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count, price, speed, connect_4G;
	float min_d, max_d;
	string name;
	string manufacturer;
	cout << "Введите количество элементов, которые хотите добавить в Вектор:" << endl;
	cin >> count;
	Vector<NetworkDevice> vec(count);
	cout << "Заполните информацию о Сетевом устройстве(-ах)" << endl;
	for (int i = 0; i < count; i++) {
		cout << "Сетевое устройство №" << i + 1 << endl;
		cout << "Введите название сетевого устройства: " << endl;
		cin >> name;
		vec[i].set_Name(name);
		cout << "Введите изготовителя сетевого устройства: " << endl;
		cin >> manufacturer;
		vec[i].set_NameManufacturer(manufacturer);
		cout << "Введите цену сетевого устройства (руб.): " << endl;
		cin >> price;
		vec[i].set_Price(price);
		cout << "Введите скорость сетевого устройства (Мбит/с): " << endl;
		cin >> speed;
		vec[i].set_Speed(speed);
		cout << "Есть ли 4G? (0 - Нет, 1 - Да)" << endl;
		cin >> connect_4G;
		if (connect_4G == 1) vec[i].set_Connection4G();
		cout << "Введите range: " << endl;
		float r;
		cin >> r;
		vec[i].set_range(r);
		cout << endl;
	}
	cout << "Вывод информации о сетевом устройстве(-ах) без сортировки:" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < count; i++) {
		cout << "Модем #" << i + 1 << endl;
		vec.OutFullInf(i);
	}
	cout << "-------------------------------" << endl;
	cout << "Вывод информации о сетевом устройстве(-ах) с сортировкой по цене (от большего к меньшему):" << endl;
	vec.BubbleSort();
	for (int i = 0; i < count; i++) {
		cout << "Модем #" << i + 1 << endl;
		vec.OutFullInf(i);
	}
	cout << endl;
	int min_price, max_price;
	cout << "Введите минимальную стоимость для сетевого устройства" << endl;
	cin >> min_price;
	cout << "Введите максимальную стоимость для сетевого устройства" << endl;
	cin >> max_price;
	cout << "-----------Подходящие по стоимости сетевые устройства------------" << endl;
	int filter = false;
	for (int i = 0; i < count; i++) {
		if (vec.Price_Filter(min_price, max_price, i)) {
			filter = true;
			vec.OutFullInf(i);
		}
	}
	if (!filter) cout << "Подходящих сетевых устройств не обнаружено!" << endl;
	cout << "----------------------------------------------------------------" << endl;
	return 0;
}


