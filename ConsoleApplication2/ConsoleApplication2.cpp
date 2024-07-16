/*
Создайте класс очереди с приоритетами для работы с целыми
значениями. Требуется создать реализации для типичных
операций над элементами очереди:
■ IsEmpty - проверка очереди на пустоту;
■ IsFull - проверка очереди на заполнение;
■ InsertWithPriority - добавление элемента с приоритетом в очередь;
PullHighestPriorityElement - удаление элемента с наивысшим приоритетом из очереди;
■ PullHighestPriorityElement - удаление элемента с
наивысшим приоритетом из очереди;
■ Peek - возврат наибольшего по приоритету элемента. Обращаем ваше внимание, что элемент не удаляется из очереди;
■ Show - вывод всех элементов очереди на экран.
При показе элемента также необходимо отображать
приоритет
*/
#include <iostream>
#include "Queue.h"

using namespace std;

void showMenu() {
    cout << "Меню:\n";
    cout << "1. Проверка очереди на пустоту\n";
    cout << "2. Проверка очереди на заполнение\n";
    cout << "3. Добавление элемента с приоритетом в очередь\n";
    cout << "4. Удаление элемента с наивысшим приоритетом\n";
    cout << "5. Показ элемента с наивысшим приоритетом\n";
    cout << "6. Вывод всех элементов очереди\n";
    cout << "0. Выход\n";
    cout << "Выберите пункт меню: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int capacity;
    cout << "Введите максимальную емкость очереди: ";
    cin >> capacity;

    Queue<int> queue(capacity);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            if (queue.IsEmpty()) {
                cout << "Очередь пуста.\n";
            }
            else {
                cout << "Очередь не пуста.\n";
            }
            break;

        case 2:
            if (queue.IsFull()) {
                cout << "Очередь заполнена.\n";
            }
            else {
                cout << "Очередь не заполнена.\n";
            }
            break;

        case 3:
            if (!queue.IsFull()) {
                int num, priority;
                cout << "Введите число для добавления в очередь: ";
                cin >> num;
                cout << "Введите приоритет: ";
                cin >> priority;
                queue.InsertWithPriority(num, priority);
                cout << "Элемент добавлен.\n";
            }
            else {
                cout << "Очередь заполнена, невозможно добавить элемент.\n";
            }
            break;

        case 4:
            if (!queue.IsEmpty()) {
                int highestPriorityElement = queue.PullHighestPriorityElement();
                cout << "Удален элемент с наивысшим приоритетом: " << highestPriorityElement << endl;
            }
            else {
                cout << "Очередь пуста, невозможно удалить элемент.\n";
            }
            break;

        case 5:
            if (!queue.IsEmpty()) {
                int highestPriorityElement = queue.Peek();
                cout << "Элемент с наивысшим приоритетом: " << highestPriorityElement << endl;
            }
            else {
                cout << "Очередь пуста.\n";
            }
            break;

        case 6:
            cout << "Элементы очереди:\n";
            queue.show();
            break;

        case 0:
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Неверный выбор, попробуйте снова.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
