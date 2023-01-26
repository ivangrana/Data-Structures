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
                        parent.l_child = Node(data)
                        return
                else:
                    current = current.r_child
                    if current is None:
                        parent.r_child = node
                        return
    
    def inorder_traversal(self,root_node):
        current = root_node 
        if current is None:
            return 
        self.inorder_traversal(current.l_child)
        print(current.data)
        self.inorder_traversal(current.r_child)
    
if __name__ == "__main__":
    elements = [12,15,9,17]
    
    tree_1 = tree()

    for i in elements:
        tree_1.insert(i)
    

    tree_1.inorder_traversal(tree_1.root_node)