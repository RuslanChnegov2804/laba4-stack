#include "stack.h"

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

void printHelp() {
    std::cout << "Доступные команды:\n";
    std::cout << "  spush <число> - добавить число в стек\n";
    std::cout << "  spop          - удалить верхний элемент\n";
    std::cout << "  stop          - показать верхний элемент\n";
    std::cout << "  sprint        - вывести стек\n";
    std::cout << "  ssize         - показать размер стека\n";
    std::cout << "  sempty        - проверить, пуст ли стек\n";
    std::cout << "  sclear        - очистить стек\n";
    std::cout << "  help          - показать список команд\n";
    std::cout << "  exit          - выйти из программы\n";
}

int main() {
    Stack stack;
    std::string line;

    std::cout << "Консольная программа для работы со стеком\n";
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
