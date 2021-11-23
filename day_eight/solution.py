class Node:
    def __init__(self, data, left=None, right=None):
        self.left = left
        self.right = right
        self.data = data


def count_unival_trees(node):
    try:
        if node.left is None and node.right is None:
            return True, 1, node.data
    except AttributeError:
        return True, 0, None

    if node.left is None:
        left_tree_is_unival = True
        left_unival_trees_count = 0
        left_val = node.data
    else:
        left_tree_is_unival, left_unival_trees_count, left_val = count_unival_trees(
            node.left
        )

    if node.right is None:
        right_tree_is_unival = True
        right_unival_trees_count = 0
        right_val = node.data
    else:
        right_tree_is_unival, right_unival_trees_count, right_val = count_unival_trees(
            node.right
        )
    if (
        left_tree_is_unival
        and right_tree_is_unival
        and (left_val == node.data)
        and (right_val == node.data)
    ):
        return True, left_unival_trees_count + right_unival_trees_count + 1, node.data
    return False, left_unival_trees_count + right_unival_trees_count, node.data


if __name__ == "__main__":
    root = Node(0, left=Node(1), right=Node(0, Node(1, Node(1)), Node(0)))
    print(count_unival_trees(root))
