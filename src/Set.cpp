#include "Set.h"

// F1  Создание пустого множества
SetClass::SetClass() {
    set = {};
}

// F2 Проверка на пустоту множества
bool SetClass::isSetEmpty() {
    return set.empty();
}

// F3 Проверка элемента на принадлежность множеству
bool SetClass::isSetHasElement(int element) {
    if (this->isSetEmpty()) {
        return false;
    }
    return this->set.contains(element);
}

// F4 Добавление нового элемента в начало множества
//SetList* 
bool SetClass::addNewElement(int element) {
    if (!this->isSetHasElement(element)) {
        return this->set.insert(element).second;
    }
    return false;
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
SetClass::SetClass(int size, int min, int max) {
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

    while (this->set.size() < size) {
        if (!this->addNewElement(min + rand() % (max - min + 1))) {
            continue;
        }
    }
}

// F6 Мощность множества
int SetClass::setPowers() {
    return this->set.size();
}

// F7 Вывод элементов множества
string SetClass::setView(char separator) {
    if (this->isSetEmpty()) {
        return "";
    }
    
    string result = "";
    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter) {
        result += to_string(*iter) + separator;
    }
    return result.erase(result.size() - 1);
}

// F8 Удаление множества (очистка занимаемой множеством памяти)
SetClass::~SetClass() {
    this->set.clear();
}

// F9 Подмножестов А-B
bool SetClass::isSubSet(SetClass* setSecond) {
    if (this->isSetEmpty()) {
        return true;
    }

    if (this->setPowers() > setSecond->setPowers()) {
        return false;
    }

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (!setSecond->isSetHasElement(*iter)) {
            return false;
        }
    }
    return true;
}
  
// F10 Равенство двух множеств А-В
bool SetClass::isSetsEquals(SetClass* setSecond) {
    return this->isSubSet(setSecond) && setSecond->isSubSet(this);
}

// F11 Объединение двух множеств
SetClass* SetClass::unionOfSets(SetClass* setSecond) {
    SetClass* unionSet = new SetClass();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        unionSet->addNewElement(*iter);
    }

    for (auto iter = setSecond->set.begin(); iter != setSecond->set.end(); ++iter){
        unionSet->addNewElement(*iter);
    }

    return unionSet;
}

// F12 Пересечение двух множеств
SetClass* SetClass::intersectionsOfSets(SetClass* setSecond) {
    SetClass* intersectionSet = new SetClass();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (setSecond->isSetHasElement(*iter)){
            intersectionSet->addNewElement(*iter);
        }
    }
    
    return intersectionSet;
}

// F13 Разность множеств
SetClass* SetClass::differenceOfSets(SetClass* setSecond) {
    SetClass* differenceSet = new SetClass();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (!setSecond->isSetHasElement(*iter)){
            differenceSet->addNewElement(*iter);
        }
    }
    
    return differenceSet;
}

// F14 Симметричная разность
SetClass* SetClass::symmetricDifferenceOfSets(SetClass* setSecond) {
    SetClass* unionSet = this->unionOfSets(setSecond);
    SetClass* intersectionSet = this->intersectionsOfSets(setSecond);
    return unionSet->differenceOfSets(intersectionSet);
}