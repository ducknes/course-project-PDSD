#include <iostream>
#include <string>
#include <time.h>
#include <list>
using namespace std;

class Set
{
private:
    list<int> set;
public:
    // F1  Создание пустого множества
    Set();

    // F2 Проверка на пустоту множества
    bool isSetEmpty();

    // F3 Проверка элемента на принадлежность множеству
    bool isSetHasElement(int element);

    // F4 Добавление нового элемента в начало множества
    //SetList* 
    void addNewElement(int element);

    // F5 Создание множества по заданным параметрам, проверяя возможность
    //  создания множества
    Set(int size, int min, int max, char whichCreate); 

    // F6 Мощность множества
    int setPowers(); 

    // F7 Вывод элементов множества
    string setView(char separator); 

    // F8 Удаление множества (очистка занимаемой множеством памяти)
    ~Set();

    // F9 Подмножестов А-B
    bool isSubSet(Set* setSecond);

    // F10 Равенство двух множеств А-В
    bool isSetsEquals(Set* setSecond);

    // F11 Объединение двух множеств
    Set* unionOfSets(Set* setSecond);

    // F12 Пересечение двух множеств
    Set* intersectionsOfSets(Set* setSecond);

    // F13 Разность множеств
    Set* differenceOfSets(Set* setSecond);

    // F14 Симметричная разность
    Set* symmetricDifferenceOfSets(Set* setSecond);
};