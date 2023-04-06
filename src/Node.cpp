#include "Node.h"

// F1 Создание пустого множества
Node* createEmptySet() {
    return NULL;
}

// F2 Проверка на пустоту множества
bool isEmptySet(Node* first) {
    return first == nullptr ? true : false;
}

// F3 Проверка элемента на принадлежность множеству
bool isSetHasElement(Node* first, int element) {
    if (isEmptySet(first)) {
        return false;
    } 
    Node* current = first;
    while (current != NULL)
    {
        if (current -> element == element){
            return true;
        }
        current = current -> next;
    }
    return false;
}

// F4 Добавление нового элемента в начало множества
Node* addNewElement(Node* first, int element) {
    if (!isSetHasElement(first, element)){
        Node* newSet = new Node;
        newSet->element = element;
        newSet->next = first;
        first = newSet;
    }
    return first;
}

// F5 Создание множества по заданным параметрам, проверяя возможность
//  создания множества
Node* createNewSet(int size, int min, int max) {
    if (size <= 0) {
        return NULL;
    }

    if (max < min) {
        return NULL;
    }

    if (size > max - min + 1) {
        return NULL;
    }

    Node* newSet = new Node{};    
    int currentSize = 1;
    srand(time(NULL));

    newSet->element = min + rand() % (max - min + 1);
    while (currentSize < size) {
        int temp = newSet->element;
        newSet = addNewElement(newSet, min + rand() % (max - min + 1));
        if (temp != newSet->element) {
            currentSize++;
        }
    }

    return newSet;
}

// F6 Мощность множества
int setPowers(Node* first) {
    long count = 0;
    Node* currentSet = first;
    while (currentSet != NULL) {
        count++;
        currentSet = currentSet->next;
    }
    return count;
}

// F7 Вывод элементов множества
string setView(Node* first, char separator) {
    if (isEmptySet(first)) {
        return "";
    }
    Node* currentSet = first;
    string result = "";
    while (currentSet != NULL) {
        result += to_string(currentSet->element) + separator;
        currentSet = currentSet->next;
    }

    return result.erase(result.size() - 1);
}

// F8 Удаление множества (очистка занимаемой множеством памяти)
Node* deleteSet(Node* first) {
    while (first != NULL){
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    return first;
}

// F9 Подмножестов А-B
bool isSubSet(Node* first, Node* second) {
    if (isEmptySet(first)) {
        return true;
    }

    if (setPowers(first) > setPowers(second)) {
        return false;
    }
    
    Node* currentFirst = first;
    while (currentFirst != NULL) {
        if (!isSetHasElement(second, currentFirst->element)) {
            return false;
        }
        currentFirst = currentFirst->next;
    }

    return true;
}

// F10 Равенство двух множеств А-В
bool isSetsEquals(Node* first, Node* second) {
    return isSubSet(first, second) && isSubSet(second, first);
}

// F11 Объединение двух множеств
Node* unionOfSets(Node* first, Node* second) {

    Node* unionSet = createEmptySet();
    Node* currentFirst = first;
    Node* currentSecond = second;
    
    while (currentFirst != NULL) {
        unionSet = addNewElement(unionSet, currentFirst->element);
        currentFirst = currentFirst->next;
    }

    while (currentSecond != NULL) {
        unionSet = addNewElement(unionSet, currentSecond->element);
        currentSecond = currentSecond->next;
    }
    
    return unionSet;
}

// F12 Пересечение двух множеств
Node* intersectionsOfSets(Node* first, Node* second) {
    Node* current = first;
    Node* intersection = createEmptySet();

    while (current != NULL) {
        if (!isEmptySet(current)) {
            if (isSetHasElement(second, current->element)){
                intersection = addNewElement(intersection, current->element);
            }
            current = current->next;
        }
    }
    return intersection;
}

// F13 Разность множеств
Node* differenceOfSets(Node* first, Node* second) {
    Node* current = first;
    Node* intersection = createEmptySet();

    while (current != NULL) {
        if (!isEmptySet(current)) {
            if (!isSetHasElement(second, current->element)){
                intersection = addNewElement(intersection, current->element);
            }
            current = current->next;
        }
    }
    return intersection;
}

// F14 Симметричная разность
Node* symmetricDifferenceOfSets(Node* first, Node* second) {
    return differenceOfSets(unionOfSets(first, second), intersectionsOfSets(second, first));
}