mod binary_tree;
use binary_tree::TreeNode;

fn main() {
  let mut root = TreeNode::new(5);
  root.insert(3);
  root.insert(7);
  root.insert(2);
  root.insert(4);
  root.insert(6);
  root.insert(8);

  println!("Does the tree contain 4? {}", root.contains(4));
  println!("Does the tree contain 9? {}", root.contains(9));
}
