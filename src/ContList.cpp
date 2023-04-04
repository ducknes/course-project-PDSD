#include "ContList.h"

// F1  Создание пустого множества
Set::Set() {
    set = {};
}

// F2 Проверка на пустоту множества
bool Set::isSetEmpty() {
    return set.empty();
}

// F3 Проверка элемента на принадлежность множеству
bool Set::isSetHasElement(int element) {
    if (this->isSetEmpty()) {
        return false;
    }

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter) {
        if (*iter == element) {
            return true;
        }
    }
    return false;
}

// F4 Добавление нового элемента в начало множества
//SetList* s
void Set::addNewElement(int element) {
    if (!this->isSetHasElement(element)) {
        this->set.push_front(element);
    }
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Set::Set(int size, int min, int max) {
    if (size <= 0) {
        set = {};
    }

    if (max < min) {
        set = {};
    }

    if (size > max - min + 1) {
        set = {};
    }

    srand(time(nullptr));
    int currentSize = 1;

    this->addNewElement(min + rand() % (max - min + 1));
    while (currentSize < size) {
        int temp = this->set.front();
        this->addNewElement(((min + 3) + rand() % ((max - min + 1))) / 3 * 3);
        if (temp != this->set.front()) {
            currentSize++;
        }
    }
}

// F6 Мощность множества
int Set::setPowers() {
    return this->set.size();
}

// F7 Вывод элементов множества
string Set::setView(char separator) {
    if (this->isSetEmpty()) {
        return "";
    }
    
    string result = "";
    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        result += to_string(*iter) + separator;
    }
    return result.erase(result.size() - 1);
}

// F8 Удаление множества (очистка занимаемой множеством памяти)
Set::~Set() {
    this->set.clear();
}

// F9 Подмножестов А-B
bool Set::isSubSet(Set* setSecond) {
    if (this->isSetEmpty()) {
        return true;
    }

    if (this->setPowers() > setSecond->setPowers()) {
        return false;
    }

    for (int i : this->set){
        if (!setSecond->isSetHasElement(i)) {
            return false;
        }
    }
    return true;
}
  
// F10 Равенство двух множеств А-В
bool Set::isSetsEquals(Set* setSecond) {
    return this->isSubSet(setSecond) && setSecond->isSubSet(this);
}

// F11 Объединение двух множеств
Set* Set::unionOfSets(Set* setSecond) {
    Set* unionSet = new Set();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        unionSet->addNewElement(*iter);
    }

    for (auto iter = setSecond->set.begin(); iter != setSecond->set.end(); ++iter){
        unionSet->addNewElement(*iter);
    }

    return unionSet;
}

// F12 Пересечение двух множеств
Set* Set::intersectionsOfSets(Set* setSecond) {
    Set* intersectionSet = new Set();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (setSecond->isSetHasElement(*iter)){
            intersectionSet->addNewElement(*iter);
        }
    }
    
    return intersectionSet;
}

// F13 Разность множеств
Set* Set::differenceOfSets(Set* setSecond) {
    Set* differenceSet = new Set();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (!setSecond->isSetHasElement(*iter)){
            differenceSet->addNewElement(*iter);
        }
    }
    
    return differenceSet;
}

// F14 Симметричная разность
Set* Set::symmetricDifferenceOfSets(Set* setSecond) {
    Set* unionSet = this->unionOfSets(setSecond);
    Set* intersectionSet = this->intersectionsOfSets(setSecond);
    return unionSet->differenceOfSets(intersectionSet);
}