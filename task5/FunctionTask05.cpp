#include "HeaderTask05.h"

//FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê

// Ïðîâåðêà êîððåêòíîñòè ðàçìåðà êîíòåéíåðà
bool IsValidSize(int InSize)
{
    return (InSize >= 2 && InSize % 2 == 0);
}

// Âûáîð ñïîñîáà ââîäà
EInputMethod SelectInputMethod()
{
    int Choice;

    std::cout << "Âûáåðèòå ñïîñîá çàïîëíåíèÿ êîíòåéíåðà:" << std::endl;
    std::cout << "1) Ââîä ñ êëàâèàòóðû" << std::endl;
    std::cout << "2) Ââîä ñ ïîìîùüþ ðàíäîìàéçåðà" << std::endl;
    std::cout << "3) Ââîä äàííûõ èç òåêñòîâîãî ôàéëà" << std::endl;

    while (true)
    {
        Choice = ReadInteger("Âàø âûáîð (1-3): ");

        if (Choice >= 1 && Choice <= 3)
        {
            return static_cast<EInputMethod>(Choice);
        }

        std::cout << "Íåâåðíûé âûáîð. Ïîæàëóéñòà, ââåäèòå 1, 2 èëè 3." << std::endl;
    }
}

// Ââîä ÷èñëà ñ ïðîâåðêîé
int ReadInteger(const std::string& InPrompt)
{
    int Value;

    while (true)
    {
        std::cout << InPrompt;

        if (std::cin >> Value)
        {
            return Value;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Îøèáêà ââîäà. Ïîæàëóéñòà, ââåäèòå öåëîå ÷èñëî." << std::endl;
        }
    }
}

// ×òåíèå äàííûõ èç ôàéëà
void ReadValuesFromFile(int* OutValues, int InExpectedCount, const char* InFileName)
{
    std::ifstream File(InFileName, std::ios::in);

    if (!File.is_open())
    {
        throw FContainerException("Îøèáêà: Íå óäàëîñü îòêðûòü ôàéë '" + std::string(InFileName) + "'");
    }

    for (int Index = 0; Index < InExpectedCount; ++Index)
    {
        File >> OutValues[Index];

        if (File.fail())
        {
            File.close();
            throw FContainerException("Îøèáêà: Íåäîñòàòî÷íî äàííûõ â ôàéëå èëè íåêîððåêòíûé ôîðìàò.");
        }
    }

    File.close();
}

// Ïîëüçîâàòåëüñêàÿ ôóíêöèÿ swap
void SwapValues(int& InOutA, int& InOutB)
{
    int Temp = InOutA;
    InOutA = InOutB;
    InOutB = Temp;
}

// Ââîä äàííûõ â êîíòåéíåð
template <typename ContainerType>
void InputContainer(ContainerType& OutContainer, int InSize)
{
    // Ïðîâåðêà êîððåêòíîñòè ðàçìåðà
    if (!IsValidSize(InSize))
    {
        throw FContainerException("Îøèáêà: Íåäîïóñòèìûé ðàçìåð êîíòåéíåðà. Òðåáóåòñÿ >= 2 è ÷åòíîå ÷èñëî.");
    }

    EInputMethod Method = SelectInputMethod();
    int Value;

    switch (Method)
    {
    case EInputMethod::Keyboard:
    {
        // Ââîä ñ êëàâèàòóðû
        for (int Index = 0; Index < InSize; ++Index)
        {
            std::string Prompt = "Ââåäèòå " + std::to_string(Index + 1) + "-é ýëåìåíò: ";
            Value = ReadInteger(Prompt);
            OutContainer.insert(OutContainer.end(), Value);
        }
        break;
    }

    case EInputMethod::Random:
    {
        // Ââîä ñëó÷àéíûìè ÷èñëàìè
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        for (int Index = 0; Index < InSize; ++Index)
        {
            Value = std::rand() % 101 - 50; // îò -50 äî 50
            OutContainer.insert(OutContainer.end(), Value);
        }
        std::cout << "Ñãåíåðèðîâàíî " << InSize << " ñëó÷àéíûõ ÷èñåë." << std::endl;
        break;
    }

    case EInputMethod::File:
    {
        // Ââîä èç ôàéëà
        int* Buffer = new int[InSize];

        try
        {
            ReadValuesFromFile(Buffer, InSize, "a.txt");
            for (int Index = 0; Index < InSize; ++Index)
            {
                OutContainer.insert(OutContainer.end(), Buffer[Index]);
            }
        }
        catch (...)
        {
            delete[] Buffer;
            throw;
        }

        delete[] Buffer;
        break;
    }

    default:
        throw FContainerException("Îøèáêà: Íåâåðíûé âûáîð ñïîñîáà ââîäà.");
    }
}

