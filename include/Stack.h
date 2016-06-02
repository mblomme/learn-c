/** @file Stack.h
 *  @brief Function prototypes and data structures for the Stack
 *
 *  This contains all the functions and data types available to work with the Stack
 *
 *  @author Matthias Blomme (mblomme)
 *  @bug No known bugs.
 */
#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_

	/**
	 * @brief generic data type T
	 */
	typedef void * T;

	/**
	 * @brief The Stack data structure
	 */
	struct _stack {
		void * internals; /**< The internal working of the stack, do not modify this */

		void (*push)(struct _stack *, T); /**< Push a new item on top of the stack */

		T (*pop)(struct _stack *); /**< Gets the top item of the stack */

		void (*display)(struct _stack *); /**< Prints out the stack data structure */

		int (*getSize)(struct _stack *); /**< Get the size of the data structure */
	};

	/**
	 * @brief The Stack data structure
	 */
	typedef struct _stack * Stack;

	/**
	 * @brief Returns a pointer to a new created Stack.
	 * @param deleteData A custom delete function, to delete the stacks items.
	 * @param displayData A custom display function to print out an item of the Stack.
	 * @return A pointer to the struct _stack
	 */
	Stack newStack(void (*deleteData) (T), void (*displayData) (const T));

	/**
	 * @brief Rushes a new item T on top of the Stack.
	 * @param Stack The working stack.
	 * @param T The supplied data.
	 */
	void push(Stack, T);

	/**
	 * @brief Removes the top item of the stack and return a reference to the removed item.
	 * @param Stack The working stack.
	 * @return A reference to the removed item.
	 */
	T pop(Stack);

	/**
	 * @brief Prints out the Stack data structure.
	 * @param Stack The working stack.
	 */
	void displayStack (Stack);

	/**
	 * @brief Get the size of the Stack.
	 * @param Stack The working stack.
	 * @return The size of the Stack.
	 */
	int count(Stack);

	/**
	 * @brief Delete the complete Stack and free the reference.
	 * @param Stack The working stack.
	 */
	void deleteStack(Stack);

#endif /* INCLUDE_STACK_H_ */
