#include "Node.h"
#include "List.h"
#include "ContList.h"
#include "Set.h"
#include "ForwardList.h"
#include "UnorderedMap.h"
#include "TableConsoleUI.h"
#include "time.h"
#include <iomanip>

void tableView() {
    int N = 1000;
    cout << "Введите размер массива(>=1000): ";
    cin >> N;
    cout << endl;

    // cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    // //cout << "\t\t\t| Односвязный список | Класс 'Список' \t|\tList\t|\tSet\t|forward_list\t|unordered_map" << endl;
    // cout << "\t\t\t" <<  setw( 30 ) << "| Односвязный список |" << setw( 30 ) << "Класс 'Список' |" << setw( 15 ) << "List |" << setw( 15 ) << "Set |" << setw( 15 ) << "Forward_List |" << setw( 15 ) << "Unordered_Map" << endl;
    // cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    // clock_t start = clock();
    // Node* nodeSet = createNewSet(N, 0, 10 * N);
    // clock_t end = clock();
    // double createNodeSet = (double)(end - start) / CLOCKS_PER_SEC;

    // start = clock();
    // ListSet* listSet = new ListSet(N, 0, 10 * N);
    // end = clock();
    // double createListSet = (double)(end - start) / CLOCKS_PER_SEC;

    // start = clock();
    // ContListSet* contListSet = new ContListSet(N, 0, 10 * N);
    // end = clock();
    // double createContListSet = (double)(end - start) / CLOCKS_PER_SEC;

    // start = clock();
    // SetClass* Set = new SetClass(N, 0, 10 * N);
    // end = clock();
    // double createSetClassSet = (double)(end - start) / CLOCKS_PER_SEC;

    // start = clock();
    // ForwardListSet* forwardListSet = new ForwardListSet(N, 0, 10 * N);
    // end = clock();
    // double createForwardListSet = (double)(end - start) / CLOCKS_PER_SEC;

    // start = clock();
    // UnorderedMapSet* unorderedMapSet = new UnorderedMapSet(N, 0, 10 * N);
    // end = clock();
    // double createUnorderedMapSet = (double)(end - start) / CLOCKS_PER_SEC;

    // cout << "Создание множества\t|" << setw( 10 ) << createNodeSet << "                |" << setw( 15 ) << createListSet << "|" << setw( 15 ) << createContListSet << "|" << setw( 15 ) << createSetClassSet << "|" << setw( 15 ) << createForwardListSet << "|" << setw( 15 ) << createUnorderedMapSet << endl;
    // cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    
}