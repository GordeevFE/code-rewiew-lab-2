#include "HeaderTask03.h"

// Êîíñòðóêòîð
FLinkedList::FLinkedList() : Head(nullptr) {}

// Äåñòðóêòîð
FLinkedList::~FLinkedList()
{
    Clear();
}

//FIX_ME: íåêîððåêòíîå èìÿ ôóíêöèè
// Ìåòîä äëÿ âñòàâêè ýëåìåíòà ñ ñîõðàíåíèåì óïîðÿäî÷åííîñòè ïî óáûâàíèþ
void FLinkedList::InsertSorted(int Value)
{
    // Ñîçäàåì íîâûé óçåë
    FNode* NewNode = new FNode(Value);

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    // Åñëè ñïèñîê ïóñò èëè íîâûé ýëåìåíò äîëæåí áûòü ïåðâûì (áîëüøå òåêóùåé ãîëîâû)
    if (Head == nullptr || Head->Data < Value)
    {
        NewNode->Next = Head;
        Head = NewNode;
    }
    else
    {
        // Èùåì ïîçèöèþ äëÿ âñòàâêè (ñïèñîê óïîðÿäî÷åí ïî óáûâàíèþ)
        FNode* Current = Head;

        //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
        while (Current->Next != nullptr && Current->Next->Data > Value)
        {
            Current = Current->Next;
        }

        // Âñòàâëÿåì íîâûé óçåë
        NewNode->Next = Current->Next;
        Current->Next = NewNode;
    }
}

// Ìåòîä äëÿ âûâîäà ñïèñêà
void FLinkedList::Print() const
{
    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (Head == nullptr)
    {
        std::cout << "Ñïèñîê ïóñò!" << std::endl;
        return;
    }

    FNode* Current = Head;

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }

    std::cout << std::endl;
}

// Ìåòîä äëÿ ÷òåíèÿ äàííûõ èç ôàéëà
void FLinkedList::ReadFromFile(const std::string& Filename)
{
    std::ifstream File(Filename); // Îòêðûâàåì ôàéë äëÿ ÷òåíèÿ

    //FIX_ME: îòñóòñòâèå ïðîâåðêè íàëè÷èÿ ôàéëà
    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    if (!File.is_open())
    {
        std::cerr << "Îøèáêà îòêðûòèÿ ôàéëà!" << std::endl;
        return;
    }

    int N;
    File >> N; // ×èòàåì êîëè÷åñòâî ýëåìåíòîâ

    int Value;

    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    for (int i = 0; i < N; ++i)
    {
        File >> Value;
        InsertSorted(Value); // Âñòàâëÿåì ýëåìåíò ñ ñîõðàíåíèåì óïîðÿäî÷åííîñòè
    }

    File.close(); // Çàêðûâàåì ôàéë
}

// Ìåòîä äëÿ î÷èñòêè ñïèñêà
void FLinkedList::Clear()
{
    //FIX_ME: íåêîððåêòíîå ðàñïîëîæåíèå ñêîáîê
    while (Head != nullptr)
    {
        FNode* Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

// Äðóæåñòâåííàÿ ôóíêöèÿ äëÿ ÷òåíèÿ èç ôàéëà
void ReadFromFile(FLinkedList& List, const std::string& Filename)
{
    List.ReadFromFile(Filename);
}
