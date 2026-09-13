class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack:
    def __init__(self):
        self.top_node = None
        self.stack_size = 0

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.top_node
        self.top_node = new_node
        self.stack_size += 1

    def pop(self):
        if self.empty():
            raise IndexError("Стек пуст")

        value = self.top_node.value
        self.top_node = self.top_node.next
        self.stack_size -= 1

        return value

    def top(self):
        if self.empty():
            raise IndexError("Стек пуст")

        return self.top_node.value

    def empty(self):
        return self.top_node is None

    def size(self):
        return self.stack_size

    def clear(self):
        self.top_node = None
        self.stack_size = 0

    def _print_from_bottom(self, node):
        if node is None:
            return

        self._print_from_bottom(node.next)

        if node.next is not None:
            print(" ", end="")

        print(node.value, end="")

    def print_stack(self):
        self._print_from_bottom(self.top_node)
        print()
