#include <iostream>
#include <string>
#include <time.h>
#include <list>
using namespace std;

class ContListSet
{
private:
    list<int> set;
public:
    // F1  Создание пустого множества
    ContListSet();

    // F2 Проверка на пустоту множества
    bool isSetEmpty();

    // F3 Проверка элемента на принадлежность множеству
    bool isSetHasElement(int element);

    // F4 Добавление нового элемента в начало множества
    //SetList* 
    void addNewElement(int element);

    // F5 Создание множества по заданным параметрам, проверяя возможность
    //  создания множества
    ContListSet(int size, int min, int max); 

    // F6 Мощность множества
    int setPowers(); 

    // F7 Вывод элементов множества
    string setView(char separator); 

    // F8 Удаление множества (очистка занимаемой множеством памяти)
    ~ContListSet();

    // F9 Подмножестов А-B
    bool isSubSet(ContListSet* setSecond);

    // F10 Равенство двух множеств А-В
    bool isSetsEquals(ContListSet* setSecond);

    // F11 Объединение двух множеств
    ContListSet* unionOfSets(ContListSet* setSecond);

    // F12 Пересечение двух множеств
    ContListSet* intersectionsOfSets(ContListSet* setSecond);

    // F13 Разность множеств
    ContListSet* differenceOfSets(ContListSet* setSecond);

    // F14 Симметричная разность
    ContListSet* symmetricDifferenceOfSets(ContListSet* setSecond);
};