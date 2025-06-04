#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

void testProvidedExample() {
	std::cout << "=== Provided Example Test ===" << '\n';

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << '\n';
	mstack.pop();
	std::cout << mstack.size() << '\n';
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << '\n';
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << '\n';
}

void testListComparison() {
	std::cout << "=== List Comparison Test ===" << '\n';

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << '\n';
	lst.pop_back();
	std::cout << lst.size() << '\n';
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << '\n';
		++it;
	}

	std::cout << '\n';
}

void testReverseIterators() {
	std::cout << "=== Reverse Iterator Test ===" << '\n';

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i) mstack.push(i);

	std::cout << "Forward iteration: ";
	for (auto it = mstack.begin(); it != mstack.end(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << "Reverse iteration: ";
	for (auto it = mstack.rbegin(); it != mstack.rend(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << '\n';
}

void testConstIterators() {
	std::cout << "=== Const Iterator Test ===" << '\n';

	MutantStack<std::string> mstack;
	mstack.push("Hello");
	mstack.push("World");
	mstack.push("!");

	const MutantStack<std::string>& const_ref = mstack;

	std::cout << "Const forward iteration: ";
	for (auto it = const_ref.begin(); it != const_ref.end(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << "Const reverse iteration: ";
	for (auto it = const_ref.rbegin(); it != const_ref.rend(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << '\n';
}

void testCopyAndAssignment() {
	std::cout << "=== Copy and Assignment Test ===" << '\n';

	MutantStack<int> original;
	for (int i = 10; i <= 30; i += 10) original.push(i);

	MutantStack<int> copy_constructed(original);
	MutantStack<int> copy_assigned;
	copy_assigned = original;

	std::cout << "Original: ";
	for (auto it = original.begin(); it != original.end(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << "Copy constructed: ";
	for (auto it = copy_constructed.begin(); it != copy_constructed.end(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << "Copy assigned: ";
	for (auto it = copy_assigned.begin(); it != copy_assigned.end(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << '\n';
}

void testWithDifferentContainer() {
	std::cout << "=== Different Container Test (vector) ===" << '\n';

	MutantStack<int, std::vector<int>> mstack;
	mstack.push(100);
	mstack.push(200);
	mstack.push(300);

	std::cout << "Vector-based MutantStack: ";
	for (auto it = mstack.begin(); it != mstack.end(); ++it) std::cout << *it << " ";
	std::cout << '\n';

	std::cout << "Size: " << mstack.size() << '\n';
	std::cout << "Top: " << mstack.top() << '\n';

	std::cout << '\n';
}

int main() {
	testProvidedExample();
	testListComparison();
	testReverseIterators();
	testConstIterators();
	testCopyAndAssignment();
	testWithDifferentContainer();

	return 0;
}