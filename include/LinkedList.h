/** @file LinkedList.h
 *  @brief Function prototypes and data structures for the Linked List
 *
 *  This contains all the functions and data types available to work with the LinkedList
 *
 *  @author Matthias Blomme (mblomme)
 *  @bug No known bugs.
 */
#ifndef LINKEDLIST_H_
	#define LINKEDLIST_H_

	/**
	 * @brief a pointer to a generic data type
	 */
	typedef void * T;

	/**
	 * @brief The linked list data structure
	 */
	struct _linkedList {
		void * internals; /**< The internal data and functionality, do not change this. */

		void (*display) (struct _linkedList *); /**< Displays the data structure */
		void (*clear) (struct _linkedList *); /**< Empties the list */
		void (*add) (struct _linkedList *, T); /**< Add a new item to the front of the list */
		void (*addAt) (struct _linkedList *, T, int); /**< Add a new item at a specific index */
		int (*getSize)(struct _linkedList *); /**< Returns the size of the list */
		T (*deleteItem) (struct _linkedList *, int); /**< Delete an item at a giving index */
	};

	/**
	 * @brief a pointer to a linked list
	 */
	typedef struct _linkedList * LinkedList;

	/**
	 * @brief Creates a new LinkedList
	 * @param deleteData A function pointer to a custom display data function.
	 * @param displayData A function pointer to a custom delete data function.
	 * @return A pointer to the new created Linked List.
	 */
	LinkedList newLinkedList(void (*deleteData) (T), void (*displayData) (const T));

	/**
	 * @brief Deletes the giving linked list.
	 * @param LinkedList The working list.
	 */
	void deleteLinkedList(LinkedList);

	/**
	 * @brief Add a new item to the front of the list.
	 * @param LinkedList The working list.
	 * @param T The reference to the data type.
	 */
	void add (LinkedList, T);
	
	/**
	 * @brief Gets the size of list.
	 * @param LinkedList The working linked list.
	 * @return The size of the LinkedList.
	 */
	int getSize(LinkedList);

	/**
	 * @brief Prints the whole linked list.
	 * @param LinkedList The working list.
	 */
	void display(LinkedList);

	/**
	 * @brief Frees all items of the linked list.
	 * @param LinkedList The working list.
	 */
	void freeList(LinkedList);

	/**
	 * @brief Add an item of type T at a specific index.
	 * @param LinkedList The working list.
	 * @param T The data type.
	 * @param n The index.
	 */
	void addAt(LinkedList, T, int);

	/**
	 * @brief Delete an item at a specific index.
	 * @param LinkedList the working list.
	 * @param n the index.
	 * @return A reference to the supplied data type.
	 */
	T deleteItem (LinkedList, int);

#endif
