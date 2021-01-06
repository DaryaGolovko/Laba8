#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>


using namespace std;

struct Human        //создание структуры
{
    char country[100] = {}; 
    char team[100] = {}; 
    char name[100] = {}; 
    int number = 0; 
    int age = 0; 
    int heigh = 0; 
    int weight = 0; 
};

Human* full(Human* arr, int size)       //функция заполнения структуры
{
    for (int i = 0; i < size; i++)     
    {
        printf_s("Введите страну:");
        scanf_s("%s", arr[i].country, 100);
        printf_s("Введите команду:");
        scanf_s("%s", arr[i].team, 100);
        printf_s("Введите имя:");
        scanf_s("%s", arr[i].name, 100);
        printf_s("Введите номер участника:");
        scanf_s("%d", &arr[i].number);
        printf_s("Введите возраст:");
        scanf_s("%d", &arr[i].age);
        printf_s("Введите рост:");
        scanf_s("%d", &arr[i].heigh);
        printf_s("Введите вес:");
        scanf_s("%d", &arr[i].weight);
    }
    return arr;
}

void look(Human* arr, int size)     //просмотр структуры
{
    printf_s("\nПросмотр структуры:\n");

    for (int i = 0; i < size; i++)
    {
        printf_s("%s\t%s\t%s\n", arr[i].country, arr[i].team, arr[i].name);
        printf_s("Номер участника : %i\n", arr[i].number);
        printf_s("Возраст: %i\n", arr[i].age);
        printf_s("Рост: %i\n", arr[i].heigh);
        printf_s("Вес: %i\n", arr[i].weight);
        printf_s("\n");
    }
}

void look2(Human* arr, int size)     //просмотр структуры в конце
{
    printf_s("\nПросмотр измененной структуры:\n");

    for (int i = 0; i < size; i++)
    {
        printf_s("%s\t%s\t%s\n", arr[i].country, arr[i].team, arr[i].name);
        printf_s("Номер участника : %i\n", arr[i].number);
        printf_s("Возраст: %i\n", arr[i].age);
        printf_s("Рост: %i\n", arr[i].heigh);
        printf_s("Вес: %i\n", arr[i].weight);
        printf_s("\n");
    }
}

Human* Shellsort(Human* arr, int size)  //функция сортировки Шелл
{   
    int newsize = size * 2;
    Human* array = new Human[newsize]; 

    for (int i = 0; i < size; i++)  //копирование данных в новый массив
    {
        strcpy_s(array[i].country, arr[i].country);
        strcpy_s(array[i].team, arr[i].team);
        strcpy_s(array[i].name, arr[i].name);
        array[i].number = arr[i].number;
        array[i].weight = arr[i].weight;
        array[i].heigh = arr[i].heigh;
        array[i].age = arr[i].age;
    }
    for ( int step = size / 2; step > 0; step /= 2)      //изменение шага, т.е. деление на 2
        for ( int j = step; j < size; j++)       //пробег по элементам
            for (int i = j - step; j >= 0 ; i -= step) //сортирую до элемента i
            {
                if((i+step)<size)
                { 
                    if (array[i].age > array[i + step].age)
                    {
                        swap(array[i + step], array[i]);
                        break;
                    }
                    break;
                }
            }

    printf_s("Список участников: \n");
    for (int i = 0; i < size; i++)
    {
        if (array[i].age >= 20)
            printf_s("%s\n", array[i].name);
    }

    return array;
}

Human* change(Human* arr, int del)
{
    int i = del;
    printf_s("Введитe cтрану:");
    scanf_s("%s", arr[i].country, 100);
    printf_s("Введитe команду:");
    scanf_s("%s", arr[i].team, 100);
    printf_s("Введитe имя:");
    scanf_s("%s", arr[i].name, 100);
    printf_s("Введитe номер участника:");
    scanf_s("%d", &arr[i].number);
    printf_s("Введитe возраст:");
    scanf_s("%d", &arr[i].age);
    printf_s("Введитe рост:");
    scanf_s("%d", &arr[i].heigh);
    printf_s("Введитe вес:");
    scanf_s("%d", &arr[i].weight);

    return arr;
}

