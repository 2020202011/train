#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

class train
{
protected:
    int number;
    string departure, destination;
public:
    train() :number(0), departure(0), destination(0) {}
    train(const train& copy) :number(copy.number), departure(copy.departure), destination(copy.destination) {}
    train(int _number, string _departure, string _destination)
    {
        number = _number; //номер поезда
        departure = _departure; //время отправления
        destination = _destination; //место назначения
    }
    int getNumber()
    {
        return number;
    }
    string getDeparture()
    {
        return departure;
    }
    string getDestination()
    {
        return destination;
    }
    void operator = (train other)
    {
        number = other.number;
        departure = other.departure;
        destination = other.destination;
    }

};

void addTrain(vector <train>& a) //добавление поезда
{
    int num;
    string station, time;
    cout << "Введите номер поезда: " << endl;
    cin >> num;
    cin.ignore();
    cout << "Введите место назначения: " << endl;
    cin >> station;
    cin.ignore();
    cout << "Введите время отправления: " << endl;
    cin >> time;
    cin.ignore();
    a.push_back(train(num, time, station));
}

void allInfo(vector <train>& a) //вывод информации о всех поездах
{
    if (a.empty())
    {
        cout << "Список пуст! " << endl; return;
    }
    vector <train>::iterator it = a.begin();
    cout << "Номер поезда  " << '\t' << " Время отправления " << '\t' << " Место назначения " << endl;
    while (it != a.end())
    {
        cout << it->getNumber() << setw(25) << it->getDeparture() << setw(25) << it->getDestination() << '\n';
        it++;
    }
}
void info_one_train(vector<train>a)//информация о запрашиваемом поезде
{
    int user_train;
    vector <train>::iterator it = a.begin();
    cout << "Введите номер поезда: " << endl;
    cin >> user_train;
    cin.ignore();
    if (it->getNumber() == user_train)
    {
        cout << it->getDestination() << '\t' << it->getDeparture() << endl;
    }
    else
    {
        cout << "Поезд не найден! " << endl;
    }
}
void main()
{
    setlocale(LC_ALL, "rus");
    cout << setw(55) << " Минск " << endl;
    vector <train> database;
    for (int i = 0; i < 2; i++)
    {
        addTrain(database);
    }
    allInfo(database);
    info_one_train(database);
}