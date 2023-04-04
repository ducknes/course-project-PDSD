#include <iostream>
#include <ctime>
#include <string>
using namespace std;

struct Node {
    int element;
    Node* next;
};

// F1 пустое множество
Node* createEmptySet();

// F2 Проверка на пустоту множества
bool isEmptySet(Node* first);

// F3 Проверка элемента на принадлежность множеству
bool isSetHasElement(Node* first, int element); 

// F4 Добавление нового элемента в начало множества
Node* addNewElement(Node* first, int element); 

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Node* createNewSet(int size, int min, int max); 

// F6 Мощность множества
int setPowers(Node* first); 

// F7 Вывод элементов множества
string setView(Node* first, char separator); 

// F8 Удаление множества (очистка занимаемой множеством памяти)
Node* deleteSet(Node* first);

// F9 Подмножестов А-B
bool isSubSet(Node* first, Node* second);

// F10 Равенство двух множеств А-В
bool isSetsEquals(Node* first, Node* second);

// F11 Объединение двух множеств
Node* unionOfSets(Node* first, Node* second);

// F12 Пересечение двух множеств
Node* intersectionsOfSets(Node* first, Node* second);

// F13 Разность множеств
Node* differenceOfSets(Node* first, Node* second);

// F14 Симметричная разность
Node* symmetricDifferenceOfSets(Node* first, Node* second);
