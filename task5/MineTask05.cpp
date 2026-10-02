#include "HeaderTask05.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        int Size1, Size2, Size3;
        std::vector<int> Vector;
        std::deque<int> Deque;
        std::list<int> List;

        // Ââîä ðàçìåðîâ êîíòåéíåðîâ
        std::cout << "=== Ââîä ðàçìåðîâ êîíòåéíåðîâ ===" << std::endl;
        std::cout << "Âñå ðàçìåðû äîëæíû áûòü >= 2 è ÷åòíûìè." << std::endl;

        // Ââîä äëÿ âåêòîðà
        while (true)
        {
            try
            {
                Size1 = ReadInteger("Ââåäèòå ðàçìåðíîñòü âåêòîðà n1: ");

                if (IsValidSize(Size1))
                {
                    break;
                }

                std::cout << "Íåêîððåêòíûé ðàçìåð. Ïîïðîáóéòå ñíîâà." << std::endl;
            }
            catch (const FContainerException& Exception)
            {
                std::cout << "Îøèáêà: " << Exception.what() << std::endl;
            }
        }

        // Ââîä äëÿ äåêà
        while (true)
        {
            try
            {
                Size2 = ReadInteger("Ââåäèòå ðàçìåðíîñòü äåêà n2: ");

                if (IsValidSize(Size2))
                {
                    break;
                }

                std::cout << "Íåêîððåêòíûé ðàçìåð. Ïîïðîáóéòå ñíîâà." << std::endl;
            }
            catch (const FContainerException& Exception)
            {
                std::cout << "Îøèáêà: " << Exception.what() << std::endl;
            }
        }

        // Ââîä äëÿ ñïèñêà
        while (true)
        {
            try
            {
                Size3 = ReadInteger("Ââåäèòå ðàçìåðíîñòü ñïèñêà n3: ");

                if (IsValidSize(Size3))
                {
                    break;
                }

                std::cout << "Íåêîððåêòíûé ðàçìåð. Ïîïðîáóéòå ñíîâà." << std::endl;
            }
            catch (const FContainerException& Exception)
            {
                std::cout << "Îøèáêà: " << Exception.what() << std::endl;
            }
        }

        // Çàïîëíåíèå êîíòåéíåðîâ
        std::cout << "\n=== Çàïîëíåíèå âåêòîðà ===" << std::endl;
        InputContainer(Vector, Size1);

        std::cout << "\n=== Çàïîëíåíèå äåêà ===" << std::endl;
        InputContainer(Deque, Size2);

        std::cout << "\n=== Çàïîëíåíèå ñïèñêà ===" << std::endl;
        InputContainer(List, Size3);

        // Âûâîä èñõîäíûõ êîíòåéíåðîâ
        std::cout << "\n=== Èñõîäíîå ñîäåðæèìîå êîíòåéíåðîâ ===" << std::endl;

        std::cout << "Âåêòîð: ";
        PrintContainer(Vector);

        std::cout << "Äåê: ";
        PrintContainer(Deque);

        std::cout << "Ñïèñîê: ";
        PrintContainer(List);

        // Îáìåí ñðåäíèõ ýëåìåíòîâ
        SwapMiddleElements(Vector);
        SwapMiddleElements(Deque);
        SwapMiddleElements(List);

        // Âûâîä èçìåíåííûõ êîíòåéíåðîâ
        std::cout << "\n=== Èçìåíåííîå ñîäåðæèìîå êîíòåéíåðîâ ===" << std::endl;

        std::cout << "Âåêòîð: ";
        PrintContainer(Vector);

        std::cout << "Äåê: ";
        PrintContainer(Deque);

        std::cout << "Ñïèñîê: ";
        PrintContainer(List);
    }
    catch (const FContainerException& Exception)
    {
        std::cerr << "Îøèáêà êîíòåéíåðà: " << Exception.what() << std::endl;
        return 1;
    }
    catch (const std::exception& Exception)
    {
        std::cerr << "Íåèçâåñòíàÿ îøèáêà: " << Exception.what() << std::endl;
        return 2;
    }

    std::cout << "      /\\     /\\  " << std::endl;
    std::cout << "     {  `---'  } " << std::endl;
    std::cout << "     {  O   O  } " << std::endl;
    std::cout << "     ~~>  V  <~~ " << std::endl;

    return 0;
}
