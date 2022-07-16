class Node:
    def __init__(self,data = None):
        self.data = data
        self.next = None

class queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def size(self):
        print(self.count)

    def enqueue(self,data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        
        self.count += 1

    def dequeue(self):
        current = self.head
        if self.count == 1:
            self.count -= 1
            self.head = None
            self.tail = None
        elif self.count > 1:
            self.head = self.head.next 
            self.head.prev = None
            self.count -= 1


