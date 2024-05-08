#include <iostream>
#include <map>
#include <vector>

using namespace std;

class GenealogicalTree {
private:
    map<int, vector<int>> tree; // Карта для хранения древа: ключ - высота, значение - вектор узлов на этой высоте

public:
    // Добавление родителя с заданной высотой и его детей
    void addParent(int height, const vector<int>& children) {
        tree[height] = children;
    }

    // Вывод генеалогического древа
    void printTree() {
        for (const auto& pair : tree) {
            cout << "Высота " << pair.first << ": ";
            for (int node : pair.second) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GenealogicalTree familyTree;

    // Пример заполнения генеалогического древа
    familyTree.addParent(0, {1, 2}); // У родоначальника высота 0, у него два потомка
    familyTree.addParent(1, {3, 4, 5}); // У первого потомка высота 1, у него три потомка
    familyTree.addParent(2, {6, 7}); // У второго потомка высота 1, у него два потомка

    // Вывод генеалогического древа
    familyTree.printTree();

    return 0;
}
