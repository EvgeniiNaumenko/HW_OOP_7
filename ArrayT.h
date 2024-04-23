#pragma once
#pragma once
#include<iostream>

using namespace std;

template<class T >
class ArrayT
{
	T* _array;
	int _size;
	int _capacity;
	int _grow;
public:
	ArrayT();
	ArrayT(int);
	~ArrayT();
	int getSize();				//■ GetSize — отримання розміру масиву(кількість елементів, під які виділено пам’ять);
	void setSize(int, int);		//■ SetSize(int size, int grow = 1) — щоб вибрати розмір
								//масиву(якщо параметр size більший за попередній
								//	розмір масиву, то виділяється додатковий блок пам’яті, якщо ні, то «зайві» елементи губляться і пам’ять
								//	звільняється); параметр grow визначає для якої кількості елементів необхідно виділити пам’ять, якщо
								//	кількість елементів є більшою від поточного розміру
								//	масиву.Наприклад, SetSize(5, 5); означає, що під час
								//	додавання 6 - го елемента розмір масиву стає рівним
								//	10, під час додавання 11 - го — 15 і т.д.;
	int getUpperBound();		// ■ GetUpperBound — отримання останнього допустимого
								//індексу в масиві.Наприклад, якщо за розміру масиву 10,
								//ви додаєте до нього 4 елементи, то функція поверне 3;
	bool isAmpty();				//■ IsEmpty — масив порожній ? ;
	void freeExtra();			//■ FreeExtra — видалити «зайву» пам’ять(вище останнього допустимого індексу);
	void removeAll();			//■ RemoveAll — видалити всі;
	T getAt(int);				//■ GetAt — отримання певного елемента(за індексом);
	void setAt(T, int);			//■ SetAt — встановлення нового значення для певного
								//елемента(індекс елемента повинен бути меншим за
								//	поточний розмір масиву);
	T& operator [](int);			//■ operator [] — для реалізації двох попередніх функцій;
	void add(T);				//■ Add — додавання елемента в масив(за необхідності
								//	масив збільшується на значення grow функції SetSize);
	void append(const ArrayT&);				//■ Append — «складання» двох масивів;
	void operator= (const ArrayT&);			//■ operator =;
	T* getData();				//■ GetData — отримання адреси масиву з даними;
	void insertAt(T*,int, int);		//■ InsertAt — вставлення елемента(-ів) в задану позицію;
	void removeAt(int,int);			//■ RemoveAt — видалення елемента(-ів) із заданої позиції.
	void print();
};

template<class T>
inline ArrayT<T>::ArrayT():ArrayT<T>(1){}

template<class T>
inline ArrayT<T>::ArrayT(int cap)
{
	_capacity = cap;
	_array = new T[_capacity];
	_size = 0;
	_grow = 1;
}

template<class T>
inline ArrayT<T>::~ArrayT()
{
	if (_array!= nullptr)
	{
		delete[] _array;
	}
}

template<class T>
inline int ArrayT<T>::getSize()
{
	return _capacity;
}

template<class T>
inline void ArrayT<T>::setSize(int capacity, int grow)
{
	int length;
	if (capacity >= _size)
	{
		length = _size;
	}
	else
		length = capacity;

	T* newArr = new T[capacity];
	for (int i = 0; i < length; i++)
	{
		newArr[i] = _array[i];
	}
	delete[]_array;
	_array = newArr;
	_grow = grow;
	_capacity = capacity;
	_size = length;
	
}

template<class T>
inline int ArrayT<T>::getUpperBound()
{
	return _size;
}

template<class T>
inline bool ArrayT<T>::isAmpty()
{
	if (_size==_capacity)
	{
		return true;
	}
	return false;
}

template<class T>
inline void ArrayT<T>::freeExtra()
{
	if (_size!=_capacity)
	{
		T* newArr = new T[_size];
		for (int i = 0; i < _size; i++)
		{
			newArr[i] = _array[i];
		}
		delete[]_array;
		_array = newArr;
		_capacity = _size;
	}
}

template<class T>
inline void ArrayT<T>::removeAll()
{
	for (int i = 0; i < _capacity; i++)
	{
		_array[i] = NULL;
	}
}

template<class T>
inline T ArrayT<T>::getAt(int index)
{
	if (index >= 0 && index<_size)
	{
		return _array[index];
	}
	else
		return NULL;

}

template<class T>
inline void ArrayT<T>::setAt(T el, int index)
{
	if (index >=0 && index <=_size)
	{
		_array[index] = el;
	}
}

template<class T>
inline T& ArrayT<T>::operator[](int index)
{
	if (index>=0 && index <=_size)
	{
		return _array[index];
	}
}

template<class T>
inline void ArrayT<T>::add(T el)
{
	if (_size < _capacity)
	{
		_array[_size] = el;
		_size++;
	}
	else
	{
		_capacity += _grow;
		T* newArr = new T[_capacity ];
		for (int i = 0; i < _size; i++)
		{
			newArr[i] = _array[i];
		}
		newArr[_size] = el;
		_size++;
		delete[]_array;
		_array = newArr;
	}
}

template<class T>
inline void ArrayT<T>::append(const ArrayT& arr) // траблы
{
	_capacity += arr._capacity;
	T* newArr = new T[_capacity];
	int j = 0;
	for (int i = 0; i < _size; i++)
	{
		newArr[j] = _array[i];
		j++;
	}
	for (int i = 0; i < arr._size; i++)
	{
		newArr[j] = arr._array[i];
		j++;
	}
	_size += arr._size;
	delete[] _array;
	_array = newArr;
}

template<class T>
inline void ArrayT<T>::operator=(const ArrayT& arr) // ТУТ БЕДА
{
	_capacity = arr._capacity;
	_size = arr._size;
	_array = new T[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_array[i] = arr._array[i];
	}
}

template<class T>
inline T* ArrayT<T>::getData()
{
	return _array;
}

template<class T>
inline void ArrayT<T>::insertAt(T* arr,int size, int index)
{
	if (_capacity-_size < size)
	{
		T* newArr = new T[_capacity+size];
		_size += size;
		for (int i = 0, j = 0 , k = 0; i < _size; i++)
		{
			if (i == index+j && j<size)
			{
				newArr[i] = arr[j];
				j++;
			}
			else
			{
				newArr[i] = _array[k];
				k++;
			}
		}
		delete[]_array;
		_array = newArr;
		_capacity += size;
	}
}

template<class T>
inline void ArrayT<T>::removeAt(int index, int quantity)
{
	if (index >=0  && index+quantity-1 <_size)
	{
		T* newArr = new T[_capacity];
		for (int i = 0,j=0; i < _size; i++)
		{
			if (i <index || i>index+quantity-1)
			{
				newArr[j] = _array[i];
				j++;
			}
		}
		delete[] _array;
		_array = newArr;
		_size--;
	}
}

template<class T>
inline void ArrayT<T>::print()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _array[i] << " ";
	}
	cout << endl;
}
