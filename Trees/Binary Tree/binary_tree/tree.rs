// Define a struct for the Node of the binary tree
pub struct TreeNode {
    value: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

// Implement methods for the TreeNode struct
impl TreeNode {
    // Constructor method to create a new node
    pub fn new(value: i32) -> Self {
        TreeNode {
            value,
            left: None,
            right: None,
        }
    }

    // Method to insert a value into the binary tree
    pub fn insert(&mut self, value: i32) {
        if value <= self.value {
            if let Some(ref mut left) = self.left {
                left.insert(value);
            } else {
                self.left = Some(Box::new(TreeNode::new(value)));
            }
        } else {
            if let Some(ref mut right) = self.right {
                right.insert(value);
            } else {
                self.right = Some(Box::new(TreeNode::new(value)));
            }
        }
    }

    // Method to check if a value exists in the binary tree
    pub fn contains(&self, value: i32) -> bool {
        if value == self.value {
            true
        } else if value < self.value {
            match &self.left {
                Some(left) => left.contains(value),
                None => false,
            }
        } else {
            match &self.right {
                Some(right) => right.contains(value),
                None => false,
            }
        }
    }
}

