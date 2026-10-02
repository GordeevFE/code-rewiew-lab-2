#include "HeaderTask01.h"
#include <locale>
#include <limits>

int main()
{
    setlocale(LC_ALL, "ru");

    try
    {
        FStack Stack;
        int Choice;
        int Value;

        while (true)
        {
            std::cout << "\nÌåíþ:\n";
            std::cout << "1. Äîáàâèòü ýëåìåíò â ñòåê\n";
            std::cout << "2. Óäàëèòü ýëåìåíò èç ñòåêà\n";
            std::cout << "3. Âûâåñòè ýëåìåíòû ñòåêà\n";
            std::cout << "4. Î÷èñòèòü ñòåê\n";
            std::cout << "5. Âûéòè\n";
            std::cout << "Ââåäèòå âàø âûáîð: ";

            if (!ReadInteger(Choice))
            {
                std::cout << "Îøèáêà ââîäà! Ïîæàëóéñòà, ââåäèòå ÷èñëî." << std::endl;
                continue;
            }

            switch (Choice)
            {
            case 1:
                std::cout << "Ââåäèòå ÷èñëî äëÿ äîáàâëåíèÿ â ñòåê: ";
                if (!ReadInteger(Value))
                {
                    std::cout << "Îøèáêà ââîäà! Ïîæàëóéñòà, ââåäèòå ÷èñëî." << std::endl;
                    break;
                }

                try
                {
                    AddElementAndPrintAddress(Stack, Value);
                }
                catch (const FStackException& Exception)
                {
                    std::cout << "Îøèáêà ïðè äîáàâëåíèè ýëåìåíòà: " << Exception.what() << std::endl;
                }
                break;

            case 2:
                try
                {
                    Stack.Pop();
                }
                catch (const FStackException& Exception)
                {
                    std::cout << Exception.what() << std::endl;
                }
                break;

            case 3:
                Stack.Print();
                break;

            case 4:
                Stack.ClearStack();
                break;

            case 5:
                std::cout << "Âûõîä èç ïðîãðàììû." << std::endl;
                return 0;

            default:
                std::cout << "Íåâåðíûé âûáîð! Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà." << std::endl;
            }
        }
    }
    catch (const FStackException& Exception)
    {
        std::cerr << "Êðèòè÷åñêàÿ îøèáêà ñòåêà: " << Exception.what() << std::endl;
        return 1;
    }
    catch (const std::exception& Exception)
    {
        std::cerr << "Íåèçâåñòíàÿ îøèáêà: " << Exception.what() << std::endl;
        return 2;
    }

    return 0;
}
