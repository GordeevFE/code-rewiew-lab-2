/*Дано число D и указатель P1 на вершину непустого стека.
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/   


//FIX_ME: нет разделения на 3 модуля
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <exception>
#include <string>

//FIX_ME: запрещается использование 
//using namespace std;

// FIX_ME: некорректное расположение скобок
// FIX_ME: отсутствие префикса у класса
// FIX_ME: некорректные имена переменных

//class Node {
//public:
//    int data;       
//    Node* next;     
//    Node(int value) : data(value), next(nullptr) {}
//};

class FNode
{
public:
    int Data;
    FNode* NextData;


    FNode(int Value) : Data(Value), NextData(nullptr) {}
};


//FIX_ME: некорректное расположение паблика и привата
class FStack
{
    //private:
    //    FNode* top; 
    //
    //public:
    //    
    //    Stack() : top(nullptr) {}

public:

    FStack();
    ~FStack();

    //FIX_ME: некорректное имя функции
    //void push(int value) {

    // для добавления элемента в стек
    void Push(int Value);

    // Метод для удаления элемента из стека
    void Pop();

    // Функция для вывода стека
    void Print() const;

    // Получение головы стека
    FNode* GetTop() const;

    // Очистка стека
    void ClearStack();

    // Проверка пустоты стека
    bool IsEmpty() const;

    friend void AddElementAndPrintAddress(FStack& Stack, int Value);

private:
    FNode* Top;
};

// Исключение для ошибок стека
class FStackException : public std::exception
{
public:
    FStackException(const std::string& InMessage) : Message(InMessage) {}
    virtual const char* what() const noexcept override { return Message.c_str(); }

private:
    std::string Message;
};


// Проверка корректности входных данных
bool ReadInteger(int& OutValue);

// Добавление элемента и вывод адреса
void AddElementAndPrintAddress(FStack& Stack, int Value);

#endif // STACK_H
