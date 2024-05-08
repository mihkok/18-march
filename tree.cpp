#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> heights;
    map<string, string> parents;


    for (int i = 0; i < N - 1; ++i) {
        string child, parent;
        cin >> child >> parent;
        parents[child] = parent;
    }


    for (auto const& [child, parent] : parents) {
        if (heights.find(child) == heights.end()) {
            string current = child;
            int height = 0;
            while (parents.find(current) != parents.end()) {
                height++;
                current = parents[current];
            }
            heights[child] = height;
        }
    }

    // Output
    for (auto const& [name, height] : heights) {
        cout << name << " " << height << endl;
    }

    return 0;
}
