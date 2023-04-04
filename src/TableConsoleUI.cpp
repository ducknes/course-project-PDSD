#include "Node.h"
#include "List.h"
#include "ContList.h"
#include "Set.h"
#include "ForwardList.h"
#include "UnorderedMap.h"

void tableView() {
    int N;
    cout << "Введите размер массива(>=1000): ";
    cin >> N;
    cout << endl;

    Node* nodeSet = createNewSet(N, 0, 10 * N);
    Set* listSet = new Set(N, 0, 10 * N);
}