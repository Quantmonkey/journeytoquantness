#pragma once

#include <iostream>
#include <string>

#include "GenericTree.h"

static void treeFactory(GenericTree<int> &tree)
{

	tree.clear(); // getting rid of the root node

	// depth 0
	tree.createRoot(4);				// creating a root note containing "4"
	auto node4 = tree.getRootPtr(); // saving a copy of the root pointer to node4

	// depth 1
	auto node8 = node4->addChild(8);   // pushing a rightmost 8 child to node4
	auto node15 = node4->addChild(15); // pushing a rightmost 15 child to node4

	// depth 2
	auto node16 = node8->addChild(16); // pushing a rightmost 16 child to node8
	auto node23 = node8->addChild(23); // pushing a rightmost 23 child to node8

	// depth 3
	auto node42 = node16->addChild(42); //pushing a rightmost 42 child to node16
}

static void treeFactoryTest()
{
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "EXERCISE 1: treeFactoryTest" << std::endl;
	std::cout << "The output should match what you see in the code comments" << std::endl
			  << std::endl;

	GenericTree<int> tree(9999);
	treeFactory(tree);
	std::cout << tree << std::endl;
}

template <typename N>
int countNullChildrenRecursive(N *subtreeRoot)
{

	// Base case: If the root of this subtree itself is null, then return 1.
	if (!subtreeRoot)
		return 1;

	int nullChildrenSum = 0;

	// Note 1: We'll allow our definition of recursion to include a combination
	//  of looping and recursing.
	// Node 2: Since we dereference subtreeRoot below with "->", we had to make
	//  sure that it was not null first. We already handled that base case above.
	// Note 3: Instead of "auto", it also works to write "auto*" or "N*" here
	//  based on how we've set up the template. But you can't use "auto" in the
	//  function arguments list, only inside the function.

	// Iterate over the list of children and recurse on each subtree.
	for (auto childPtr : subtreeRoot->childrenPtrs)
	{

		// Increment the sum by the result of recursing on this child's subtree.
		nullChildrenSum += countNullChildrenRecursive(childPtr);
	}

	// Return the sum.
	return nullChildrenSum;
}

// countNullChildrenIterative: Given a pointer to a TreeNode, look at the
// subtree that is implicitly rooted at that node, and count how many children
// throughout the tree are null pointers. Here, templated type N should be a
// TreeNode inner type belonging to some type of GenericTree.
// (You do NOT need to edit this function.)
template <typename N>
int countNullChildrenIterative(N *subtreeRoot)
{

	int nullChildrenSum = 0;

	// Stack of node pointers that we still need to explore (constructed empty)
	std::stack<N *> nodesToExplore;

	// Begin by pushing our subtree root pointer onto the stack
	nodesToExplore.push(subtreeRoot);

	// Loop while there are still nodes to explore
	while (!nodesToExplore.empty())
	{

		// Make a copy of the top pointer on the stack, then pop it to decrease the stack
		N *topNode = nodesToExplore.top();
		nodesToExplore.pop();

		if (!topNode)
		{
			// If the top node pointer is null, then we must not dereference it.
			// Just increment the null counter, then "continue" to jump back to the top of the loop.
			nullChildrenSum++;
			continue;
		}

		// If the node exists, it may have children pointers. Let's iterate
		// through the childrenPtrs vector and push copies of those pointers
		// onto the exploration stack.
		for (auto childPtr : topNode->childrenPtrs)
		{
			nodesToExplore.push(childPtr);
		}
	}

	// Return the sum.
	return nullChildrenSum;
}

/*******************************************************************
  EXERCISE 2: Implement level-order traversal in the traverseLevels function.

  As discussed above, a level-order traversal is related to the idea of a
  breadth-first traversal. You need to implement the traverseLevels function,
  which takes a tree as input and performs a level-order traversal. Traverse
  the tree one layer at a time, visiting child nodes from left to right, while
  storing copies of the node data in level order as a std::vector. If a null
  child pointer is encountered, no data item should be appended to the results
  for that one pointer. The function should return the std::vector of result
  data in the appropriate order.

  You may implement the body of the function however you want, but you must
  not leak any memory or crash, and your function should work for any
  simple instance of GenericTree<T> (such as GenericTree<int> or
  GenericTree<std::string>). You'll find several good strategies for building
  the function throughout the source files provided with this assignment.

  ****************************************************************/

