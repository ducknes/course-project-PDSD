#include <iostream>
#include <string>
#include <time.h>
#include <unordered_map>
using namespace std;

class UnorderedMapSet
{
private:
    unordered_map<int, int> set;
public:
    // F1  Создание пустого множества
    UnorderedMapSet();

    // F2 Проверка на пустоту множества
    bool isSetEmpty();

    // F3 Проверка элемента на принадлежность множеству
    bool isSetHasElement(int element);

    // F4 Добавление нового элемента в начало множества
    //SetList* 
    bool addNewElement(int element);

    // F5 Создание множества по заданным параметрам, проверяя возможность
    //  создания множества
    UnorderedMapSet(int size, int min, int max); 

    // F6 Мощность множества
    int setPowers(); 

    // F7 Вывод элементов множества
    string setView(char separator); 

    // F8 Удаление множества (очистка занимаемой множеством памяти)
    ~UnorderedMapSet();

    // F9 Подмножестов А-B
    bool isSubSet(UnorderedMapSet* setSecond);

    // F10 Равенство двух множеств А-В
    bool isSetsEquals(UnorderedMapSet* setSecond);

    // F11 Объединение двух множеств
    UnorderedMapSet* unionOfSets(UnorderedMapSet* setSecond);

    // F12 Пересечение двух множеств
    UnorderedMapSet* intersectionsOfSets(UnorderedMapSet* setSecond);

    // F13 Разность множеств
    UnorderedMapSet* differenceOfSets(UnorderedMapSet* setSecond);

    // F14 Симметричная разность
    UnorderedMapSet* symmetricDifferenceOfSets(UnorderedMapSet* setSecond);
};