#include <iostream>

using namespace std;

#include "animals.h"

/*
 * tsearch.cpp -- search the animal game data tree for info
 *  compile this and link with animals.o:
 *
 *   g++ -Wall -Wextra -o tsearch.o tsearch.cpp -c
 *   g++ -o ts tsearch.o animals.o
 *
 * hist: 
 *	2012-04-25 replaced cin >> findme with getline call for sea lion
 */

int count_all_nodes     (Node *tree);
int count_animals       (Node *tree);
void print_animals      (Node *tree);
int count_questions     (Node *tree);
int length_longest_path (Node *tree);
int length_shortest_path(Node *tree);
bool is_in_tree         (Node *tree, string findme);
void print_path_from    (Node *tree, string findme);

int main()
{
	Node *tree;
	string findme;

	tree = make_tree();

	cout << "Total nodes: "   << count_all_nodes(tree) << endl;
	cout << "Total animals: " << count_animals(tree)   << endl;
	cout << "List of animals\n";
	print_animals(tree);

	cout << "Total questions: " << count_questions(tree) << endl;
	cout << "Max depth: "       << length_longest_path(tree) << endl;
	cout << "Min depth: "       << length_shortest_path(tree) << endl;

	cout << "Find what animal? ";
	getline(cin, findme);

	if (is_in_tree(tree, findme)) {
		cout << "Found at " << endl;
		print_path_from(tree, findme);
	} else {
		cout << "not in tree\n";
	}
	return 0;
}

//
// purp: count the number of nodes in the tree
// args: ptr to root of tree
// rets: number of nodes at and below that node
// base: a root of NULL returns 0
//
int count_all_nodes(Node *tree)
{
        int counter = 0;
        if (tree == NULL) {
                return counter;
        }
        counter += 1;
        counter += count_all_nodes(tree->yes);
        counter += count_all_nodes(tree->no);
        return counter;
}

//
// purp: count the number of animal nodes in the tree
// args: ptr to root of tree
// rets: number of animal nodes at and below that node
// base: a root of NULL returns 0
//
int count_animals(Node *tree)
{
        if (tree == NULL) {
                return 0;
        }
        if (tree->yes == NULL && tree->no == NULL) {
                return 1;
        }
        return count_animals(tree->yes) + count_animals(tree->no);
}

//
// purp: print the names of all the animals stored in the tree
// args: ptr to root of tree
// rets: nothing
// outp: prints each animal name on a separate line
//
void print_animals(Node *tree)
{
	if (tree == NULL) {
                return;
        }
        if (tree->yes == NULL && tree->no == NULL) {
                cout << animal << endl;
        }
        print_animals(tree->yes);
        print_animals(tree->no);
}

//
// purp: count the number of question nodes in the tree
// args: ptr to root of tree
// rets: number of question nodes at and below that node
// base: a root of NULL returns 0
//
int count_questions(Node *tree)
{
        if (tree == NULL) {
                return 0;
        }
        if (tree->yes != NULL && tree->no != NULL) {
                return 1;
        }
        return count_questions(tree->yes) + count_questions(tree->no);
}

//
// length_longest_path
// purp: determine the length of the longest sequence of questions
// args: ptr to root of tree
// rets: the length of the longest sequence of questions
//
int length_longest_path(Node *tree)
{
        if (tree == NULL) {
                return 0;
        }
        if (tree->yes != NULL && tree->no != NULL) {
                return 1 + length_longest_path(tree->yes) +
                        length_longest_path(tree->no);
        }
        return 0;
}

//
// length_shortest_path
// purp: determine the length of the shortest sequence of questions
// args: ptr to root of tree
// rets: the length of the longest sequence of questions
//
int length_shortest_path(Node *tree)
{
        if (tree == NULL) {
                return 0;
        }
        if (tree->yes == NULL && tree->no == NULL) {
                return 0;
        }
        return 1 + length_shortest_path(tree->yes) +
                length_shortest_path(tree->no);
}

//
// is_in_tree
// purp: determine if a string is an animal in the tree
// args: ptr to root of tree, name of animal
// rets: true if found, false if not
//
bool is_in_tree(Node *tree, string findme)
{
        if (tree == NULL) {
                return false;
        }
        if (tree->yes == NULL && tree->no = NULL) {
                if (tree->animal == findme) {
                        return true;
                } else {
                        return false;
                }
        }
        return is_in_tree(tree->yes, findme) + is_in_tree(tree->no);
}

//
// print_path_from
// purp: print the list of questions that leads to an animal
// args: ptr to root of tree, name of animal
// rets: nothing
// outp: one question per line, in reverse order of being asked
//       that is, the most specific question first, most general last
//
void print_path_from(Node *tree, string findme)
{
        if (tree == NULL) {
                return;
        }
        
}