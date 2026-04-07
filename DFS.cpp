#include <iostream>
#include <vector>

void DFS(int start, std::vector<std::vector<int>>& array, std::vector<int>& answer, std::vector<bool>& visited) {
    visited[start] = true;

    for (int i = 0; i < array.size(); i++) {
        if (array[i][0] == start) {
            int next = array[i][1];
            if (!visited[next]) {
                answer.push_back(next);
                DFS(next, array, answer, visited);
            };
        };
    };
}

int main() {
    int n;
    std::cout << "Enter number of vertexes: ";
    std::cin >> n;

    int k;
    std::cout << "Enter number of edges: ";
    std::cin >> k;

    std::vector<std::vector<int>> edges(k, std::vector<int>(2));
    std::cout << "Enter edges:\n";
    for (int i = 0; i < k; i++) {
        std::cin >> edges[i][0] >> edges[i][1];
    }

    std::vector<int> answer;
    std::vector<bool> visited(n, false);

    int start = 0;
    answer.push_back(start);

    DFS(start, edges, answer, visited);

    for (int x : answer) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}