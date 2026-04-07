#include <iostream>
#include <vector>
#include <queue>

void BFS(int start,
         std::vector<std::vector<int>>& array,
         std::vector<int>& answer,
         std::vector<bool>& visited)
{
    std::queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < array.size(); i++) {
            if (array[i][0] == current) {
                int next = array[i][1];

                if (!visited[next]) {
                    visited[next] = true;
                    answer.push_back(next);
                    q.push(next);
                }
            }
        }
    }
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

    BFS(start, edges, answer, visited);

    for (int x : answer) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}