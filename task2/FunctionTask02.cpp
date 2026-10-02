#include "HeaderTask02.h"
#include <limits>

// Êîíñòðóêòîð
FQueue::FQueue() : Head(nullptr), Tail(nullptr) {}

// Äåñòðóêòîð
FQueue::~FQueue()
{
    Clear();
}

//FIX_ME: íåêîððåêòíîå èìÿ ôóíêöèè
//void Queue::push(int value)

// Äîáàâëåíèå ýëåìåíòà â î÷åðåäü
void FQueue::Push(int InValue)
{
    try
    {
        FNode* NewNode = new FNode(InValue);

        if (IsEmpty())
        {
            Head = Tail = NewNode;
        }
        else
        {
            Tail->Next = NewNode;
            Tail = NewNode;
        }

        std::cout << "Ýëåìåíò " << InValue << " äîáàâëåí â î÷åðåäü." << std::endl;
    }
    catch (const std::bad_alloc& Exception)
    {
        throw FQueueException("Îøèáêà âûäåëåíèÿ ïàìÿòè ïðè äîáàâëåíèè ýëåìåíòà");
    }
}

// Èçâëå÷åíèå ýëåìåíòà èç î÷åðåäè
bool FQueue::Pop(int& OutValue)
{
    if (IsEmpty())
    {
        return false;
    }

    FNode* Temp = Head;
    OutValue = Head->Data;
    Head = Head->Next;

    if (Head == nullptr)
    {
        Tail = nullptr; // Î÷åðåäü ñòàëà ïóñòîé
    }

    delete Temp;
    return true;
}

// Âûâîä ýëåìåíòîâ î÷åðåäè
void FQueue::Show() const
{
    if (IsEmpty())
    {
        std::cout << "Î÷åðåäü ïóñòàÿ" << std::endl;
        return;
    }

    FNode* Current = Head;
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

// Îáðàáîòêà ÷åòíîñòè ãîëîâû
void FQueue::ProcessEvenHead()
{
    int Value;
    std::cout << "Èçâëå÷åííûå ýëåìåíòû: ";

    while (!IsEmpty() && (Head->Data % 2 != 0))
    {
        if (Pop(Value))
        {
            std::cout << Value << " ";
        }
    }
    std::cout << std::endl;
}

// Ïîëó÷åíèå óêàçàòåëÿ íà íà÷àëî î÷åðåäè
FNode* FQueue::GetHead() const
{
    return Head;
}

// Ïîëó÷åíèå óêàçàòåëÿ íà êîíåö î÷åðåäè
FNode* FQueue::GetTail() const
{
    return Tail;
}

// Ïîëó÷åíèå çíà÷åíèÿ íà÷àëà î÷åðåäè
int FQueue::GetHeadValue() const
{
    if (IsEmpty())
    {
        throw FQueueException("Î÷åðåäü ïóñòà - íåò çíà÷åíèÿ ãîëîâû");
    }
    return Head->Data;
}

// Ïîëó÷åíèå çíà÷åíèÿ êîíöà î÷åðåäè
int FQueue::GetTailValue() const
{
    if (IsEmpty())
    {
        throw FQueueException("Î÷åðåäü ïóñòà - íåò çíà÷åíèÿ õâîñòà");
    }
    return Tail->Data;
}

// Ïðîâåðêà ïóñòîòû î÷åðåäè
bool FQueue::IsEmpty() const
{
    return Head == nullptr;
}

// Î÷èñòêà î÷åðåäè
void FQueue::Clear()
{
    int Dummy;
    while (Pop(Dummy)) {}
    std::cout << "Î÷åðåäü î÷èùåíà." << std::endl;
}

// Ïðîâåðêà, ÿâëÿåòñÿ ëè ñòðîêà ÷èñëîì
bool IsNumber(const std::string& InString)
{
    if (InString.empty())
    {
        return false;
    }

    int StartIndex = (InString[0] == '-' || InString[0] == '+') ? 1 : 0;

    // Ïðîâåðêà, ÷òî ñòðîêà íå ñîñòîèò òîëüêî èç çíàêà
    if (StartIndex >= static_cast<int>(InString.length()))
    {
        return false;
    }

    for (int i = StartIndex; i < static_cast<int>(InString.length()); ++i)
    {
        if (!isdigit(static_cast<unsigned char>(InString[i])))
        {
            return false;
        }
    }

    return true;
}

// Ïðîâåðêà êîððåêòíîñòè âõîäíûõ äàííûõ
bool ReadInteger(int& OutValue)
{
    std::cin >> OutValue;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}
