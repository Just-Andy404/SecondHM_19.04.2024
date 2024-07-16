/*
Создайте класс очереди с приоритетами для работы с целыми
значениями. Требуется создать реализации для типичных
операций над элементами очереди:
■ IsEmpty - проверка очереди на пустоту;
■ IsFull - проверка очереди на заполнение;
■ InsertWithPriority - добавление элемента с приоритетом в очередь;
■ PullHighestPriorityElement - удаление элемента с наивысшим приоритетом из очереди;
■ Peek - возврат наибольшего по приоритету элемента. Обращаем ваше внимание, что элемент не удаляется из очереди;
■ Show - вывод всех элементов очереди на экран.
При показе элемента также необходимо отображать
приоритет
*/
#pragma once
#include <iostream>

using namespace std;

template <class Q>
class Queue
{
	Q* _queue;
	int* _priority;
	int _capacity;
	int _size;
public:
	Queue();
	Queue(int);
	~Queue();
	bool IsEmpty();
	bool IsFull();
	void InsertWithPriority(Q, int);
	Q PullHighestPriorityElement();
	Q Peek();
	void show();
};

template<class Q>
inline Queue<Q>::Queue() : Queue(1) {}

template<class Q>
inline Queue<Q>::Queue(int capacity) : _capacity(capacity), _size(0)
{
	_queue = new Q[_capacity];
	_priority = new int[_capacity];
}

template<class Q>
inline Queue<Q>::~Queue()
{
	delete[] _queue;
	delete[] _priority;
}

template<class Q>
inline bool Queue<Q>::IsEmpty()
{
	return _size == 0;
}

template<class Q>
inline bool Queue<Q>::IsFull()
{
	return _size == _capacity;
}

template<class Q>
inline void Queue<Q>::InsertWithPriority(Q el, int prior)
{
	if (!IsFull())
	{
		_queue[_size] = el;
		_priority[_size] = prior;
		_size++;
	}
}

template<class Q>
inline Q Queue<Q>::PullHighestPriorityElement()
{
	if (!IsEmpty())
	{
		int highestPriorityIndex = 0;
		for (int i = 1; i < _size; i++)
		{
			if (_priority[highestPriorityIndex] < _priority[i])
			{
				highestPriorityIndex = i;
			}
		}
		Q el = _queue[highestPriorityIndex];
		for (int j = highestPriorityIndex; j < _size - 1; j++)
		{
			_queue[j] = _queue[j + 1];
			_priority[j] = _priority[j + 1];
		}
		_size--;
		return el;
	}
	return Q();
}

template<class Q>
inline Q Queue<Q>::Peek()
{
	if (!IsEmpty())
	{
		int highestPriorityIndex = 0;
		for (int i = 1; i < _size; i++)
		{
			if (_priority[highestPriorityIndex] < _priority[i])
			{
				highestPriorityIndex = i;
			}
		}
		return _queue[highestPriorityIndex];
	}
	return Q();
}

template<class Q>
inline void Queue<Q>::show()
{
	cout << "\n-------------------------------------\n";
	for (int i = 0; i < _size; i++) {
		cout << _queue[i] << " - " << _priority[i] << "\n";
	}
	cout << "-------------------------------------\n";
}
