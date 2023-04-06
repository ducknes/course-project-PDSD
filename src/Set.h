#include <iostream>
#include <string>
#include <time.h>
#include <set>
using namespace std;

class SetClass
{
private:
    set<int> set;
public:
    // F1  Создание пустого множества
    SetClass();

    // F2 Проверка на пустоту множества
    bool isSetEmpty();

    // F3 Проверка элемента на принадлежность множеству
    bool isSetHasElement(int element);

    // F4 Добавление нового элемента в начало множества
    //SetList* 
    bool addNewElement(int element);

    // F5 Создание множества по заданным параметрам, проверяя возможность
    //  создания множества
    SetClass(int size, int min, int max); 

    // F6 Мощность множества
    int setPowers(); 

    // F7 Вывод элементов множества
    string setView(char separator); 

    // F8 Удаление множества (очистка занимаемой множеством памяти)
    ~SetClass();

    // F9 Подмножестов А-B
    bool isSubSet(SetClass* setSecond);

    // F10 Равенство двух множеств А-В
    bool isSetsEquals(SetClass* setSecond);

    // F11 Объединение двух множеств
    SetClass* unionOfSets(SetClass* setSecond);

    // F12 Пересечение двух множеств
    SetClass* intersectionsOfSets(SetClass* setSecond);

    // F13 Разность множеств
    SetClass* differenceOfSets(SetClass* setSecond);

    // F14 Симметричная разность
    SetClass* symmetricDifferenceOfSets(SetClass* setSecond);
};