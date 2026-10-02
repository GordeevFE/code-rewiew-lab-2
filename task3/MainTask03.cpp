#include "HeaderTask03.h"
#include <locale>

//FIX_ME: çàïðåùàåòñÿ èñïîëüçîâàíèå 
//using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    try
    {
        FLinkedList List; // Ñîçäàåì ñïèñîê

        // ×òåíèå äàííûõ èç ôàéëà
        ReadFromFile(List, "InputFile.txt");

        // Âûâîä óïîðÿäî÷åííîãî ñïèñêà
        std::cout << "Óïîðÿäî÷åííûé ñïèñîê: ";
        List.Print();
    }
    catch (const std::exception& Exception)
    {
        std::cerr << "Îøèáêà: " << Exception.what() << std::endl;
        return 1;
    }

    return 0;
}
