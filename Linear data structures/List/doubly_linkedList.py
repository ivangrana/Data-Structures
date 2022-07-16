class Node:
    def __init__(self,data = None,next = None,prev = None):
        self.data = data
        self.next = next #reference to the next node
        self.prev = prev #reference on the previous node
        
        
class double_linked():
    def __init__(self):
        self.lenght = 0
        self.head = None
        self.tail = None
        
    def append(self,data):
        new_node = Node(data,None,None)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.lenght += 1
        

