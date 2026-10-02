#include "HeaderTask02.h"
#include <locale>
#include <limits>
#include <string>

int main()
{
    setlocale(LC_ALL, "ru");

    try
    {
        FQueue Queue;
        std::string InputString;
        int ElementCount;
        int Value;

        // Ââîä êîëè÷åñòâà ýëåìåíòîâ
        std::cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ â î÷åðåäè: ";
        std::cin >> InputString;

        if (!IsNumber(InputString))
        {
            throw FQueueException("Íåäîïóñòèìîå çíà÷åíèå äëÿ êîëè÷åñòâà ýëåìåíòîâ");
        }

        ElementCount = std::stoi(InputString);

        if (ElementCount <= 0)
        {
            throw FQueueException("Êîëè÷åñòâî ýëåìåíòîâ äîëæíî áûòü ïîëîæèòåëüíûì ÷èñëîì");
        }

        // Ââîä ýëåìåíòîâ î÷åðåäè
        std::cout << "Ââåäèòå ýëåìåíòû î÷åðåäè: ";
        for (int i = 1; i <= ElementCount; ++i)
        {
            std::cin >> InputString;

            if (!IsNumber(InputString))
            {
                throw FQueueException("Íåäîïóñòèìîå çíà÷åíèå äëÿ ýëåìåíòà î÷åðåäè");
            }

            Value = std::stoi(InputString);
            Queue.Push(Value);
        }

        // Âûâîä èñõîäíîé î÷åðåäè
        std::cout << "Èçíà÷àëüíàÿ î÷åðåäü: ";
        Queue.Show();

        // Îáðàáîòêà ÷åòíîñòè ãîëîâû
        Queue.ProcessEvenHead();

        // Âûâîä èçìåíåííîé î÷åðåäè
        std::cout << "Èçìåíåííàÿ î÷åðåäü: ";
        Queue.Show();

        // Âûâîä èíôîðìàöèè î íà÷àëå î÷åðåäè
        if (!Queue.IsEmpty())
        {
            try
            {
                std::cout << "Çíà÷åíèå ïåðâîãî ýëåìåíòà: " << Queue.GetHeadValue() << std::endl;
            }
            catch (const FQueueException& Exception)
            {
                std::cout << "Îøèáêà ïðè ïîëó÷åíèè çíà÷åíèÿ ãîëîâû: " << Exception.what() << std::endl;
            }

            std::cout << "Íîâûé àäðåñ íà÷àëà î÷åðåäè (P1): " << Queue.GetHead() << std::endl;

            try
            {
                std::cout << "Çíà÷åíèå ïîñëåäíåãî ýëåìåíòà: " << Queue.GetTailValue() << std::endl;
            }
            catch (const FQueueException& Exception)
            {
                std::cout << "Îøèáêà ïðè ïîëó÷åíèè çíà÷åíèÿ õâîñòà: " << Exception.what() << std::endl;
            }

            std::cout << "Íîâûé àäðåñ êîíöà î÷åðåäè (P2): " << Queue.GetTail() << std::endl;
        }
        else
        {
            std::cout << "Î÷åðåäü ïóñòà" << std::endl;
            std::cout << "Íîâûé àäðåñ íà÷àëà î÷åðåäè (P1): nullptr" << std::endl;
            std::cout << "Íîâûé àäðåñ êîíöà î÷åðåäè (P2): nullptr" << std::endl;
        }
    }
    catch (const FQueueException& Exception)
    {
        std::cerr << "Îøèáêà: " << Exception.what() << std::endl;
        return 1;
    }
    catch (const std::exception& Exception)
    {
        std::cerr << "Íåèçâåñòíàÿ îøèáêà: " << Exception.what() << std::endl;
        return 2;
    }

    return 0;
}
