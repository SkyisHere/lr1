#include<string>
#include<iostream>
#include"Exception.hpp"
using namespace std;
class Note{
	string name;
	string surname;
	string phone;
	int date[3];
public:
	Note(const string& name = "", const string& surname = "", const string& phone = "", int day = 0, int month = 0, int year = 0);
	Note(const Note& note);
	~Note();
	//геттеры и сеттеры
	string& Name();
	string& Surname();
	string& Phone();
	int& Month();
	int& Day();
	int& Year();
	//операторы
	friend ostream& operator<<(ostream& out, const Note& note);
	friend istream& operator>>(istream& in, Note& note);
	Note& operator =(const Note& note);
};

#include "Note.h"

Note::Note(const string& name, const string& surname, const string& phone, int day, int month, int year){
  cout << "\nNote()";
  this->name = name;
  this->surname = surname;
  this->phone = phone;
  this->date[0] = day;
  this->date[1] = month;
  this->date[2] = year;
	
}
Note::Note(const Note& note){
  cout << "\nNote(Note)";
  this->name = note.name;
  this->surname = note.surname;
  this->phone = note.phone;
  this->date[0] = note.date[0];
  this->date[1] = note.date[1];
  this->date[2] = note.date[2];
}
Note::~Note(){
	cout << "~Note()";
}
//геттеры и сеттеры
string& Note::Name(){
	return name;
}
string& Note::Surname(){
	return surname;
}
string& Note::Phone(){
	return phone;
}
int& Note::Month(){
	return date[1];
}
int& Note::Day(){
	return date[0];
}
int& Note::Year(){
	return date[2];
}
//операторы
ostream& operator<<(ostream& out, const Note& note){
	out << note.name << '\n' << note.surname << '\n' << note.phone << '\n' <<
		note.date[0] << '/' << note.date[1] << '/' << note.date[2];
	return out;
}
istream& operator>>(istream& in, Note& note){
	if(!(in >> note.name >> note.surname >> note.phone >> note.date[0] >> note.date[1] >> note.date[2])){
		throw Exception("Ошибка ввода");
	}
	return in;
}
Note& Note::operator =(const Note& note){
  if(this == &note) return *this;
  this->name = note.name;
  this->surname = note.surname;
  this->phone = note.phone;
  this->date[0] = note.date[0];
  this->date[1] = note.date[1];
  this->date[2] = note.date[2];
  return *this;
}
#include "Note.h”
const int size1 = 8;//размер
Note notes[size1];//массив знаков
int j, n = size1;
void Sort(int j, int n) {
	do {
		
		int nn = 0;
		for (j = 1; j < n; ++j)
			if (notes[j - 1].Day() > notes[j].Day()
				&& notes[j - 1].Month() > notes[j].Month()
				&& notes[j - 1].Year() > notes[j].Year()) {
				Note temp = notes[j - 1];
				notes[j - 1] = notes[j];
				notes[j] = temp;
				nn = j;
			}
		n = nn;
	} while (n);

}
int main(){
	string phone;
	setlocale(LC_ALL, "");
	int choice;
	while(true){
		 cout << "\n1. Считать\n2. Поиск\n3. Изменить\n4. Выход\n-> ";
		 cin >> choice;
		 switch(choice){
		 case 1:
			 cout << "Имя Фамилия Телефон DD MM YY\n";
			 try{
				 //считываем данные
				for(int i = 0; i < size1; ++i){
				   cin >> notes[i];
				}
				/*Сортируем*/
				Sort(j, n);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
			 break;
		 case 2:
			 cout << "Введите номер телефона: ";
			 
			 cin >> phone;
			 int i;
			 for(i = 0; i < size1; ++i){
				if(notes[i].Phone() == phone){
					cout << "\n" << notes[i];
				}
			 }
			 if(i > size1){
				cout << "NOT FOUND";
			 }
			 break;
		 case 3:
			 int index;
			 do{
				cout << "Введите индекс: ";
				cin >> index;
			 } while(index < 0 || index >= 8);//защита от некорректного ввода
			 cout << "Имя Фамилия Телефон DD MM YY\n";
			 cin >> notes[index];
			 break;
		 case 4:
			 return 0;
			 break;
		 }
	}
}
