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
        """Method to insert an element in the queue"""
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
        """methodd to remove the first element in the queue"""
        current = self.head
        if self.count == 1:
            self.count -= 1
            self.head = None
            self.tail = None
        elif self.count > 1:
            self.head = self.head.next 
            self.head.prev = None
            self.count -= 1
    
    def print_all(self):
        """Method to show all the elements in the queue"""
        head = q1.head
        print("{}, {}, {}".format(head.data.type,head.data.size,head.data.id))
        while True:
            try:
                head = head.next
                print("{}, {}, {}".format(head.data.type,head.data.size,head.data.id))
            except:
                break

class plane:
    def __init__(self,plane_type,size,id):
        self.type = plane_type
        self.size = size
        self.id = id
        
if __name__ == "__main__":
    q1 = queue()
    q1.enqueue(plane("cargo","large","C1"))
    q1.enqueue(plane("Passenger","Medium","P1"))
    q1.enqueue(plane("Passenger","Large","P2"))

    print("Planes in queue:\n%s" %"------------------------")
    q1.print_all()