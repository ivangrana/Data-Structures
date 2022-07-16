class Node:
    def __init__(self,data):
        self.data = data
        self.r_child = None
        self.l_child = None 

class tree():
    def __init__(self):
        self.root_node = None
        
    def insert(self,data): #insert method 
        node = Node(data)
        if self.root_node is None:
            self.root_node = node
        else:
            current = self.root_node
            parent = None
        while True:
            parent = current
            if node.data < current.data:
                current = current.l_child
                if current is None:
                    parent.l_child = Node
                    return
            else:
                current = current.r_child
                if current is None:
                    parent.r_child = node
                    return
