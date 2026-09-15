#include "stack.h"
#include "queue.h"
#include "tree.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

void printHelp() {
    std::cout << "\nСтек\n";
    std::cout << "spush <число> - добавить число в стек\n";
    std::cout << "spop          - удалить верхний элемент\n";
    std::cout << "stop          - показать верхний элемент\n";
    std::cout << "sprint        - вывести стек\n";
    std::cout << "ssize         - показать размер стека\n";
    std::cout << "sempty        - проверить, пуст ли стек\n";
    std::cout << "sclear        - очистить стек\n";

    std::cout << "\nОчередь\n";
    std::cout << "qpush <число> - добавить элемент в очередь\n";
    std::cout << "qpop          - удалить первый элемент очереди\n";
    std::cout << "qfront        - показать первый элемент очереди\n";
    std::cout << "qprint        - вывести очередь\n";
    std::cout << "qsize         - показать размер очереди\n";
    std::cout << "qempty        - проверить, пуста ли очередь\n";
    std::cout << "qclear        - очистить очередь\n";

    std::cout << "\nДерево\n";
    std::cout << "binsert <число> - добавить элемент в дерево\n";
    std::cout << "bsearch <число> - найти элемент в дереве\n";
    std::cout << "bprint          - вывести дерево по возрастанию\n";
    std::cout << "bsize           - показать размер дерева\n";
    std::cout << "bempty          - проверить, пусто ли дерево\n";
    std::cout << "bclear          - очистить дерево\n";

    std::cout << "\nДругое:\n";
    std::cout << "help            - показать список команд\n";
    std::cout << "exit            - выйти из программы\n";

}
int main() {
    Stack stack;
    Queue queue;
    Tree tree;
    std::string line;

    std::cout << "Консольная программа для работы со стеком, деревом и очередью\n";
    printHelp();

    while (true) {
        std::cout << "> ";

        if (!std::getline(std::cin, line)) {
            break;
        }

        std::istringstream input(line);
        std::string command;

        input >> command;

        try {
            if (command == "spush") {
                int value;

                if (input >> value) {
                    stack.push(value);
                    std::cout << "Добавлено: " << value << '\n';
                } else {
                    std::cout << "Использование: spush <число>\n";
                }
            }
            else if (command == "spop") {
                int value = stack.pop();
                std::cout << "Удалено: " << value << '\n';
            }
            else if (command == "stop") {
                std::cout << "Верхний элемент: " << stack.top() << '\n';
            }
            else if (command == "sprint") {
                stack.print();
            }
            else if (command == "ssize") {
                std::cout << "Размер стека: " << stack.size() << '\n';
            }
            else if (command == "sempty") {
                std::cout << (stack.empty() ? "Стек пуст" : "Стек не пуст") << '\n';
            }
            else if (command == "sclear") {
                stack.clear();
                std::cout << "Стек очищен\n";
            }
            else if (command == "help") {
                printHelp();
            }
            else if (command == "exit") {
                std::cout << "Выход из программы\n";
                break;
            }
            else if (command.empty()) {
                continue;
            }
            else if (command == "qpush") {
    int value;

    if (input >> value) {
        queue.push(value);
        std::cout << "Добавлено в очередь: " << value << '\n';
    } else {
        std::cout << "Ошибка: укажите число\n";
    }
}
else if (command == "qpop") {
    int value = queue.pop();
    std::cout << "Удалено из очереди: " << value << '\n';
}
else if (command == "qfront") {
    std::cout << "Первый элемент: " << queue.front() << '\n';
}
else if (command == "qprint") {
    queue.print();
}
else if (command == "qsize") {
    std::cout << "Размер очереди: " << queue.size() << '\n';
}
else if (command == "qempty") {
    if (queue.empty()) {
        std::cout << "Очередь пуста\n";
    } else {
        std::cout << "Очередь не пуста\n";
    }
}
else if (command == "qclear") {
    queue.clear();
    std::cout << "Очередь очищена\n";
}
else if (command == "binsert") {
    int value;

    if (input >> value) {
        tree.insert(value);
        std::cout << "Добавлено в дерево: " << value << '\n';
    } else {
        std::cout << "Ошибка: укажите число\n";
    }
}
else if (command == "bsearch") {
    int value;

    if (input >> value) {
        if (tree.search(value)) {
            std::cout << "Элемент найден\n";
        } else {
            std::cout << "Элемент не найден\n";
        }
    } else {
        std::cout << "Ошибка: укажите число\n";
    }
}
else if (command == "bprint") {
    tree.print();
}
else if (command == "bsize") {
    std::cout << "Размер дерева: " << tree.size() << '\n';
}
else if (command == "bempty") {
    if (tree.empty()) {
        std::cout << "Дерево пусто\n";
    } else {
        std::cout << "Дерево не пусто\n";
    }
}
else if (command == "bclear") {
    tree.clear();
    std::cout << "Дерево очищено\n";
}
            else {
                std::cout << "Неизвестная команда. Введите help.\n";
            }
        }
        catch (const std::underflow_error& error) {
            std::cout << "Ошибка: " << error.what() << '\n';
        }
    }

    return 0;
}
