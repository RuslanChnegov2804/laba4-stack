# Лабораторная работа 4(Stack)

Реализованно на: C++, Python

## Консольные команды: 
spush <число> - добавить число в стек
spop          - удалить верхний элемент
stop          - показать верхний элемент
sprint        - вывести стек
ssize         - показать размер стека
sempty        - проверить, пуст ли стек
sclear        - очистить стек
help          - показать список команд
exit          - выйти из программы

## Структура проекта

```text
laba4-stack/
├── cpp/
│   ├── include/
│   │   └── stack.h
│   ├── src/
│   │   ├── main.cpp
│   │   └── stack.cpp
│   └── tests/
│       └── test_stack.cpp
│
├── python/
│   ├── main.py
│   ├── stack.py
│   └── test_stack.py
│
├── .github/
│   └── workflows/
│       └── coverage.yml
│
├── CMakeLists.txt
├── requirements.txt
├── .gitignore
└── READMdE.m
```

#C++
##Сборка
cmake -S . -B build
cmake --build build

##Запуск
./build/stack_app

## Тесты

Используется GoogleTest.

ctest --test-dir build --output-on-failure
или:
./build/stack_tests

## Покрытие тестами

Для C++ используется: gcov; lcov; genhtml.

# Python

## Запуск
python3 python/main.py

## Создание виртуального окружения
python3 -m venv .venv
source .venv/bin/activate

## Установка зависимостей
python -m pip install -r requirements.txt

## Тесты
Перейти в папку Python:
cd python

Запустить:
pytest -v

## Покрытие тестамиh
pytest --cov=stack --cov-report=term-missing --cov-report=html
## Отчет
python/htmlcov/index.html





