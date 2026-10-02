/* Дан двусвязный линейный список и указатель на первый элемент этого
списка. Создать текстовый файл, в который вывести содержимое списка в обратном
порядке. По ходу вывода списка удалять элементы в нем. Числа выводить в одну строку,
разделяя ровно одним пробелом, в конце строки пробел не ставить.


Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
дружественного интерфейса. Ввод данных с клавиатуры. */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <exception>

//FIX_ME: запрещается использование
//using namespace std;

// Класс исключения для ошибок списка
class FListException : public std::exception
{
public:
    FListException(const std::string& Message) : ErrorMessage(Message) {}
    virtual const char* what() const noexcept override { return ErrorMessage.c_str(); }

private:
    std::string ErrorMessage;
};

//FIX_ME: отсутствие префикса у структуры
struct FNode
{
    int Data;           // Данные узла
    FNode* Previous;    // Указатель на предыдущий узел
    FNode* Next;        // Указатель на следующий узел

    // Конструктор узла
    FNode(int Value);
};

//FIX_ME: отсутствие префикса у класса
//FIX_ME: отсутствие конструктора и деструктора
class FDoubleList
{
public:
    // Конструктор и деструктор
    FDoubleList();
    ~FDoubleList();

    //FIX_ME: некорректное имя метода

    // Добавление элемента в конец списка
    void AddElement(int Value);

    // Удаление указанного узла
    void DeleteElement(FNode* NodeToDelete);

    // Вывод списка на экран
    void Print() const;

    // Запись в файл в обратном порядке и удаление элементов
    void WriteToFileAndClear(const std::string& FileName);

    // Очистка всего списка
    void Clear();

    // Проверка пустоты списка
    bool IsEmpty() const;

private:
    FNode* First; // Указатель на первый узел
};

//FIX_ME: некорректное имя функции

// Функция для ввода числа с проверкой
int InputNumber();

// Функция для вывода содержимого файла
void PrintFileContent(const std::string& FileName);

#endif // DOUBLELINKEDLIST_H