// Âûâîä ñîäåðæèìîãî êîíòåéíåðà
template <typename ContainerType>
void PrintContainer(const ContainerType& InContainer)
{
    if (InContainer.empty())
    {
        std::cout << "(êîíòåéíåð ïóñò)";
        return;
    }

    // Âûâîä â ïðÿìîì ïîðÿäêå ñ èñïîëüçîâàíèåì èòåðàòîðà
    for (auto Iter = InContainer.begin(); Iter != InContainer.end(); ++Iter)
    {
        std::cout << *Iter << " ";

        if (std::cout.fail())
        {
            throw FContainerException("Îøèáêà ïðè âûâîäå äàííûõ.");
        }
    }
    std::cout << std::endl;

    // Âûâîä â îáðàòíîì ïîðÿäêå ñ èñïîëüçîâàíèåì îáðàòíûõ èòåðàòîðîâ (rbegin/rend)
    std::cout << "Â îáðàòíîì ïîðÿäêå: ";
    for (auto ReverseIter = InContainer.rbegin(); ReverseIter != InContainer.rend(); ++ReverseIter)
    {
        std::cout << *ReverseIter << " ";
    }
    std::cout << std::endl;
}

// Îáìåí çíà÷åíèé äâóõ ñðåäíèõ ýëåìåíòîâ
template <typename ContainerType>
void SwapMiddleElements(ContainerType& InOutContainer)
{
    // Ïðîâåðêà ðàçìåðà êîíòåéíåðà
    if (InOutContainer.size() < 2)
    {
        throw FContainerException("Îøèáêà: Êîíòåéíåð ñîäåðæèò ìåíåå äâóõ ýëåìåíòîâ.");
    }

    if (InOutContainer.size() % 2 != 0)
    {
        throw FContainerException("Îøèáêà: Êîíòåéíåð èìååò íå÷åòíîå êîëè÷åñòâî ýëåìåíòîâ.");
    }

    auto Iter = InOutContainer.begin();
    size_t Size = InOutContainer.size();

    // Äîñòèãàåì ïåðâîãî ñðåäíåãî ýëåìåíòà
    for (size_t Index = 0; Index < Size / 2 - 1; ++Index)
    {
        ++Iter;
    }

    auto FirstMiddle = Iter;   // Ïåðâûé ñðåäíèé ýëåìåíò
    ++Iter;                    // Ïåðåõîäèì êî âòîðîìó
    auto SecondMiddle = Iter;  // Âòîðîé ñðåäíèé ýëåìåíò

    // Èñïîëüçóåì àëãîðèòì swap (íå ôóíêöèþ-÷ëåí êîíòåéíåðà)
    SwapValues(*FirstMiddle, *SecondMiddle);
}

// ßâíîå èíñòàíöèðîâàíèå øàáëîíîâ äëÿ èñïîëüçóåìûõ òèïîâ
template void InputContainer<std::vector<int>>(std::vector<int>& OutContainer, int InSize);
template void InputContainer<std::deque<int>>(std::deque<int>& OutContainer, int InSize);
template void InputContainer<std::list<int>>(std::list<int>& OutContainer, int InSize);

template void PrintContainer<std::vector<int>>(const std::vector<int>& InContainer);
template void PrintContainer<std::deque<int>>(const std::deque<int>& InContainer);
template void PrintContainer<std::list<int>>(const std::list<int>& InContainer);

template void SwapMiddleElements<std::vector<int>>(std::vector<int>& InOutContainer);
template void SwapMiddleElements<std::deque<int>>(std::deque<int>& InOutContainer);
template void SwapMiddleElements<std::list<int>>(std::list<int>& InOutContainer);