Human* add(Human* arr, int size)        //функция добавления
{
    int newsize = size+1;
    Human* array = new Human[newsize];

    for (int i = 0; i < size; i++)  //копирование данных в новый массив
    {
        strcpy_s(array[i].country, arr[i].country);
        strcpy_s(array[i].team, arr[i].team);
        strcpy_s(array[i].name, arr[i].name);
        array[i].number = arr[i].number;
        array[i].weight = arr[i].weight;
        array[i].heigh = arr[i].heigh;
        array[i].age = arr[i].age;
    }
    for (int i = size; i < size+1; i++)        //добавление нового участника
    {
        printf_s("Введитe cтрану:");
        scanf_s("%s", array[i].country, 100);
        printf_s("Введитe команду:");
        scanf_s("%s", array[i].team, 100);
        printf_s("Введитe имя:");
        scanf_s("%s", array[i].name, 100);
        printf_s("Введитe номер участника:");
        scanf_s("%d", &array[i].number);
        printf_s("Введитe возраст:");
        scanf_s("%d", &array[i].age);
        printf_s("Введитe рост:");
        scanf_s("%d", &array[i].heigh);
        printf_s("Введитe вес:");
        scanf_s("%d", &array[i].weight);
    }
    return array;
}

Human* Del(Human* arr, int size, int del)
{
    int newsize = size - 1;
    Human* array = new Human[newsize];

    for (int i = 0; i < del; i++)
    {
       strcpy_s(array[i].country, arr[i].country);
       strcpy_s(array[i].team, arr[i].team);
       strcpy_s(array[i].name, arr[i].name);
       array[i].number = arr[i].number;
       array[i].age = arr[i].age;
       array[i].heigh = arr[i].heigh;
       array[i].weight = arr[i].weight;

    }

    for (int i = del; i < newsize; i++)
    {
        strcpy_s(array[i].country, arr[i+1].country);
        strcpy_s(array[i].team, arr[i+1].team);
        strcpy_s(array[i].name, arr[i+1].name);
        array[i].number = arr[i+1].number;
        array[i].age = arr[i+1].age;
        array[i].heigh = arr[i+1].heigh;
        array[i].weight = arr[i+1].weight;
    }

    return array;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;   //изначальноe количество участников
    printf_s("Введите количество участников:");
    scanf_s("%d", &size);

    Human* arr = new Human[size];  //массив структур

    full(arr, size);      //функция заполнения массива
    look(arr, size);      //функция просмотра массива 


    cout << "Выберите действие\n";
    cout << "1-добавить участника, 2-изменить информация об участнике, 3-удалить участника, 4-вывод участников 20+с сортировкой\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        arr = add(arr, size);
        size++;
    }

    if (choice == 2)
    {
        printf_s("Какого участника вы хотите изменить?(Введите страну)");
        char* mas = new char[100];
        int h = 0;
        scanf_s("%s", mas, 100);
        for (int i = 0; i < size; i++)
        {
            if (strcmp(mas, arr[i].country) == 0)
            {
                h = i;
                break;
            }
        }
        change(arr, h);
    }

    if (choice == 3)
    {
        printf_s("Какого участника вы хотите убрать? Введите страну\n");
        char* st = new char[100];
        int del = 0;
        scanf_s("%s", st, 100);
        for (int i = 0; i < size; i++)
        {
            if (strcmp(st, arr[i].country) == 0)
            {
                del = i;
                break;
            }
        }
        arr = Del(arr, size, del);
        size -= 1;
    }

    if (choice == 4)
    {
        Shellsort(arr, size);

    }

    printf_s("Вывод измененного массива структур на экран\n");
    look2(arr, size);     // функция вывода на экран измененного массива

    delete[] arr;
}