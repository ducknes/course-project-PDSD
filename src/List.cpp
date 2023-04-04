#include "List.h"

// F1  Создание пустого множества
ListSet::ListSet() {
    head = NULL;
}

// F2 Проверка на пустоту множества
bool ListSet::isSetEmpty() {
    return head == NULL;
}

// F3 Проверка элемента на принадлежность множеству
bool ListSet::isSetHasElement(int element) {
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
void ListSet::addNewElement(int element) {
    if (!this->isSetHasElement(element)) {
        SetList* newSet = new SetList{};
        newSet->next = this->head;
        newSet->element = element;
        this->head = newSet;
    }
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
ListSet::ListSet(int size, int min, int max) {
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
int ListSet::setPowers() {
    long count = 0;
    SetList* current = this->head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// F7 Вывод элементов множества
string ListSet::setView(char separator) {
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
ListSet::~ListSet() {
    while (this->head != nullptr) {
        SetList* temp = this->head;
        this->head = this->head->next;
        delete temp;    
    }
}

// F9 Подмножестов А-B
bool ListSet::isSubSet(ListSet* setSecond) {
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
bool ListSet::isSetsEquals(ListSet* setSecond) {
    return this->isSubSet(setSecond) && setSecond->isSubSet(this);
}

// F11 Объединение двух множеств
ListSet* ListSet::unionOfSets(ListSet* setSecond) {
    ListSet* unionSet = new ListSet();

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
ListSet* ListSet::intersectionsOfSets(ListSet* setSecond) {
    SetList* currentFirst = this->head;
    ListSet* intersectionSet = new ListSet();

    while (currentFirst != nullptr) {
        if (setSecond->isSetHasElement(currentFirst->element)){
            intersectionSet->addNewElement(currentFirst->element);
        }
        currentFirst = currentFirst->next;
    }
    
    return intersectionSet;
}

// F13 Разность множеств
ListSet* ListSet::differenceOfSets(ListSet* setSecond) {
    SetList* currentFirst = this->head;
    ListSet* differenceSet = new ListSet();

    while (currentFirst != nullptr) {
        if (!setSecond->isSetHasElement(currentFirst->element)){
            differenceSet->addNewElement(currentFirst->element);
        }
        currentFirst = currentFirst->next;
    }
    
    return differenceSet;
}

// F14 Симметричная разность
ListSet* ListSet::symmetricDifferenceOfSets(ListSet* setSecond) {
    ListSet* unionSet = this->unionOfSets(setSecond);
    ListSet* intersectionSet = this->intersectionsOfSets(setSecond);
    return unionSet->differenceOfSets(intersectionSet);
}