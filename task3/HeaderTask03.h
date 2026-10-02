/*
Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно
наличие дружественного интерфейса. Ввод данных с клавиатуры.


Дан текстовый файл, в первой строке которого хранится число N, а во второй
строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
нарушалась его упорядоченность.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>

//FIX_ME: запрещается использование 
//using namespace std;

//FIX_ME: отсутствие префикса у класса
//FIX_ME: некорректные имена переменных
class FNode
{
public:
    int Data;
    FNode* Next;

    // Конструктор
    FNode(int Value) : Data(Value), Next(nullptr) {}
};

//FIX_ME: отсутствие префикса у класса
//FIX_ME: некорректное расположение public/private
class FLinkedList
{
public:
    // Конструктор
    FLinkedList();

    // Деструктор
    ~FLinkedList();

    //FIX_ME: некорректное имя функции
    // Метод для вставки элемента с сохранением упорядоченности по убыванию
    void InsertSorted(int Value);

    // Метод для вывода списка
    void Print() const;

    // Метод для чтения данных из файла
    void ReadFromFile(const std::string& Filename);

    // Метод для очистки списка
    void Clear();

    // Дружественная функция
    friend void ReadFromFile(FLinkedList& List, const std::string& Filename);

private:
    FNode* Head; // Указатель на начало списка
};

// Дружественная функция для чтения из файла
void ReadFromFile(FLinkedList& List, const std::string& Filename);

#endif // LINKEDLIST_H
