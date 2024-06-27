﻿// лаб 1 list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Lab 1 - 4.cpp : Этот файл содержит функцию "main".Здесь начинается и заканчивается выполнение программы.
// лаб 1 list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Использование STL(list). 
// Обработка контейнеров, с использованием алгоритмов.
// 1. Не использовать циклы для увеличения итераторов, использовать функцию advance!
// 2. Вывод коллекции на консоль осуществлять с помощью алгоритма сopy.

// ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ:
// 5. Разработать программу для работы со списком (использовать list). 
// Информационное поле каждого элемента целые числа.

// Программа должна выводить на экран компьютера меню вида :
// 1. Просмотреть состояние списка
// 2. Удалить несколько элементов с заданной позиции
// 3. Добавить несколько элементов в заданную позицию c друго list
// 4. Удалить парные элементы
// 5. Подсчитать сколько элементов одного массива больше соответствующих элементов другого массива (inner_product)
// 6. Поиск в списке два одинаковых смежных элемента, использовать алгоритм(adjacent_find)
// 7. Выход из программы

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <conio.h>
#include <windows.h>  // русский язык

using namespace std;

template<int MaxVal>  // шаблон генератора случайных чисел в заданном диапазоне
int GenRnd()
{
    return rand() % MaxVal; // генерируем случайные числа в заданном диапазоне
}

int main()
{
    SetConsoleCP(1251);  // русский язык
    SetConsoleOutputCP(1251);  // русский язык

    cout << "\t Введите количество элементов списка: ";
    int c;
    cin >> c;
    system("cls");
    list<int>myList(c);                                // создаем список (контейнер) list с типом <int> натуральных чисел диапазона
    list<int>nList(c);                                 // создаем список (контейнер) list с типом <int> натуральных чисел диапазона
    list<int>::iterator i = myList.begin();  // создаем итератор
    list<int>::iterator result1, result2;
    //............................................

    generate(myList.begin(), myList.end(), GenRnd<10>); // заполняем массив случайными числами в интервале от 0 до 10
    generate(nList.begin(), nList.end(), GenRnd<10>);   // заполняем массив случайными числами в интервале от 0 до 10
    //............................................

    char ch; 
    auto v6 = myList.end();// объявляем переменную
    auto v4 = myList.begin();
    auto vi = myList.begin();
    auto v3 = myList.begin();
    auto v1 = nList.begin();
    auto v2 = nList.begin();

    int k, x, y, a, b,r2;                                  // объявляем переменные

    // выводим текст на консоль
    cout << "\t ===========МЕНЮ===========\n\n";
    cout << "\t 1.Просмотреть состояние списка\n\n";
    cout << "\t 2.Удалить несколько элементов с заданной позиции\n\n";
    cout << "\t 3.Добавить несколько элементов в заданную позицию c другого list\n\n";
    cout << "\t 4.Удалить парные элементы\n\n";
    cout << "\t 5.Подсчитать сколько элементов одного массива больше соответствующих элементов другого массива (inner_product)\n\n";
    cout << "\t 6.Поиск в списке два одинаковых смежных элемента, использовать алгоритм (adjacent_find)\n\n";
    cout << "\t 7.Выход из программы\n";
    cout << "\t ===========================\n";
    cout << "\t Выберите вариант (1-7) ";
    do  // используем оператор цикла цикл do-while
    {
        // функцией _getche() считываем введенный символ с консоли, и выводим этот символ на экран
        ch = _getche();
        cout << endl << endl;                       // переход на строку ниже
        //............................................

        switch (ch)                                 //используем оператор ветвления switch для выбора 
        {
        case '1':                                   // Просмотреть состояние списка
            cout << "Cостояние списка 1: \n";
            copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));   // выводим на экран список через пробел
            cout << endl << endl;                                                   // переход на строку ниже
            cout << "Cостояние списка 2: \n";
            copy(nList.begin(), nList.end(), ostream_iterator<int>(cout, " "));     // выводим на экран список через пробел
            cout << endl << endl;                                                   // переход на строку ниже
            break;
            //............................................

        case '2':                                   // Удалить несколько элементов с заданной позиции
            cout << "Удаление элементов списка 1: \n";
            cout << "С какого номера элемента = ";
            cin >> a;
            cout << endl;
            cout << "По какой номера элемента = ";
            cin >> b;
            cout << endl;

            std::advance(vi, a);
            std::advance(v3, b);
            myList.erase(vi, v3);                                                      // удаляем последний элемент
            copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));   // выводим на экран список через пробел
            cout << endl << endl;                                                   // переход на строку ниже

            break;
            //............................................

        case '3':                                   // Добавить несколько элементов в заданную позицию c друго list
            cout << "Добавление элементов из другого списка: \n";
            cout << "С какого номера элемента вставить элементы в список 1 = ";
            cin >> k;
            cout << endl;
            cout << "С какого номера элемента вставить элементы из списка 2 = ";
            cin >> x;
            cout << endl;
            cout << "По какой номер элемента вставить элементы из списка 2 = ";
            cin >> y;
            cout << endl;

            std::advance(v4, k);
            std::advance(v1, x);
            std::advance(v2, y);
            myList.insert(v4, v1, v2);                    // вставляем nList в myList
            copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));   // выводим на экран список через пробел
            cout << endl << endl;                                                   // переход на строку ниже
            break;
            //............................................

        case '4':                                   // Удалить парные элементы
            cout << "Удаление парных элементов: \n";
            myList.unique();                                                        // удаляем соседние повторяющиеся элементы
            copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));   // выводим на экран список через пробел
            cout << endl << endl;                                                   // переход на строку ниже
            break;
            //............................................

        case '5':                       // Подсчитать сколько элементов одного массива больше соответствующих элементов другого массива
            cout << "Подсчитать сколько элементов одного массива больше соответствующих элементов другого массива: \n";
          r2 = std::inner_product(myList.begin(), myList.end(), nList.begin(), 0,
                std::plus<int>(), std::greater<int>());
            cout << " Элементов в первом массиве больше чем во втором=  "<<r2;
            cout << endl << endl;                                                   // переход на строку ниже
            break;
            //............................................

        case '6':                       // Поиск в списке два одинаковых смежных элемента
            cout << "Поиск в списке два одинаковых смежных элемента: \n";
            result1 = adjacent_find(myList.begin(), myList.end());
            if (result1 == myList.end())
                cout << "нет двух одинаковых смежных элементов";
            else
                cout << "есть два одинаковых смежных элемента  "<<*(result1);
            cout << endl << endl;                                                   // переход на строку ниже
            break;
            //............................................

        case '7':                                                                   // выход из программы
            exit(0);

        default:
            cout << "\a";
        }
    } while (ch != '7');

}