#include "ForwardList.h"

// F1  Создание пустого множества
ForwardListSet::ForwardListSet() {
    set = {};
}

// F2 Проверка на пустоту множества
bool ForwardListSet::isSetEmpty() {
    return set.empty();
}

// F3 Проверка элемента на принадлежность множеству
bool ForwardListSet::isSetHasElement(int element) {
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
void ForwardListSet::addNewElement(int element) {
    if (!this->isSetHasElement(element)) {
        this->set.push_front(element);
    }
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
ForwardListSet::ForwardListSet(int size, int min, int max) {
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
int ForwardListSet::setPowers() {
    return distance(this->set.begin(), this->set.end());
}

// F7 Вывод элементов множества
string ForwardListSet::setView(char separator) {
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
ForwardListSet::~ForwardListSet() {
    this->set.clear();
}

// F9 Подмножестов А-B
bool ForwardListSet::isSubSet(ForwardListSet* setSecond) {
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
bool ForwardListSet::isSetsEquals(ForwardListSet* setSecond) {
    return this->isSubSet(setSecond) && setSecond->isSubSet(this);
}

// F11 Объединение двух множеств
ForwardListSet* ForwardListSet::unionOfSets(ForwardListSet* setSecond) {
    ForwardListSet* unionSet = new ForwardListSet();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        unionSet->addNewElement(*iter);
    }

    for (auto iter = setSecond->set.begin(); iter != setSecond->set.end(); ++iter){
        unionSet->addNewElement(*iter);
    }

    return unionSet;
}

// F12 Пересечение двух множеств
ForwardListSet* ForwardListSet::intersectionsOfSets(ForwardListSet* setSecond) {
    ForwardListSet* intersectionSet = new ForwardListSet();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (setSecond->isSetHasElement(*iter)){
            intersectionSet->addNewElement(*iter);
        }
    }
    
    return intersectionSet;
}

// F13 Разность множеств
ForwardListSet* ForwardListSet::differenceOfSets(ForwardListSet* setSecond) {
    ForwardListSet* differenceSet = new ForwardListSet();

    for (auto iter = this->set.begin(); iter != this->set.end(); ++iter){
        if (!setSecond->isSetHasElement(*iter)){
            differenceSet->addNewElement(*iter);
        }
    }
    
    return differenceSet;
}

// F14 Симметричная разность
ForwardListSet* ForwardListSet::symmetricDifferenceOfSets(ForwardListSet* setSecond) {
    ForwardListSet* unionSet = this->unionOfSets(setSecond);
    ForwardListSet* intersectionSet = this->intersectionsOfSets(setSecond);
    return unionSet->differenceOfSets(intersectionSet);
}