#include "UnorderedMap.h"

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
    return this->set.contains(element);
}

// F4 Добавление нового элемента в начало множества
bool Set::addNewElement(int element) {
    if (!this->isSetHasElement(element)) {
        return this->set.insert({element, element}).second;
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
    int current_size = 0;

    while (current_size < size) {
        if (this->addNewElement(min + rand() % (max - min + 1))) {
            current_size++;
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
        result += to_string(iter->second) + separator;
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

    for (auto iter = this->set.begin(); iter != this->set.end(); iter++) {
        if (!setSecond->isSetHasElement(iter->second)) {
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
        unionSet->addNewElement(iter->second);
    }

    for (auto iter = setSecond->set.begin(); iter != setSecond->set.end(); ++iter){
        unionSet->addNewElement(iter->second);
    }

    return unionSet;
}

// F12 Пересечение двух множеств
Set* Set::intersectionsOfSets(Set* setSecond) {
    Set* intersectionSet = new Set();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (setSecond->isSetHasElement(iter->second)){
            intersectionSet->addNewElement(iter->second);
        }
    }
    
    return intersectionSet;
}

// F13 Разность множеств
Set* Set::differenceOfSets(Set* setSecond) {
    Set* differenceSet = new Set();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (!setSecond->isSetHasElement(iter->second)){
            differenceSet->addNewElement(iter->second);
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