#include "binary_trees.h"
#include <stdlib.h>


/**
 * find_root - finds the root node of the tree
 *
 * @node: a pointer to a node in the tree
 * Return: root node
 */
binary_tree_t *find_root(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (node);
	return (find_root(node->parent));
}

/**
 * findLCA - helper function to find the lowest common ancestor
 * @root: pointer to the root node
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the LCA
 */
binary_tree_t *findLCA(binary_tree_t *root, const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *leftLCA;
	binary_tree_t *rightLCA;

	/* Base case */
	if (root == NULL)
		return (NULL);

	/* if either first or second matches with root, report */
	/* the presence by returning root */
	if (root == first || root == second)
		return (root);

	/* Look for first or second in left and right subtrees */
	leftLCA = findLCA(root->left, first, second);
	rightLCA = findLCA(root->right, first, second);

	/* If both of the above calls return Non-NULL, then one */
	/* key is present in once subtree and other is present */
	/* in other, so this node is the LCA */
	if (leftLCA && rightLCA)
		return (root);

	/* Otherwise check if left subtree or right subtree is LCA */
	return ((leftLCA != NULL) ? leftLCA : rightLCA);
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *root;

	if ((first == NULL) || (second == NULL))
		return (NULL);

	root = find_root((binary_tree_t *)first);

	return (findLCA(root, first, second));
}
