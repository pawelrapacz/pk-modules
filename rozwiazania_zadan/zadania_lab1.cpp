// zadania_lab1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <chrono>

import mathh;
import bank;

using namespace std::chrono_literals;

int main()
{
    //std::cout << "Hello World!\n";

    /*shape d1(4, 0, 2, 2);
    std::cout << d1.surface_area()<<std::endl;
    std::cout << d1.volume() << std::endl;

    shape d2(4, 1, 2, 2);
    std::cout << d2.surface_area() << std::endl;
    std::cout << d2.volume() << std::endl;

    shape d3(6, 1, 2, 2);
    std::cout << d3.surface_area() << std::endl;
    std::cout << d3.volume() << std::endl;*/
    bank kowalski("Jan", "Kowalski", 123456, 300, 1234);
    kowalski.transfer(200, 1234);
    std::this_thread::sleep_for(5s);
    kowalski.transfer(-200, 1234);
    std::cout << std::endl;
    kowalski.printOperations(12434);

}   

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
