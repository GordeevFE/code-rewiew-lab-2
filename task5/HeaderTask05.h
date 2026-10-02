/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны вектор V, дек D и список L. Каждый исходный контейнер содержит не менее
двух элементов, количество элементов является четным. Поменять значения двух средних
элементов каждого из исходных контейнеров. Использовать алгоритм swap (не путать его с
одноименной функцией-членом контейнера).*/

#ifndef CONTAINER_TASKS_H
#define CONTAINER_TASKS_H

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <limits>
#include <exception>

//FIX_ME: запрещается использование
//using namespace std;

// Класс исключения для ошибок контейнеров
class FContainerException : public std::exception
{
public:
    explicit FContainerException(const std::string& InMessage) : Message(InMessage) {}
    virtual const char* what() const noexcept override { return Message.c_str(); }

private:
    std::string Message;
};

// Перечисление для способа ввода
enum class EInputMethod
{
    Keyboard = 1,
    Random = 2,
    File = 3
};

// Проверка корректности размера контейнера
bool IsValidSize(int InSize);

// Ввод данных в контейнер
template <typename ContainerType>
void InputContainer(ContainerType& OutContainer, int InSize);

// Вывод содержимого контейнера
template <typename ContainerType>
void PrintContainer(const ContainerType& InContainer);

// Пользовательская функция swap
void SwapValues(int& InOutA, int& InOutB);

// Обмен значений двух средних элементов
template <typename ContainerType>
void SwapMiddleElements(ContainerType& InOutContainer);

// Ввод числа с проверкой
int ReadInteger(const std::string& InPrompt);

// Выбор способа ввода
EInputMethod SelectInputMethod();

// Чтение данных из файла
void ReadValuesFromFile(int* OutValues, int InExpectedCount, const char* InFileName);

#endif // CONTAINER_TASKS_H
