#include "HeaderTask04.h"
#include <limits>

// Êîíñòðóêòîð óçëà
FNode::FNode(int Value) : Data(Value), Previous(nullptr), Next(nullptr) {}

// Êîíñòðóêòîð ñïèñêà
FDoubleList::FDoubleList() : First(nullptr) {}

// Äåñòðóêòîð ñïèñêà
FDoubleList::~FDoubleList()
{
    try
    {
        Clear();
    }
    catch (...)
    {
        // Èãíîðèðóåì èñêëþ÷åíèÿ â äåñòðóêòîðå
    }
}

// Ïðîâåðêà ïóñòîòû ñïèñêà
bool FDoubleList::IsEmpty() const
{
    return First == nullptr;
}

//FIX_ME: íåêîððåêòíîå èìÿ ìåòîäà
// Äîáàâëåíèå ýëåìåíòà â êîíåö ñïèñêà
void FDoubleList::AddElement(int Value)
{
    //FIX_ME: îòñóòñòâèå ïðîâåðêè âûäåëåíèÿ ïàìÿòè
    FNode* NewNode = nullptr;

    try
    {
        NewNode = new FNode(Value);
    }
    catch (const std::bad_alloc&)
    {
        throw FListException("Îøèáêà âûäåëåíèÿ ïàìÿòè ïðè äîáàâëåíèè ýëåìåíòà");
    }

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (First == nullptr)
    {
        First = NewNode;
    }
    else
    {
        FNode* Current = First;

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }

        Current->Next = NewNode;
        NewNode->Previous = Current;
    }
}

//FIX_ME: íåêîððåêòíîå èìÿ ìåòîäà
// Óäàëåíèå óêàçàííîãî óçëà
void FDoubleList::DeleteElement(FNode* NodeToDelete)
{
    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (NodeToDelete == nullptr)
    {
        throw FListException("Ïîïûòêà óäàëèòü íåñóùåñòâóþùèé óçåë");
    }

    FNode* Prev = NodeToDelete->Previous;
    FNode* Next = NodeToDelete->Next;

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (Prev != nullptr)
    {
        Prev->Next = Next;
    }
    else
    {
        First = Next;
    }

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (Next != nullptr)
    {
        Next->Previous = Prev;
    }

    delete NodeToDelete;
}

//FIX_ME: íåêîððåêòíîå èìÿ ìåòîäà
// Âûâîä ñïèñêà íà ýêðàí
void FDoubleList::Print() const
{
    //FIX_ME: èñïîëüçîâàíèå cout áåç ïðåôèêñà std::
    if (IsEmpty())
    {
        std::cout << "Ñïèñîê ïóñò!" << std::endl;
        return;
    }

    FNode* Current = First;
    std::cout << "Ñïèñîê: ";

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";

        if (std::cout.fail())
        {
            throw FListException("Îøèáêà ïðè âûâîäå äàííûõ");
        }

        Current = Current->Next;
    }

    std::cout << std::endl;
}

//FIX_ME: íåêîððåêòíîå èìÿ ìåòîäà
// Çàïèñü â ôàéë â îáðàòíîì ïîðÿäêå è óäàëåíèå ýëåìåíòîâ
void FDoubleList::WriteToFileAndClear(const std::string& FileName)
{
    //FIX_ME: îòñóòñòâèå ïðîâåðêè îòêðûòèÿ ôàéëà
    std::ofstream File(FileName);

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (!File.is_open())
    {
        throw FListException("Îøèáêà îòêðûòèÿ ôàéëà äëÿ çàïèñè: " + FileName);
    }

    if (IsEmpty())
    {
        File.close();
        std::cout << "Ñïèñîê ïóñò. Ñîçäàí ïóñòîé ôàéë." << std::endl;
        return;
    }

    bool bFirstElement = true;
    FNode* Current = First;

    // Íàõîäèì ïîñëåäíèé ýëåìåíò
    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (Current != nullptr && Current->Next != nullptr)
    {
        Current = Current->Next;
    }

    // Çàïèñûâàåì è óäàëÿåì ýëåìåíòû ñ êîíöà
    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (Current != nullptr)
    {
        //FIX_ME: èñïîëüçîâàíèå File áåç ïðåôèêñà std::
        if (bFirstElement)
        {
            File << Current->Data;
            bFirstElement = false;
        }
        else
        {
            File << " " << Current->Data;
        }

        // Ïðîâåðêà îøèáîê çàïèñè
        if (File.fail())
        {
            throw FListException("Îøèáêà ïðè çàïèñè â ôàéë");
        }

        FNode* Previous = Current->Previous;
        DeleteElement(Current);
        Current = Previous;
    }

    File.close();

    if (File.fail())
    {
        throw FListException("Îøèáêà ïðè çàêðûòèè ôàéëà");
    }

    std::cout << "Äàííûå çàïèñàíû â ôàéë è ñïèñîê î÷èùåí." << std::endl;
}

