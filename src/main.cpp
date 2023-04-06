#include "TableConsoleUI.h"
#include "Node.h"
#include "List.h"
#include "ContList.h"
#include "Set.h"
#include "ForwardList.h"
#include "UnorderedMap.h"
#include "TableConsoleUI.h"
#include "time.h"
#include <iomanip>

void space()
{
    for (int i = 0; i < 128; i++)
    {
        cout << ".";
    }
    cout<< endl;
}

int main(int argc, char **argv){
    setlocale(LC_ALL, "Ru");
	
	cout << "Введите мощность: ";
    int N;
    cin >> N;


    //диапазон от 0 до 10*n
    //+регулярка для n
    //массив из элементов для множеств должны быть одинаковыми для сравнений в равных условиях 

    // СОЗДАНИЕ МНОЖЕСТВА

    //Односвязный список
    auto startSetCreate = chrono::steady_clock::now();
    Node* A = createNewSet(N, 0, N * 10);
    auto endSetCreate = chrono::steady_clock::now();
    double timeSetCreate = chrono::duration_cast<chrono::milliseconds>(endSetCreate - startSetCreate).count();

    //Класс Список
    auto startSetListCreate = chrono::steady_clock::now();
    ListSet* A2 = new ListSet(N, 0, N * 10);
    auto endSetListCreate = chrono::steady_clock::now();
    double timeSetListCreate = chrono::duration_cast<chrono::milliseconds>(endSetListCreate - startSetListCreate).count();

    //Контейнерный класс List
    auto startSetByListCreate = chrono::steady_clock::now();
    ContListSet* A3 = new ContListSet(N, 0, N * 10);
    auto endSetByListCreate = chrono::steady_clock::now();
    double timeSetByListCreate = chrono::duration_cast<chrono::milliseconds>(endSetByListCreate - startSetByListCreate).count();

    //Контейнерный класс Set
    auto startSetBySetCreate = chrono::steady_clock::now();
    SetClass* A4 = new SetClass(N, 0, N * 10);
    auto endSetBySetCreate = chrono::steady_clock::now();
    double timeSetBySetCreate = chrono::duration_cast<chrono::milliseconds>(endSetBySetCreate - startSetBySetCreate).count();

    //Контейнерный класс forward_list
    auto startForwardListSetCreate = chrono::steady_clock::now();
    ForwardListSet* A5 = new ForwardListSet(N, 0, N * 10);
    auto endForwardListSetCreate = chrono::steady_clock::now();
    double timeForwardListSetCreate = chrono::duration_cast<chrono::milliseconds>(endForwardListSetCreate - startForwardListSetCreate).count();

    //Контейнерный класс Unordered_map
    auto startUnorderedMapSetCreate = chrono::steady_clock::now();
    UnorderedMapSet* A6 = new UnorderedMapSet(N, 0, N * 10);
    auto endUnorderedMapSetCreate = chrono::steady_clock::now();
    double timeUnorderedMapSetCreate = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetCreate - startUnorderedMapSetCreate).count();

    cout << endl << endl;
    space();
        cout << "                     | Односвязный список |  Класс 'Список'  |     List     |      Set      | forward_list  |unordered_map" << endl;
    space();
    cout << "Создание множества   |" << setw(11) << timeSetCreate << setw(10) << "|" << setw(10) << timeSetListCreate << setw(9) << "|" << setw(8) << timeSetByListCreate << setw(7) << "|" << setw(8) << timeSetBySetCreate << setw(8) << "|" << setw(9) << timeForwardListSetCreate << setw(7) << "|" << setw(10) << timeUnorderedMapSetCreate << setw(9) << "" << endl;



    // МОЩНОСТЬ
    auto startSetPower = chrono::steady_clock::now();
    int powerA = setPowers(A);
    auto endSetPower = chrono::steady_clock::now();
    double timeSetPower = chrono::duration_cast<chrono::milliseconds>(endSetPower - startSetPower).count();

    auto startSetListPower = chrono::steady_clock::now();
    A2->setPowers();
    auto endSetListPower = chrono::steady_clock::now();
    double timeSetListPower = chrono::duration_cast<chrono::milliseconds>(endSetListPower - startSetListPower).count();

    auto startSetByListPower = chrono::steady_clock::now();
    A3->setPowers();
    auto endSetByListPower = chrono::steady_clock::now();
    double timeSetByListPower = chrono::duration_cast<chrono::milliseconds>(endSetByListPower - startSetByListPower).count();

    auto startSetBySetPower = chrono::steady_clock::now();
    A4->setPowers();
    auto endSetBySetPower = chrono::steady_clock::now();
    double timeSetBySetPower = chrono::duration_cast<chrono::milliseconds>(endSetBySetPower - startSetBySetPower).count();

    auto startForwardListSetPower = chrono::steady_clock::now();
    A5->setPowers();
    auto endForwardListSetPower = chrono::steady_clock::now();
    double timeForwardListSettPower = chrono::duration_cast<chrono::milliseconds>(endForwardListSetPower - startForwardListSetPower).count();

    auto startUnorderedMapSetPower = chrono::steady_clock::now();
    A6->setPowers();
    auto endUnorderedMapSetPower = chrono::steady_clock::now();
    double timeUnorderedMapSetPower = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetPower - startUnorderedMapSetPower).count();

    space();
    cout << "Мощность             |" << setw(11) << timeSetPower << setw(10) << "|" << setw(10) << timeSetListPower << setw(9) << "|" << setw(8) << timeSetByListPower << setw(7) << "|" << setw(8) << timeSetBySetPower << setw(8) << "|" << setw(9) << timeForwardListSettPower << setw(7) << "|" << setw(10) << timeUnorderedMapSetPower << setw(9) << "" << endl;



    // ПОДМНОЖЕСТВА А-А

    auto startSetSubsetAA = chrono::steady_clock::now();
    isSubSet(A, A);
    auto endSetSubsetAA = chrono::steady_clock::now();
    double timeSetSubsetAA = chrono::duration_cast<chrono::milliseconds>(endSetSubsetAA - startSetSubsetAA).count();

    auto startSetListSubsetAA = chrono::steady_clock::now();
    A2->isSubSet(A2);
    auto endSetListSubsetAA = chrono::steady_clock::now();
    double timeSetListSubsetAA = chrono::duration_cast<chrono::milliseconds>(endSetListSubsetAA - startSetListSubsetAA).count();

    auto startSetByListSubsetAA = chrono::steady_clock::now();
    A3->isSubSet(A3);
    auto endSetByListSubsetAA = chrono::steady_clock::now();
    double timeSetByListSubsetAA = chrono::duration_cast<chrono::milliseconds>(endSetByListSubsetAA - startSetByListSubsetAA).count();

    auto startSetBySetSubsetAA = chrono::steady_clock::now();
    A4->isSubSet(A4);
    auto endSetBySetSubsetAA = chrono::steady_clock::now();
    double timeSetBySetSubsetAA = chrono::duration_cast<chrono::milliseconds>(endSetBySetSubsetAA - startSetBySetSubsetAA).count();

    auto startForwardListSetSubsetAA = chrono::steady_clock::now();
    A5->isSubSet(A5);
    auto endForwardListSetSubsetAA = chrono::steady_clock::now();
    double timeForwardListSetSubsetAA = chrono::duration_cast<chrono::milliseconds>(endForwardListSetSubsetAA - startForwardListSetSubsetAA).count();

    auto startUnorderedMapSetSubsetAA = chrono::steady_clock::now();
    A6->isSubSet(A6);
    auto endUnorderedMapSetSubsetAA = chrono::steady_clock::now();
    double timeUnorderedMapSetSubsetAA = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetSubsetAA - startUnorderedMapSetSubsetAA).count();

    space();
    cout << "Подмножество А-А     |" << setw(11) << timeSetSubsetAA << setw(10) << "|" << setw(10) << timeSetListSubsetAA << setw(9) << "|" << setw(8) << timeSetByListSubsetAA << setw(7) << "|" << setw(8) << timeSetBySetSubsetAA << setw(8) << "|" << setw(9) << timeForwardListSetSubsetAA << setw(7) << "|" << setw(10) << timeUnorderedMapSetSubsetAA << setw(9) << "" << endl;



    // ПОДМНОЖЕСТВО B-A
    Node* B = createNewSet(N, 0, N * 10);
    auto startSetSubsetAB = chrono::steady_clock::now();
    isSubSet(A, B);
    auto endSetSubsetAB = chrono::steady_clock::now();
    double timeSetSubsetAB = chrono::duration_cast<chrono::milliseconds>(endSetSubsetAB - startSetSubsetAB).count();

    ListSet* B2 = new ListSet(N, 0, N * 10);
    auto startSetListSubsetAB = chrono::steady_clock::now();
    A2->isSubSet(B2);
    auto endSetListSubsetAB = chrono::steady_clock::now();
    double timeSetListSubsetAB = chrono::duration_cast<chrono::milliseconds>(endSetListSubsetAB - startSetListSubsetAB).count();

    ContListSet* B3 = new ContListSet(N, 0, N * 10);
    auto startSetByListSubsetAB = chrono::steady_clock::now();
    A3->isSubSet(B3);
    auto endSetByListSubsetAB = chrono::steady_clock::now();
    double timeSetByListSubsetAB = chrono::duration_cast<chrono::milliseconds>(endSetByListSubsetAB - startSetByListSubsetAB).count();

    SetClass* B4 = new SetClass(N, 0, N * 10);
    auto startSetBySetSubsetAB = chrono::steady_clock::now();
    A4->isSubSet(B4);
    auto endSetBySetSubsetAB = chrono::steady_clock::now();
    double timeSetBySetSubsetAB = chrono::duration_cast<chrono::milliseconds>(endSetBySetSubsetAB - startSetBySetSubsetAB).count();

    ForwardListSet* B5 = new ForwardListSet(N, 0, N * 10);
    auto startForwardListSetSubsetAB = chrono::steady_clock::now();
    A5->isSubSet(B5);
    auto endForwardListSetSubsetAB = chrono::steady_clock::now();
    double timeForwardListSetSubsetAB = chrono::duration_cast<chrono::milliseconds>(endForwardListSetSubsetAB - startForwardListSetSubsetAB).count();

    UnorderedMapSet* B6 = new UnorderedMapSet(N, 0, N * 10);
    auto startUnorderedMapSetSubsetAB = chrono::steady_clock::now();
    A6->isSubSet(B6);
    auto endUnorderedMapSetSubsetAB = chrono::steady_clock::now();
    double timeUnorderedMapSetSubsetAB = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetSubsetAB - startUnorderedMapSetSubsetAB).count();

    space();
    cout << "Подмножество А-B     |" << setw(11) << timeSetSubsetAB << setw(10) << "|" << setw(10) << timeSetListSubsetAB << setw(9) << "|" << setw(8) << timeSetByListSubsetAB << setw(7) << "|" << setw(8) << timeSetBySetSubsetAB << setw(8) << "|" << setw(9) << timeForwardListSetSubsetAB << setw(7) << "|" << setw(10) << timeUnorderedMapSetSubsetAB << setw(9) << "" << endl;



    // РАВЕНСТВО А-А
    auto startSetEqualsAA = chrono::steady_clock::now();
    isSetsEquals(A, A);
    auto endSetEqualsAA = chrono::steady_clock::now();
    double timeSetEqualsAA = chrono::duration_cast<chrono::milliseconds>(endSetEqualsAA - startSetEqualsAA).count();

    auto startSetListEqualsAA = chrono::steady_clock::now();
    A2->isSetsEquals(A2);
    auto endSetListEqualsAA = chrono::steady_clock::now();
    double timeSetListEqualsAA = chrono::duration_cast<chrono::milliseconds>(endSetListEqualsAA - startSetListEqualsAA).count();

    auto startSetByListEqualsAA = chrono::steady_clock::now();
    A3->isSetsEquals(A3);
    auto endSetByListEqualsAA = chrono::steady_clock::now();
    double timeSetByListEqualsAA = chrono::duration_cast<chrono::milliseconds>(endSetByListEqualsAA - startSetByListEqualsAA).count();

    auto startSetBySetEqualsAA = chrono::steady_clock::now();
    A4->isSetsEquals(A4);
    auto endSetBySetEqualsAA = chrono::steady_clock::now();
    double timeSetBySetEqualsAA = chrono::duration_cast<chrono::milliseconds>(endSetBySetEqualsAA - startSetBySetEqualsAA).count();

    auto startForwardListSetEqualsAA = chrono::steady_clock::now();
    A5->isSetsEquals(A5);
    auto endForwardListSetEqualsAA = chrono::steady_clock::now();
    double timeForwardListSetEqualsAA = chrono::duration_cast<chrono::milliseconds>(endForwardListSetEqualsAA - startForwardListSetEqualsAA).count();

    auto startUnorderedMapSetEqualsAA = chrono::steady_clock::now();
    A6->isSetsEquals(A6);
    auto endUnorderedMapSetEqualsAA = chrono::steady_clock::now();
    double timeUnorderedMapSetEqualsAA = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetEqualsAA - startUnorderedMapSetEqualsAA).count();

    space();
    cout << "Равенство А-А        |" << setw(11) << timeSetEqualsAA << setw(10) << "|" << setw(10) << timeSetListEqualsAA << setw(9) << "|" << setw(8) << timeSetByListEqualsAA << setw(7) << "|" << setw(8) << timeSetBySetEqualsAA << setw(8) << "|" << setw(9) << timeForwardListSetEqualsAA << setw(7) << "|" << setw(10) << timeUnorderedMapSetEqualsAA << setw(9) << "" << endl;
    space();



    // РАВЕНСТВО A-B
    auto startSetEqualsAB = chrono::steady_clock::now();
    isSetsEquals(A, B);
    auto endSetEqualsAB = chrono::steady_clock::now();
    double timeSetEqualsAB = chrono::duration_cast<chrono::milliseconds>(endSetEqualsAB - startSetEqualsAB).count();

    auto startSetListEqualsAB = chrono::steady_clock::now();
    A2->isSetsEquals(B2);
    auto endSetListEqualsAB = chrono::steady_clock::now();
    double timeSetListEqualsAB = chrono::duration_cast<chrono::milliseconds>(endSetListEqualsAB - startSetListEqualsAB).count();

    auto startSetByListEqualsAB = chrono::steady_clock::now();
    A3->isSetsEquals(B3);
    auto endSetByListEqualsAB = chrono::steady_clock::now();
    double timeSetByListEqualsAB = chrono::duration_cast<chrono::milliseconds>(endSetByListEqualsAB - startSetByListEqualsAB).count();

    auto startSetBySetEqualsAB = chrono::steady_clock::now();
    A4->isSetsEquals(B4);
    auto endSetBySetEqualsAB = chrono::steady_clock::now();
    double timeSetBySetEqualsAB = chrono::duration_cast<chrono::milliseconds>(endSetBySetEqualsAB - startSetBySetEqualsAB).count();

    auto startForwardListSetEqualsAB = chrono::steady_clock::now();
    A5->isSetsEquals(B5);
    auto endForwardListSetEqualsAB = chrono::steady_clock::now();
    double timeForwardListSetEqualsAB = chrono::duration_cast<chrono::milliseconds>(endForwardListSetEqualsAB - startForwardListSetEqualsAB).count();

    auto startUnorderedMapSetEqualsAB = chrono::steady_clock::now();
    A6->isSetsEquals(B6);
    auto endUnorderedMapSetEqualsAB = chrono::steady_clock::now();
    double timeUnorderedMapSetEqualsAB = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetEqualsAB - startUnorderedMapSetEqualsAB).count();

    cout << "Равенство В-А        |" << setw(11) << timeSetEqualsAB << setw(10) << "|" << setw(10) << timeSetListEqualsAB << setw(9) << "|" << setw(8) << timeSetByListEqualsAB << setw(7) << "|" << setw(8) << timeSetBySetEqualsAB << setw(8) << "|" << setw(9) << timeForwardListSetEqualsAB << setw(7) << "|" << setw(10) << timeUnorderedMapSetEqualsAB << setw(9) << "" << endl;
    space();

    // Объединение 
    auto startSetUnification = chrono::steady_clock::now();
    Node* C = unionOfSets(A, B);
    auto endSetUnification = chrono::steady_clock::now();
    double timeSetUnification = chrono::duration_cast<chrono::milliseconds>(endSetUnification - startSetUnification).count();

    auto startSetListUnification = chrono::steady_clock::now();
    ListSet* C2 = A2->unionOfSets(B2);
    auto endSetListUnification = chrono::steady_clock::now();
    double timeSetListUnification = chrono::duration_cast<chrono::milliseconds>(endSetListUnification - startSetListUnification).count();

    auto startSetByListUnification = chrono::steady_clock::now();
    ContListSet* C3 = A3->unionOfSets(B3);
    auto endSetByListUnification = chrono::steady_clock::now();
    double timeSetByListUnification = chrono::duration_cast<chrono::milliseconds>(endSetByListUnification - startSetByListUnification).count();

    auto startSetBySetUnification = chrono::steady_clock::now();
    SetClass* C4 = A4->unionOfSets(B4);
    auto endSetBySetUnification = chrono::steady_clock::now();
    double timeSetBySetUnification = chrono::duration_cast<chrono::milliseconds>(endSetBySetUnification - startSetBySetUnification).count();

    auto startForwardListSetUnification = chrono::steady_clock::now();
    ForwardListSet* C5 = A5->unionOfSets(B5);
    auto endForwardListSetUnification = chrono::steady_clock::now();
    double timeForwardListSetUnification = chrono::duration_cast<chrono::milliseconds>(endForwardListSetUnification - startForwardListSetUnification).count();

    auto startUnorderedMapSetUnification = chrono::steady_clock::now();
    UnorderedMapSet* C6 = A6->unionOfSets(B6);
    auto endUnorderedMapSetUnification = chrono::steady_clock::now();
    double timUnorderedMapSetUnification = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetUnification - startUnorderedMapSetUnification).count();

    cout << "Объединение          |" << setw(11) << timeSetUnification << setw(10) << "|" << setw(10) << timeSetListUnification << setw(9) << "|" << setw(8) << timeSetByListUnification << setw(7) << "|" << setw(8) << timeSetBySetUnification << setw(8) << "|" << setw(9) << timeForwardListSetUnification << setw(7) << "|" << setw(10) << timUnorderedMapSetUnification << setw(9) << "" << endl;
    space();



    // ПЕРЕСЕЧЕНИЕ
    auto startSetIntersection = chrono::steady_clock::now();
    Node* D = intersectionsOfSets(A, B);
    auto endSetIntersection = chrono::steady_clock::now();
    double timeSetIntersection = chrono::duration_cast<chrono::milliseconds>(endSetIntersection - startSetIntersection).count();

    auto startSetListIntersection = chrono::steady_clock::now();
    ListSet* D2 = A2->intersectionsOfSets(B2);
    auto endSetListIntersection = chrono::steady_clock::now();
    double timeSetListIntersection = chrono::duration_cast<chrono::milliseconds>(endSetListIntersection - startSetListIntersection).count();

    auto startSetByListIntersection = chrono::steady_clock::now();
    ContListSet* D3 = A3->intersectionsOfSets(B3);
    auto endSetByListIntersection = chrono::steady_clock::now();
    double timeSetByListIntersection = chrono::duration_cast<chrono::milliseconds>(endSetByListIntersection - startSetByListIntersection).count();

    auto startSetBySetIntersection = chrono::steady_clock::now();
    SetClass* D4 = A4->intersectionsOfSets(B4);
    auto endSetBySetIntersection = chrono::steady_clock::now();
    double timeSetBySetIntersection = chrono::duration_cast<chrono::milliseconds>(endSetBySetIntersection - startSetBySetIntersection).count();

    auto startForwardListSetIntersection = chrono::steady_clock::now();
    ForwardListSet* D5 = A5->intersectionsOfSets(B5);
    auto endForwardListSetIntersection = chrono::steady_clock::now();
    double timeForwardListSetIntersection = chrono::duration_cast<chrono::milliseconds>(endForwardListSetIntersection - startForwardListSetIntersection).count();

    auto startUnorderedMapSetIntersection = chrono::steady_clock::now();
    UnorderedMapSet* D6 = A6->intersectionsOfSets(B6);
    auto endUnorderedMapSetIntersection = chrono::steady_clock::now();
    double timeUnorderedMapSetIntersection = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetIntersection - startUnorderedMapSetIntersection).count();

    cout << "Пересечение          |" << setw(11) << timeSetIntersection << setw(10) << "|" << setw(10) << timeSetListIntersection << setw(9) << "|" << setw(8) << timeSetByListIntersection << setw(7) << "|" << setw(8) << timeSetBySetIntersection << setw(8) << "|" << setw(9) << timeForwardListSetIntersection << setw(7) << "|" << setw(10) << timeUnorderedMapSetIntersection << setw(9) << "" << endl;
    space();




    // РАЗНОСТЬ А-В
    auto startSetDifferenceAB = chrono::steady_clock::now();
    Node* E = differenceOfSets(A, B);
    auto endSetDifferenceAB = chrono::steady_clock::now();
    double timeSetDifferenceAB = chrono::duration_cast<chrono::milliseconds>(endSetDifferenceAB - startSetDifferenceAB).count();

    auto startSetListDifferenceAB = chrono::steady_clock::now();
    ListSet* E2 = A2->differenceOfSets(B2);
    auto endSetListDifferenceAB = chrono::steady_clock::now();
    double timeSetListDifferenceAB = chrono::duration_cast<chrono::milliseconds>(endSetListDifferenceAB - startSetListDifferenceAB).count();

    auto startSetByListDifferenceAB = chrono::steady_clock::now();
    ContListSet* E3 = A3->differenceOfSets(B3);
    auto endSetByListDifferenceAB = chrono::steady_clock::now();
    double timeSetByListDifferenceAB = chrono::duration_cast<chrono::milliseconds>(endSetByListDifferenceAB - startSetByListDifferenceAB).count();

    auto startSetBySetDifferenceAB = chrono::steady_clock::now();
    SetClass* E4 = A4->differenceOfSets(B4);
    auto endSetBySetDifferenceAB = chrono::steady_clock::now();
    double timeSetBySetDifferenceAB = chrono::duration_cast<chrono::milliseconds>(endSetBySetDifferenceAB - startSetBySetDifferenceAB).count();

    auto startForwardListSetDifferenceAB = chrono::steady_clock::now();
    ForwardListSet* E5 = A5->differenceOfSets(B5);
    auto endForwardListSetDifferenceAB = chrono::steady_clock::now();
    double timeForwardListSetDifferenceAB = chrono::duration_cast<chrono::milliseconds>(endForwardListSetDifferenceAB - startForwardListSetDifferenceAB).count();

    auto startUnorderedMapSetDifferenceAB = chrono::steady_clock::now();
    UnorderedMapSet* E6 = A6->differenceOfSets(B6);
    auto endUnorderedMapSetDifferenceAB = chrono::steady_clock::now();
    double timeUnorderedMapSetDifferenceAB = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetDifferenceAB - startUnorderedMapSetDifferenceAB).count();

    cout << "Разность A-B         |" << setw(11) << timeSetDifferenceAB << setw(10) << "|" << setw(10) << timeSetListDifferenceAB << setw(9) << "|" << setw(8) << timeSetByListDifferenceAB << setw(7) << "|" << setw(8) << timeSetBySetDifferenceAB << setw(8) << "|" << setw(9) << timeForwardListSetDifferenceAB << setw(7) << "|" << setw(10) << timeUnorderedMapSetDifferenceAB << setw(9) << "" << endl;
    space();



    // РАЗНОСТЬ В-А
    auto startSetDifferenceBA = chrono::steady_clock::now();
    Node* J = differenceOfSets(B, A);
    auto endSetDifferenceBA = chrono::steady_clock::now();
    double timeSetDifferenceBA = chrono::duration_cast<chrono::milliseconds>(endSetDifferenceBA - startSetDifferenceBA).count();

    auto startSetListDifferenceBA = chrono::steady_clock::now();
    ListSet* J2 = B2->differenceOfSets(A2);
    auto endSetListDifferenceBA = chrono::steady_clock::now();
    double timeSetListDifferenceBA = chrono::duration_cast<chrono::milliseconds>(endSetListDifferenceBA - startSetListDifferenceBA).count();

    auto startSetByListDifferenceBA = chrono::steady_clock::now();
    ContListSet* J3 = B3->differenceOfSets(A3);
    auto endSetByListDifferenceBA = chrono::steady_clock::now();
    double timeSetByListDifferenceBA = chrono::duration_cast<chrono::milliseconds>(endSetByListDifferenceBA - startSetByListDifferenceBA).count();

    auto startSetBySetDifferenceBA = chrono::steady_clock::now();
    SetClass* J4 = B4->differenceOfSets(A4);
    auto endSetBySetDifferenceBA = chrono::steady_clock::now();
    double timeSetBySetDifferenceBA = chrono::duration_cast<chrono::milliseconds>(endSetBySetDifferenceBA - startSetBySetDifferenceBA).count();

    auto startForwardListSetDifferenceBA = chrono::steady_clock::now();
    ForwardListSet* J5 = B5->differenceOfSets(A5);
    auto endForwardListSetDifferenceBA = chrono::steady_clock::now();
    double timeForwardListSetDifferenceBA = chrono::duration_cast<chrono::milliseconds>(endForwardListSetDifferenceBA - startForwardListSetDifferenceBA).count();

    auto startUnorderedMapSetDifferenceBA = chrono::steady_clock::now();
    UnorderedMapSet* J6 = B6->differenceOfSets(A6);
    auto endUnorderedMapSetDifferenceBA = chrono::steady_clock::now();
    double timeUnorderedMapSetDifferenceBA = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetDifferenceBA - startUnorderedMapSetDifferenceBA).count();

    cout << "Разность B-A         |" << setw(11) << timeSetDifferenceBA << setw(10) << "|" << setw(10) << timeSetListDifferenceBA << setw(9) << "|" << setw(8) << timeSetByListDifferenceBA << setw(7) << "|" << setw(8) << timeSetBySetDifferenceBA << setw(8) << "|" << setw(9) << timeForwardListSetDifferenceBA << setw(7) << "|" << setw(10) << timeUnorderedMapSetDifferenceBA << setw(9) << "" << endl;
    space();

    // СИММЕТРИЧНАЯ РАЗНОСТЬ
    auto startSetSymmetricDifference = chrono::steady_clock::now();
    Node* G = symmetricDifferenceOfSets(A, B);
    auto endSetSymmetricDifference = chrono::steady_clock::now();
    double timeSetSymmetricDifference = chrono::duration_cast<chrono::milliseconds>(endSetSymmetricDifference - startSetSymmetricDifference).count();

    auto startSetListSymmetricDifference = chrono::steady_clock::now();
    ListSet* G2 = A2->symmetricDifferenceOfSets(B2);
    auto endSetListSymmetricDifference = chrono::steady_clock::now();
    double timeSetListSymmetricDifference = chrono::duration_cast<chrono::milliseconds>(endSetListSymmetricDifference - startSetListSymmetricDifference).count();

    auto startSetByListSymmetricDifference = chrono::steady_clock::now();
    ContListSet* G3 = A3->symmetricDifferenceOfSets(B3);
    auto endSetByListSymmetricDifference = chrono::steady_clock::now();
    double timeSetByListSymmetricDifference = chrono::duration_cast<chrono::milliseconds>(endSetByListSymmetricDifference - startSetByListSymmetricDifference).count();

    auto startSetBySetSymmetricDifference = chrono::steady_clock::now();
    SetClass* G4 = A4->symmetricDifferenceOfSets(B4);
    auto endSetBySetSymmetricDifference = chrono::steady_clock::now();
    double timeSetBySetSymmetricDifference = chrono::duration_cast<chrono::milliseconds>(endSetBySetSymmetricDifference - startSetBySetSymmetricDifference).count();

    auto startForwardListSetSymmetricDifference = chrono::steady_clock::now();
    ForwardListSet* G5 = A5->symmetricDifferenceOfSets(B5);
    auto endForwardListSetSymmetricDifference = chrono::steady_clock::now();
    double timeForwardListSetSymmetricDifference = chrono::duration_cast<chrono::milliseconds>(endForwardListSetSymmetricDifference - startForwardListSetSymmetricDifference).count();

    auto startUnorderedMapSetSymmetricDifference = chrono::steady_clock::now();
    UnorderedMapSet* G6 = A6->symmetricDifferenceOfSets(B6);
    auto endUnorderedMapSetSymmetricDifference = chrono::steady_clock::now();
    double timeUnorderedMapSetSymmetricDifference = chrono::duration_cast<chrono::milliseconds>(endUnorderedMapSetSymmetricDifference - startUnorderedMapSetSymmetricDifference).count();

    cout << "Симметричная разность|" << setw(11) << timeSetSymmetricDifference << setw(10) << "|" << setw(10) << timeSetListSymmetricDifference << setw(9) << "|" << setw(8) << timeSetByListSymmetricDifference << setw(7) << "|" << setw(8) << timeSetBySetSymmetricDifference << setw(8) << "|" << setw(9) << timeForwardListSetSymmetricDifference << setw(7) << "|" << setw(10) << timeUnorderedMapSetSymmetricDifference << setw(9) << "" << endl;
    return 0;
}