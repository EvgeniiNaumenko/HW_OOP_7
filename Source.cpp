﻿//Завдання №1
//Створити шаблонний клас - контейнер Array, який
//є масивом, що дозволяє зберігати об’єкти заданого типу.
//Клас повинен реалізовувати наступніі функції :
//■ GetSize — отримання розміру масиву(кількість елементів, під які виділено пам’ять);
//■ SetSize(int size, int grow = 1) — щоб вибрати розмір
//масиву(якщо параметр size більший за попередній
//	розмір масиву, то виділяється додатковий блок пам’яті, якщо ні, то «зайві» елементи губляться і пам’ять
//	звільняється); параметр grow визначає для якої кількості елементів необхідно виділити пам’ять, якщо
//	кількість елементів є більшою від поточного розміру
//	масиву.Наприклад, SetSize(5, 5); означає, що під час
//	додавання 6 - го елемента розмір масиву стає рівним
//	10, під час додавання 11 - го — 15 і т.д.;
//■ GetUpperBound — отримання останнього допустимого
//індексу в масиві.Наприклад, якщо за розміру масиву 10,
//ви додаєте до нього 4 елементи, то функція поверне 3;
//■ IsEmpty — масив порожній ? ;
//■ FreeExtra — видалити «зайву» пам’ять(вище останнього допустимого індексу);
//■ RemoveAll — видалити всі;
//Практичні завдання №12
//1
//■ GetAt — отримання певного елемента(за індексом);
//■ SetAt — встановлення нового значення для певного
//елемента(індекс елемента повинен бути меншим за
//	поточний розмір масиву);
//■ operator [] — для реалізації двох попередніх функцій;
//■ Add — додавання елемента в масив(за необхідності
//	масив збільшується на значення grow функції SetSize);
//■ Append — «складання» двох масивів;
//■ operator =;
//■ GetData — отримання адреси масиву з даними;
//■ InsertAt — вставлення елемента(-ів) в задану позицію;
//■ RemoveAt — видалення елемента(-ів) із заданої позиції.

#include <iostream>
using namespace std;
#include "ArrayT.h"

int main()
{
	ArrayT<int> list(5);// наш массив на 5 элементов
	list.add(10); //добавляем элемент в конец
	list.add(15);
	list.add(20);
	list.add(25);
	list.add(30);
	list.print(); //печатаем
	list[0] = 999;
	list.print();
	cout << "Size : " << list.getSize() << endl;
	list.setSize(4, 5);// установил размер 4 с шагом 5
	list.print();
	cout << "last item index: " << list.getUpperBound() << endl;
	cout << list.isAmpty() << endl; // полон ли 1-да 0- нет
	list.add(598);//добавил элемент
	cout << list.isAmpty() << endl; // полон ли 1-да 0- нет
	cout << "Size : " << list.getSize() << endl; // массив стал на 9 элементов
	list.freeExtra(); // удалили 4 свободные ячейки
	cout << "Size : " << list.getSize() << endl; // массив стал на 9 элементов
	list.print(); //печатаем
	cout << "element in index 2: " << list.getAt(2) << endl;
	list.setAt(666, 2);
	list.print(); //печатаем
	ArrayT<int> list2(2);
	list2.add(77);
	list2.add(4321);
	list2.print(); //печатаем
	cout << "Arr adress: " << list.getData() << endl;
	list2.removeAt(0, 1); // удаляем 1 элмент по индексу 0
	list2.print(); //печатаем
	int* arr = new int[3] { 5, 6, 7 };
	list2.insertAt(arr, 3, 0); // вставим массив арр размером 3 на 0 индекс массива лист2
	list2.print(); //печатаем
	list.append(list2); // склеили 1й лист и 2й  в первом листе
	list.print(); //печатаем
	ArrayT<int> list3;
	list3 = list2; //копируем лист 2 в лист 3
	list3.add(777777);
	list3.print(); //печатаем

	
	return 0;
}