// traverseLevels: Performs a level-order traversal of the input tree
// and records copies of the data found, in order, in a std::vector,
// which should then be returned.
template <typename T>
std::vector<T> traverseLevels(GenericTree<T> &tree)
{
	// This defines a type alias for the appropriate TreeNode dependent type.
	// This might be convenient.
	using TreeNode = typename GenericTree<T>::TreeNode;

	auto rootNodePtr = tree.getRootPtr();

	// This is the results vector you need to fill.
	std::vector<T> results;

	// Placeholder queue
	std::queue<T> results_holder;

	// Stack of node pointers that we still need to explore (constructed empty)
	std::queue<TreeNode*> nodesToExplore;

	// Begin by pushing our rootNodePtr onto the stack
	nodesToExplore.push(rootNodePtr);

	// Loop while there are still nodes to explore
	while (!nodesToExplore.empty())
	{
		// Make a copy of the top pointer on the stack, then pop it to decrease the stack
		TreeNode* topNode = nodesToExplore.front();
		nodesToExplore.pop();

		if (!topNode) {
			// If the top node pointer is null, then we must not dereference it.
			// then "continue" to jump back to the top of the loop.
			continue;
		}
		else {
			results_holder.push(topNode->data);
			// If the node exists, it may have children pointers. Let's iterate
			// through the childrenPtrs vector and push copies of those pointers
			// onto the exploration stack.
			for (auto childPtr : topNode->childrenPtrs){
				nodesToExplore.push(childPtr);
			}
		}
	}

	while (!results_holder.empty()) {
		results.push_back(results_holder.front());
		results_holder.pop();
	}

	// Return
	return results;
}

// traversalTest: Runs some tests with your traverseLevels function and
// displays comparison output. (You do NOT need to edit this function.)
static void traversalTest()
{
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "EXERCISE 2: traversalTest" << std::endl;
	std::cout << "Testing your traverseLevels function" << std::endl
			  << std::endl;

	{
		// This is the tree from exampleTree1() in main.cpp
		std::cout << "[Test 1] Expected output:" << std::endl
				  << "A B E C D F G" << std::endl;
		GenericTree<std::string> tree1("A");
		auto nodeA = tree1.getRootPtr();
		auto nodeB = nodeA->addChild("B");
		nodeB->addChild("C");
		nodeB->addChild("D");
		auto nodeE = nodeA->addChild("E");
		nodeE->addChild("F");
		nodeE->addChild("G");
		std::vector<std::string> tree1_results = traverseLevels(tree1);
		std::cout << "Your traverseLevels output:" << std::endl;
		for (auto result : tree1_results)
		{
			std::cout << result << " ";
		}
		std::cout << std::endl
				  << std::endl;
	}

	{
		// This is the tree from exampleTree2() in main.cpp
		std::cout << "[Test 2] Expected output:" << std::endl
				  << "A B D J K C E I L F G M H" << std::endl;
		GenericTree<std::string> tree2("A");
		auto A = tree2.getRootPtr();
		A->addChild("B")->addChild("C");
		auto D = A->addChild("D");
		auto E = D->addChild("E");
		E->addChild("F");
		E->addChild("G")->addChild("H");
		D->addChild("I");
		A->addChild("J");
		auto L = A->addChild("K")->addChild("L");
		L->addChild("M");
		std::vector<std::string> tree2_results = traverseLevels(tree2);
		std::cout << "Your traverseLevels output:" << std::endl;
		for (auto result : tree2_results)
		{
			std::cout << result << " ";
		}
		std::cout << std::endl
				  << std::endl;
	}

	{
		// This is the tree you should have built for the first part of this
		// assignment above, with treeFactory.
		std::cout << "[Test 3] Expected output:" << std::endl
				  << "4 8 15 16 23 42" << std::endl;
		GenericTree<int> tree3(9999);
		treeFactory(tree3);
		std::vector<int> tree3_results = traverseLevels(tree3);
		std::cout << "Your traverseLevels output:" << std::endl;
		for (auto result : tree3_results)
		{
			std::cout << result << " ";
		}
		std::cout << std::endl
				  << std::endl;
	}
}
