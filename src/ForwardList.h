#include <iostream>
#include <string>
#include <time.h>
#include <forward_list>
using namespace std;

class ForwardListSet
{
private:
    forward_list<int> set;
public:
    // F1  Создание пустого множества
    ForwardListSet();

    // F2 Проверка на пустоту множества
    bool isSetEmpty();

    // F3 Проверка элемента на принадлежность множеству
    bool isSetHasElement(int element);

    // F4 Добавление нового элемента в начало множества
    //SetList* 
    void addNewElement(int element);

    // F5 Создание множества по заданным параметрам, проверяя возможность
    //  создания множества
    ForwardListSet(int size, int min, int max); 

    // F6 Мощность множества
    int setPowers(); 

    // F7 Вывод элементов множества
    string setView(char separator); 

    // F8 Удаление множества (очистка занимаемой множеством памяти)
    ~ForwardListSet();

    // F9 Подмножестов А-B
    bool isSubSet(ForwardListSet* setSecond);

    // F10 Равенство двух множеств А-В
    bool isSetsEquals(ForwardListSet* setSecond);

    // F11 Объединение двух множеств
    ForwardListSet* unionOfSets(ForwardListSet* setSecond);

    // F12 Пересечение двух множеств
    ForwardListSet* intersectionsOfSets(ForwardListSet* setSecond);

    // F13 Разность множеств
    ForwardListSet* differenceOfSets(ForwardListSet* setSecond);

    // F14 Симметричная разность
    ForwardListSet* symmetricDifferenceOfSets(ForwardListSet* setSecond);
};