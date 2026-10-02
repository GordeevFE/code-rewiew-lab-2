#include "HeaderTask04.h"
#include <limits>

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        //FIX_ME: íåêîððåêòíîå èìÿ ïåðåìåííîé
        FDoubleList MyList;

        std::cout << "=== Ââîä ÷èñåë â ñïèñîê ===" << std::endl;

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        while (true)
        {
            try
            {
                int Number = InputNumber();

                //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
                if (Number == -1)
                {
                    break;
                }

                MyList.AddElement(Number);
            }
            catch (const FListException& Exception)
            {
                std::cerr << "Îøèáêà ââîäà: " << Exception.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Ïðîäîëæàåì ââîä
            }
        }

        try
        {
            MyList.Print();
        }
        catch (const FListException& Exception)
        {
            std::cerr << "Îøèáêà ïðè âûâîäå ñïèñêà: " << Exception.what() << std::endl;
        }

        std::cout << "\n=== Çàïèñü â ôàéë ===" << std::endl;

        //FIX_ME: íåêîððåêòíîå èìÿ ïåðåìåííîé
        std::string FileName;
        std::cout << "Ââåäèòå èìÿ ôàéëà: ";

        if (!(std::cin >> FileName))
        {
            throw FListException("Îøèáêà ÷òåíèÿ èìåíè ôàéëà");
        }

        try
        {
            MyList.WriteToFileAndClear(FileName);
            PrintFileContent(FileName);
        }
        catch (const FListException& Exception)
        {
            std::cerr << "Îøèáêà ïðè ðàáîòå ñ ôàéëîì: " << Exception.what() << std::endl;
            return 2;
        }
    }
    catch (const FListException& Exception)
    {
        std::cerr << "Êðèòè÷åñêàÿ îøèáêà: " << Exception.what() << std::endl;
        return 1;
    }
    catch (const std::exception& Exception)
    {
        std::cerr << "Íåèçâåñòíàÿ îøèáêà: " << Exception.what() << std::endl;
        return 3;
    }

    return 0;
}
