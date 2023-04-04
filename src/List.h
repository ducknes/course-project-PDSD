#include <iostream>
#include <string>
#include <time.h>
using namespace std;

struct SetList {
    int element;
    SetList* next;
};

class ListSet
{
private:
    SetList* head;
public:
    // F1  Создание пустого множества
    ListSet();

    // F2 Проверка на пустоту множества
    bool isSetEmpty();

    // F3 Проверка элемента на принадлежность множеству
    bool isSetHasElement(int element);

    // F4 Добавление нового элемента в начало множества
    //SetList* 
    void addNewElement(int element);

    // F5 Создание множества по заданным параметрам, проверяя возможность
    //  создания множества
    ListSet(int size, int min, int max); 

    // F6 Мощность множества
    int setPowers(); 

    // F7 Вывод элементов множества
    string setView(char separator); 

    // F8 Удаление множества (очистка занимаемой множеством памяти)
    ~ListSet();

    // F9 Подмножестов А-B
    bool isSubSet(ListSet* setSecond);

    // F10 Равенство двух множеств А-В
    bool isSetsEquals(ListSet* setSecond);

    // F11 Объединение двух множеств
    ListSet* unionOfSets(ListSet* setSecond);

    // F12 Пересечение двух множеств
    ListSet* intersectionsOfSets(ListSet* setSecond);

    // F13 Разность множеств
    ListSet* differenceOfSets(ListSet* setSecond);

    // F14 Симметричная разность
    ListSet* symmetricDifferenceOfSets(ListSet* setSecond);
};