//FIX_ME: íåêîððåêòíîå èìÿ ìåòîäà
// Î÷èñòêà âñåãî ñïèñêà
void FDoubleList::Clear()
{
    FNode* Current = First;

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (Current != nullptr)
    {
        FNode* Next = Current->Next;
        delete Current;
        Current = Next;
    }

    First = nullptr;
}

//FIX_ME: íåêîððåêòíîå èìÿ ôóíêöèè
// Ôóíêöèÿ äëÿ ââîäà ÷èñëà ñ ïðîâåðêîé
int InputNumber()
{
    std::string Input;

    //FIX_ME: èñïîëüçîâàíèå while ñ cin áåç îáðàáîòêè îøèáîê
    while (true)
    {
        std::cout << "Ââåäèòå ÷èñëî (èëè '-1' äëÿ çàâåðøåíèÿ): ";

        if (!(std::cin >> Input))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw FListException("Îøèáêà ÷òåíèÿ ââîäà");
        }

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        if (Input == "-1")
        {
            return -1;
        }

        bool bIsValid = true;
        int Sign = 1;
        size_t StartIndex = 0;

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        if (Input.empty())
        {
            bIsValid = false;
        }
        else if (Input[0] == '-')
        {
            Sign = -1;
            StartIndex = 1;

            //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
            if (Input.size() == 1)
            {
                bIsValid = false;
            }
        }

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        for (size_t i = StartIndex; i < Input.size(); ++i)
        {
            //FIX_ME: èñïîëüçîâàíèå isdigit áåç ïðèâåäåíèÿ òèïà
            if (!isdigit(static_cast<unsigned char>(Input[i])))
            {
                bIsValid = false;
                break;
            }
        }

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        if (bIsValid)
        {
            int Number = 0;

            //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
            for (size_t i = StartIndex; i < Input.size(); ++i)
            {
                // Ïðîâåðêà íà ïåðåïîëíåíèå
                if (Number > (std::numeric_limits<int>::max() - (Input[i] - '0')) / 10)
                {
                    throw FListException("×èñëî ïðåâûøàåò äîïóñòèìûé äèàïàçîí");
                }
                Number = Number * 10 + (Input[i] - '0');
            }

            return Number * Sign;
        }
        else
        {
            std::cout << "Íåêîððåêòíûé ââîä! Èñïîëüçóéòå öèôðû è çíàê '-' â íà÷àëå." << std::endl;
        }
    }
}

//FIX_ME: íåêîððåêòíîå èìÿ ôóíêöèè
// Ôóíêöèÿ äëÿ âûâîäà ñîäåðæèìîãî ôàéëà
void PrintFileContent(const std::string& FileName)
{
    //FIX_ME: îòñóòñòâèå ïðîâåðêè îòêðûòèÿ ôàéëà
    std::ifstream File(FileName);

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (!File.is_open())
    {
        throw FListException("Îøèáêà ïðè îòêðûòèè ôàéëà äëÿ ÷òåíèÿ: " + FileName);
    }

    std::cout << "\n=== Ñîäåðæèìîå ôàéëà ===" << std::endl;
    std::string Line;
    bool bHasContent = false;

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (std::getline(File, Line))
    {
        std::cout << Line << std::endl;
        bHasContent = true;

        if (std::cout.fail())
        {
            throw FListException("Îøèáêà ïðè âûâîäå ñîäåðæèìîãî ôàéëà");
        }
    }

    if (!bHasContent)
    {
        std::cout << "(ôàéë ïóñò)" << std::endl;
    }

    File.close();
}
