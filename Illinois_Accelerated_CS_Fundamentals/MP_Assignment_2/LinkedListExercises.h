
/**
 * @file LinkedListExercises.h
 * University of Illinois CS 400, MOOC 2, Week 1: Linked List
 * Spring 2019
 *                        STUDENT STARTER FILE
 *
 * @author Eric Huber - University of Illinois staff
 *
**/

/********************************************************************
	Week 1: Linked List and Merge Sort Exercises

	There are two exercises in this file. Please read the code comments
	below and see the provided instructions PDF before you begin. The
	other provided code files in the starter zip also contain important
	comments and hints about how to approach this.

	This is the only file you can edit for the sake of grading! You can
	edit the other provided starter files for testing purposes, but the
	autograder will assume that this is the only file that has been edited
	by you, and the others will be replaced with the original intended
	versions at grading time.
 ********************************************************************/

// Prevent the header from being included more than once per cpp file
#pragma once

// It's good to put system headers first, so that if your own libraries
// cause conflicts, the compiler will most likely identify the problem
// as being in your own source code files, where it arises later.
#include <iostream>
#include <string>

#include "LinkedList.h"

/********************************************************************
	Exercise 1: insertOrdered

	This LinkedList member function assumes that the current contents
	of the list are already sorted in increasing order. The function
	takes as input a new data item to be inserted to the same list.
	The new data item should be inserted to the list in the correct
	position, so that you preserve the overall sorted state of the list.

	For example, if your LinkedList<int> contains:
	[1, 2, 8, 9]
	And the input is 7, then the list should be updated to contain:
	[1, 2, 7, 8, 9]

	To be more precise, a new node should be created on the heap, and
	it should be inserted in front of the earliest node in the list that
	contains a greater data element. If no such other node exists, then
	the new item should be placed at the end (the back of the list).

	Also, be sure to update the size_ member of the list appropriately.

	Your implementation of this function should not change the memory
	locations of the existing nodes. That is, you should not push or pop
	the existing elements of the list if it would change their address.
	(The member functions for push and pop will add a new node or delete
	one, so these operations would not leave the original node in place
	even if you recreated the node with equivalent data.) You should use
	pointers to connect your new node at the correct insertion location,
	being sure to adjust the list's head and tail pointers if necessary,
	as well as any prev or next pointers of adjacent nodes in the list.
	Remember: LinkedList is a doubly-linked list. That means each node
	also refers to the previous item in the list, not just the next item.

	A correct implementation of this function has O(n) time complexity
	for a list of length n. That is, in the worst case, you would
	traverse each element of the list some constant number of times.

	You can use "make test" followed by "./test" to check the correctness
	of your implementation, and then you can use "./test [.bench]" to run
	some interesting benchmarks on the speed of your code.

 ********************************************************************/

template <typename T>
void LinkedList<T>::insertOrdered(const T& newData) {

	// Creating a new node that exists on the heap and returns memory address
	// to new_data_node pointer
	Node *new_data_node = new Node;
	// Using -> to access the member function of Node through new_data_node
	// pointer, and adjusting the public data to newData (passed by reference)
	new_data_node->data = newData;
	// Setting the next pointer to NULL so no memory leakage
	new_data_node->next = NULL;
	// Setting the previous pointer to NULL so no memory leakage
	new_data_node->prev = NULL;

	// Checking if the head returns NULL, representing an empty list
	// Setting the head_ pointer to the new data node
	// Setting the tail_ pointer tot the new data node
	if (getHeadPtr() == NULL) {
		head_ = new_data_node;
		tail_ = new_data_node;
	}

	// If the value of the node to be inserted is smaller 
	// than the value of the head node, then insert the node 
	// at the start and make it head.
	else if (head_->data >= new_data_node->data) {
		new_data_node->next = head_;
		new_data_node->prev = nullptr;  
		head_->prev = new_data_node;
		head_ = new_data_node;  
	}

	else if (tail_->data <= new_data_node->data) {
		new_data_node->next = nullptr;
		new_data_node->prev = tail_;
		tail_->next = new_data_node;
		tail_ = new_data_node;
	}

	else {
		// Creates a Node pointer called current that is pointing at head node
		Node* cur = head_;
		// While the current pointer's node's next pointer is not null and
		// the current pointer's next node's data is less than the new data
		// the pointer will point to the node's next pointer's node
		while (cur->next != NULL && cur->next->data < new_data_node->data) {
			cur = cur->next;
		}
		// The new data's nodes next pointer will point at cur's next pointer's node
		new_data_node->next = cur->next;
		new_data_node->prev = cur;
		// cur's next pointer's node will point at 
		cur->next->prev = new_data_node;
		cur->next = new_data_node;
	}

	size_++;
}

