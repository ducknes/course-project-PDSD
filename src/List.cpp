#include "List.h"

// F1  Создание пустого множества
Set::Set() {
    head = NULL;
}

// F2 Проверка на пустоту множества
bool Set::isSetEmpty() {
    return head == NULL;
}

// F3 Проверка элемента на принадлежность множеству
bool Set::isSetHasElement(int element) {
    if (this->isSetEmpty()) {
        return false;
    }
    SetList* current = this->head;
    while (current != NULL) {
        if (current->element == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// F4 Добавление нового элемента в начало множества
//SetList* 
void Set::addNewElement(int element) {
    if (!this->isSetHasElement(element)) {
        SetList* newSet = new SetList{};
        newSet->next = this->head;
        newSet->element = element;
        this->head = newSet;
    }
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Set::Set(int size, int min, int max) {
    if (size <= 0) {
        head = NULL;
    }

    if (max < min) {
        head = NULL;
    }

    if (size > max - min + 1) {
        head = NULL;
    }

    srand(time(nullptr));
    int currentSize = 1;
    head = new SetList{};

    head->element = min + rand() % (max - min + 1);
    while (currentSize < size) {
        int temp = head->element;
        this->addNewElement(min + rand() % (max - min + 1));
        if (temp != head->element) {
            currentSize++;
        }
    }
}

// F6 Мощность множества
int Set::setPowers() {
    long count = 0;
    SetList* current = this->head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// F7 Вывод элементов множества
string Set::setView(char separator) {
    if (this->isSetEmpty()) {
        return "";
    }
    SetList* current = this->head;
    string result = "";
    while (current != nullptr) {
        result += to_string(current->element) + separator;
        current= current->next;
    }
    return result.erase(result.size() - 1);
}

// F8 Удаление множества (очистка занимаемой множеством памяти)
Set::~Set() {
    while (this->head != nullptr) {
        SetList* temp = this->head;
        this->head = this->head->next;
        delete temp;    
    }
}

// F9 Подмножестов А-B
bool Set::isSubSet(Set* setSecond) {
    if (this->isSetEmpty()) {
        return true;
    }

    if (this->setPowers() > setSecond->setPowers()) {
        return false;
    }

    SetList* current = this->head;
    while (current != nullptr) {
        if (!setSecond->isSetHasElement(current->element)) {
            return false;
        }
        current = current->next;
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

    SetList* currentFirst = this->head;
    SetList* currentSecond = setSecond->head;

    while (currentFirst != nullptr) {
        unionSet->addNewElement(currentFirst->element);
        currentFirst = currentFirst->next;
    }

    while (currentSecond != nullptr) {
        unionSet->addNewElement(currentSecond->element);
        currentSecond = currentSecond->next;
    }

    return unionSet;
}

// F12 Пересечение двух множеств
Set* Set::intersectionsOfSets(Set* setSecond) {
    SetList* currentFirst = this->head;
    Set* intersectionSet = new Set();

    while (currentFirst != nullptr) {
        if (setSecond->isSetHasElement(currentFirst->element)){
            intersectionSet->addNewElement(currentFirst->element);
        }
        currentFirst = currentFirst->next;
    }
    
    return intersectionSet;
}

// F13 Разность множеств
Set* Set::differenceOfSets(Set* setSecond) {
    SetList* currentFirst = this->head;
    Set* differenceSet = new Set();

    while (currentFirst != nullptr) {
        if (!setSecond->isSetHasElement(currentFirst->element)){
            differenceSet->addNewElement(currentFirst->element);
        }
        currentFirst = currentFirst->next;
    }
    
    return differenceSet;
}

// F14 Симметричная разность
Set* Set::symmetricDifferenceOfSets(Set* setSecond) {
    Set* unionSet = this->unionOfSets(setSecond);
    Set* intersectionSet = this->intersectionsOfSets(setSecond);
    return unionSet->differenceOfSets(intersectionSet);
}