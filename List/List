class Node:
    def __init__(self,data = None):
        self.data = data
        self.next = None
        
class List():
    def __init__(self):
        self.tail = None
        self.head = None
        
    def append(self,data):
        node = Node(data)
        if self.head:
            self.head.next = node
            self.head = node
        else:
            self.tail = node
            self.head = None
