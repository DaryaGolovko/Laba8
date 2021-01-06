#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct Human        //создание структуры
{
    string F;    //фамилия
    string I;       //имя
    string O;       //отчество
    string dol;        //должность
    int number = 0;     //номер отдела
    int start = 0;  //год начала работы
};

void look(Human* arr, int size)     //просмотр структуры
{
    printf_s("\nПросмотр структуры:\n");

    for (int i = 0; i < size; i++)
    {
        cout << "Сотрудник: " << arr[i].F << "\t" << arr[i].I << "\t" << arr[i].O << endl;
        cout << "должность: " << arr[i].dol << endl;
        cout << "номер отдела: " << arr[i].number << endl;
        cout << "год начала: " << arr[i].start << endl;;
    }
}

void look2(Human* arr, int size)     //просмотр структуры в конце +сортировка Шелла
{


    int newsize = size * 2;
    Human* array = new Human[newsize];

    for (int i = 0; i < size; i++)  //копирование данных в новый массив
    {
        array[i].F = arr[i].F;
        array[i].I = arr[i].I;
        array[i].O = arr[i].O;
        array[i].number = arr[i].number;
        array[i].dol = arr[i].dol;
        array[i].start = arr[i].start;
    }
    

    for (int step = size / 2; step > 0; step /= 2)      //изменение шага, т.е. деление на 2
        for (int j = step; j < size; j++)       //пробег по элементам
            for (int i = j - step; j >= 0; i -= step) //сортирую до элемента i
            {
                if ((i + step) < size)
                {
                    if (array[i].start < array[i + step].start)
                    {
                        swap(array[i + step], array[i]);
                        break;
                    }
                    break;
                }
            }

    printf_s("Список сотрудников: \n");
    for (int i = 0; i < size; i++)
    {
        cout << "Сотрудник: " << array[i].F << "\t" << arr[i].I << "\t" << arr[i].O << endl;
        cout << "должность: " << array[i].dol << endl;
        cout << "номер отдела: " << array[i].number << endl;
        cout << "год начала: " << array[i].start << endl;;
    }

}

Human* change(Human* arr, int del)
{
    int i = del;
    cout << "Введитe фамилию:";
    cin >> arr[i].F;
    cout << "Введитe имя:";
    cin >> arr[i].I;
    cout << "Введитe отчество:";
    cin >> arr[i].O;
    cout << "Введитe номер отдела:";
    cin >> arr[i].number;
    cout << "Введитe должность:";
    cin >> arr[i].dol;
    cout << "Введитe дату начала:";
    cin >> arr[i].start;

    return arr;
}

Human* add(Human* arr, int size)        //функция добавления
{
    int newsize = size + 1;
    Human* array = new Human[newsize];

    for (int i = 0; i < size; i++)  //копирование данных в новый массив
    {
        array[i].F = arr[i].F;
        array[i].I = arr[i].I;
        array[i].O = arr[i].O;
        array[i].number = arr[i].number;
        array[i].dol = arr[i].dol;
        array[i].start = arr[i].start;
    }
    for (int i = size; i < size + 1; i++)        //добавление нового участника
    {
        cout << "Введитe фамилию:";
        cin >> array[i].F;
        cout << "Введитe имя:";
        cin >> array[i].I;
        cout << "Введитe отчество:";
        cin >> array[i].O;
        cout << "Введитe номер отдела:";
        cin >> array[i].number;
        cout << "Введитe должность:";
        cin >> array[i].dol;
        cout << "Введитe дату начала:";
        cin >> array[i].start;
    }

    return array;
}

Human* Del(Human* arr, int size, int del)
{
    int newsize = size - 1;
    Human* array = new Human[newsize];

    for (int i = 0; i < del; i++)
    {
        array[i].F = arr[i].F;
        array[i].I = arr[i].I;
        array[i].O = arr[i].O;
        array[i].number = arr[i].number;
        array[i].dol = arr[i].dol;
        array[i].start = arr[i].start;
    }

    for (int i = del; i < newsize; i++)
    {
        array[i].F = arr[i + 1].F;
        array[i].I = arr[i + 1].I;
        array[i].O = arr[i + 1].O;
        array[i].number = arr[i + 1].number;
        array[i].dol = arr[i + 1].dol;
        array[i].start = arr[i + 1].start;
    }

    return array;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size = 5;
    Human* arr = new Human[size];

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string way = "Data.txt";
    ifstream file1;
    file1.open(way);    //открываю файл

    if (!file1.is_open())
        cout << "Ошибка доступа к файлу\n";
    else
    {
        cout << "Файл успешно открылся\n";

        for (int i = 0; i < size; i++)     //копирую инфу из файла в массив структур
        {

            string s1, s2, s3, s5;
            int s4, s6;
            file1 >> s1;
            arr[i].F = s1;
            file1 >> s2;
            arr[i].I = s2;
            file1 >> s3;
            arr[i].O = s3;
            file1 >> s4;
            arr[i].number = s4;
            file1 >> s5;
            arr[i].dol = s5;
            file1 >> s6;
            arr[i].start = s6;
        }
    }

    file1.close();//закрываем файл, потому что 2 прога не сможет достать инфу 

    look(arr, size);

    cout << "Выберите действие\n";
    cout << "1-добавить сотрудника, 2-изменить информация о сотруднике, 3-удалить сотрудника\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        arr = add(arr, size);
    }

    if (choice == 2)
    {
        printf_s("Какого участника вы хотите изменить? Введите фамилию");
        char* mas = new char[100];
        int h = 0;
        scanf_s("%s", mas, 100);
        for (int i = 0; i < size; i++)
        {
            if (mas == arr[i].F)
            {
                h = i;
                break;
            }
        }
        change(arr, h);
    }

    if (choice == 3)
    {
        printf_s("Какого сотрудника вы хотите убрать? Введите фамилию\n");
        char* mas = new char[100];
        int del = 0;
        scanf_s("%s", mas, 100);
        for (int i = 0; i < size; i++)
        {
            if (mas == arr[i].F)
            {
                del = i;
                break;
            }
        }
        arr = Del(arr, size, del);
        size -= 1;
    }

    printf_s("Вывод измененного массива структур на экран\n");
    look2(arr, size);     // функция вывода на экран измененного массива+сотировка по убыванию стажа

    delete[] arr;
}