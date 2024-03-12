struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

struct Stack {
    top: Option<Box<Node>>,
    size: i8,
}

impl Stack {
    fn new() -> Stack {
        Stack { top: None, size: 0 }
    }

    fn push(&mut self, value: i32) {
        let new_node = Box::new(Node {
            value,
            next: self.top.take(),
        });
        self.top = Some(new_node);
        self.size += 1;
    }

    fn print_stack(self) {
        let mut current = self.top;
        while let Some(node) = current {
            println!("{}", node.value);
            current = node.next;
        }
    }

    fn pop(&mut self) -> Option<i32> {
        match self.top.take() {
            Some(boxed_node) => {
                let node = *boxed_node; // Extract the Node from the Box
                self.top = node.next; // Update top to point to the next node
                self.size -= 1; // Decrease the size of the stack
                Some(node.value) // Return the value of the popped Node
            }
            None => None, // Stack is empty
        }
    }
}

fn main() {
    let mut stack = Stack::new();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.print_stack();
}
