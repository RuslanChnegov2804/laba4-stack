# Лабораторная работа 4(СТЭК, ОЧЕРЕДЬ, ДЕРЕВО)

Реализованно на: C++

## Консольные команды: 
СТЭК:
spush <число> - добавить число в стек
spop          - удалить верхний элемент
stop          - показать верхний элемент
sprint        - вывести стек
ssize         - показать размер стека
sempty        - проверить, пуст ли стек
sclear        - очистить стек

ОЧЕРЕДЬ:
qpush <число>
qpop
qfront
qprint
qsize
qempty
qclear

ДЕРЕВО:
binsert <число>
bsearch <число>
bprint
bsize
bempty
bclear

ОБЩИЕ КОМАНДЫ:
help
exit

## Структура проекта

```text
laba4-stack/
├── cpp/
│   ├── include/
│   │   ├── stack.h
│   │   ├── queue.h
│   │   └── tree.h
│   ├── src/
│   │   ├── main.cpp
│   │   ├── stack.cpp
│   │   ├── queue.cpp
│   │   └── tree.cpp
│   └── tests/
│       ├── test_stack.cpp
│       ├── test_queue.cpp
│       └── test_tree.cpp
├── .github/
│   └── workflows/
│       └── coverage.yml
├── CMakeLists.txt
├── .gitignore
└── README.md
```+

##Сборка

```bash
cmake -S . -B build
cmake --build build
```

##Запуск

```bash
./build/stack_app
```

## Тесты
Используется GoogleTest.

```bash
ctest --test-dir build --output-on-failure
```

или:

```bash
./build/stack_tests
```

## Покрытие тестами

Для C++ используется: gcov; lcov; genhtml.




