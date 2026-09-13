from stack import Stack


def print_help():
    print("Доступные команды:")
    print("  spush <число> - добавить число в стек")
    print("  spop          - удалить верхний элемент")
    print("  stop          - показать верхний элемент")
    print("  sprint        - вывести стек")
    print("  ssize         - показать размер стека")
    print("  sempty        - проверить, пуст ли стек")
    print("  sclear        - очистить стек")
    print("  help          - показать список команд")
    print("  exit          - выйти из программы")


def main():
    stack = Stack()

    print("Консольная программа для работы со стеком")
    print_help()

    while True:
        line = input("> ").strip()

        if not line:
            continue

        parts = line.split()
        command = parts[0]

        try:
            if command == "spush":
                if len(parts) != 2:
                    print("Использование: spush <число>")
                    continue

                try:
                    value = int(parts[1])
                except ValueError:
                    print("Ошибка: необходимо ввести целое число")
                    continue

                stack.push(value)
                print(f"Добавлено: {value}")

            elif command == "spop":
                value = stack.pop()
                print(f"Удалено: {value}")

            elif command == "stop":
                print(f"Верхний элемент: {stack.top()}")

            elif command == "sprint":
                stack.print_stack()

            elif command == "ssize":
                print(f"Размер стека: {stack.size()}")

            elif command == "sempty":
                if stack.empty():
                    print("Стек пуст")
                else:
                    print("Стек не пуст")

            elif command == "sclear":
                stack.clear()
                print("Стек очищен")

            elif command == "help":
                print_help()

            elif command == "exit":
                print("Выход из программы")
                break

            else:
                print("Неизвестная команда. Введите help.")

        except IndexError as error:
            print(f"Ошибка: {error}")


if __name__ == "__main__":
    main()
