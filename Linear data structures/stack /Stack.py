class Node:
    def __init__(self,data = None):
        self.data = data
        self.next = None


class stack:
    def __init__(self): 
        self.top = None
        self.size = 0

    def push(self,data): #Push operation
        node = Node(data)
        if self.top:
            node.next = self.top
            self.top = node
        else:
            self.top = node
        self.size += 1

    def pop(self):  #Pop operation
        if self.top:
            data = self.top.data
            self.size -= 1
            if self.top.next:
                self.top = self.top.next
            else:
                self.top = None
                return data
        else:
            return None

