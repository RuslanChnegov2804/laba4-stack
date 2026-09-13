import pytest

from stack import Stack


def test_new_stack_is_empty():
    stack = Stack()

    assert stack.empty()
    assert stack.size() == 0


def test_push_adds_elements():
    stack = Stack()

    stack.push(10)
    stack.push(20)

    assert not stack.empty()
    assert stack.size() == 2
    assert stack.top() == 20


def test_pop_removes_top_element():
    stack = Stack()

    stack.push(10)
    stack.push(20)
    stack.push(30)

    assert stack.pop() == 30
    assert stack.top() == 20
    assert stack.size() == 2


def test_clear_removes_all_elements():
    stack = Stack()

    stack.push(10)
    stack.push(20)
    stack.push(30)

    stack.clear()

    assert stack.empty()
    assert stack.size() == 0


def test_pop_from_empty_stack_raises_exception():
    stack = Stack()

    with pytest.raises(IndexError):
        stack.pop()


def test_top_from_empty_stack_raises_exception():
    stack = Stack()

    with pytest.raises(IndexError):
        stack.top()


def test_print_stack(capsys):
    stack = Stack()

    stack.push(10)
    stack.push(20)
    stack.push(30)

    stack.print_stack()

    captured = capsys.readouterr()

    assert captured.out == "10 20 30\n"