/********************************************************************
	Exercise 2: Linear-time Merge

	This LinkedList member function is intended to perform the classic
	"merge" operation from the mergesort algorithm. It combines two sorted
	lists into a single sorted list. This algorithm is intended to run
	in linear time (that is, O(n) where n is the total number of elements
	in the input lists), so it is not appropriate to simply concatenate
	the two lists and then apply a sorting algorithm. Instead, the merge
	algorithm relies on the fact that the two input lists are already sorted
	separately in order to create the merged, sorted list in linear time.

	One of the implied input lists is the "*this" LinkedList instance that
	is calling the function, and the other input list is explicitly specified
	as the function argument "other". The function does NOT change either
	of the original lists directly, as the inputs are marked const.
	Instead, this function makes a new list containing the merged result,
	and it returns a copy of the new list. For example, one usage might be:

	LinkedList<int> leftList;
	// [... Add some sorted contents to leftList here. ...]
	LinkedList<int> rightList;
	// [... Add some sorted contents to rightList here. ...]
	LinkedList<int> mergedList = leftList.merge(rightList);

	You may assume that the two input lists have already been sorted.
	However, the lists may be empty, and they may contain repeated or
	overlapping elements. The lists may also have different lengths.
	For example, it's possible that these are the two input lists:

	Left list: [1, 2, 2, 3, 5, 5, 5, 6]
	Right list: [1, 3, 5, 7]

	And the result of merging those two sorted lists will contain all
	of the same elements, including the correct number of any duplicates,
	in sorted order:
	[1, 1, 2, 2, 3, 3, 5, 5, 5, 5, 6, 7]

	Because your implementation of this function operates on const inputs
	and returns a newly created list, you do not need to maintain the
	previous memory locations of any nodes as required in Exercise 1.
	You may need to make non-const "working copies" of the const input lists
	if you wish. You may approach this problem either iteratively or
	recursively, and you may use the member functions of the LinkedList class
	to make it simpler (such as push and pop), or you may edit the contents
	of lists explicitly by changing the pointers of a list or of its nodes
	(such as head_, tail_, next, and prev).

	Be sure that the size_ member of the resulting list is correct.

	A correct implementation of this function has O(n) time complexity
	for a list of length n. That is, in the worst case, you would
	traverse each element of the list some constant number of times.

	You can use "make test" followed by "./test" to check the correctness
	of your implementation, and then you can use "./test [.bench]" to run
	some interesting benchmarks on the speed of your code.

 ********************************************************************/

template <typename T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& other) const {

	LinkedList<T> left = *this;
	LinkedList<T> right = other;
	LinkedList<T> merged;

	Node* left_cur = left.head_;
	Node* right_cur = right.head_;

	// Iterates through both of them if both of them are not empty
	while (left_cur != NULL && right_cur != NULL) {
		// If data in left is smaller or equal to data in right
		// Pop out that data in left

		if (left_cur->data <= right_cur->data) {
			merged.pushBack(left_cur->data);
			left_cur = left_cur->next;
		}
		// Means data in right is smaller than data in left
		// Pop out that data once its copied to merge
		else {
			merged.pushBack(right_cur->data);
			right_cur = right_cur->next;
		}
	}

	// Either left is empty or right is empty
	// Left specifically now
	// While left is still not yet empty, push left_cur's data into merged
	// Pop that data from left & iterate next

	if (left.head_ <= left.tail_ && left_cur != NULL) {
	while (left_cur != NULL) {
		merged.pushBack(left_cur->data);
		left_cur = left_cur->next;
		}
	}

	else if (left.tail_ < left.head_ && left_cur != NULL) {
		left_cur = left.tail_;
		while (left_cur != NULL) {
			merged.pushFront(left_cur->data);
			left.popBack();
			left_cur = left_cur->prev;
		}
	}

	// It means left is empty
	// Refer to left doc
	if (right.head_ <= right.tail_ && right_cur != NULL) {
		while (right_cur != NULL) {
			merged.pushBack(right_cur->data);
			right_cur = right_cur->next;
		}
	}

	else if (right.tail_ < right.head_ && right_cur != NULL) {
		right_cur = right.tail_;
		while (right_cur != NULL) {
			merged.pushFront(right_cur->data);
			right_cur = right_cur->prev;
		}
	}
	

	return merged;
}

