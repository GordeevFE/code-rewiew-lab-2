#include "HeaderTask01.h"

// Êîíñòðóêòîð
FStack::FStack() : Top(nullptr) {}

// Äåñòðóêòîð
FStack::~FStack()
{
    ClearStack();
}

//FIX_ME: íåêîððåêòíîå èìÿ ôóíêöèè
//void push(int value) {

// äëÿ äîáàâëåíèÿ ýëåìåíòà â ñòåê
void FStack::Push(int Value)
{
    try
    {
        FNode* NewNode = new FNode(Value); // Ñîçäàåì íîâûé óçåë
        NewNode->NextData = Top;            // Íîâûé óçåë óêàçûâàåò íà òåêóùóþ âåðøèíó
        Top = NewNode;                       // Îáíîâëÿåì âåðøèíó ñòåêà

        std::cout << "Ýëåìåíò " << Value << " äîáàâëåí â ñòåê." << std::endl;
    }
    catch (const std::bad_alloc& Exception)
    {
        throw FStackException("Îøèáêà âûäåëåíèÿ ïàìÿòè ïðè äîáàâëåíèè ýëåìåíòà");
    }
}

// Ìåòîä äëÿ óäàëåíèÿ ýëåìåíòà èç ñòåêà
void FStack::Pop()
{
    if (IsEmpty())
    {
        throw FStackException("Ñòåê ïóñò! Íåâîçìîæíî óäàëèòü ýëåìåíò.");
    }

    FNode* Temp = Top;
    Top = Top->NextData;

    std::cout << "Ýëåìåíò " << Temp->Data << " óäàëåí èç ñòåêà." << std::endl;
    delete Temp;
}

// Ôóíêöèÿ äëÿ âûâîäà ñòåêà
void FStack::Print() const
{
    if (IsEmpty())
    {
        std::cout << "Ñòåê ïóñò!" << std::endl;
        return;
    }

    FNode* Current = Top;
    std::cout << "Ýëåìåíòû ñòåêà: ";

    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->NextData;
    }
    std::cout << std::endl;
}

// Ïîëó÷åíèå ãîëîâû ñòåêà
FNode* FStack::GetTop() const
{
    return Top;
}

// Î÷èñòêà ñòåêà
void FStack::ClearStack()
{
    while (Top != nullptr)
    {
        FNode* Temp = Top;
        Top = Top->NextData;
        delete Temp;
    }
    std::cout << "Ñòåê î÷èùåí." << std::endl;
}

// Ïðîâåðêà ïóñòîòû ñòåêà
bool FStack::IsEmpty() const
{
    return Top == nullptr;
}

// Äîáàâëåíèå ýëåìåíòà è âûâîä àäðåñà
void AddElementAndPrintAddress(FStack& Stack, int Value)
{
    try
    {
        Stack.Push(Value);
        std::cout << "Àäðåñ íîâîé âåðøèíû ñòåêà: " << Stack.GetTop() << std::endl;
    }
    catch (const FStackException& Exception)
    {
        throw; // Ïðîáðàñûâàåì èñêëþ÷åíèå äàëüøå
    }
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
