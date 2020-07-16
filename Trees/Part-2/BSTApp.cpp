#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>

#include "BinarySearchTree.cpp"
#include "AvlTree.cpp"

using namespace std;
using namespace std::chrono;

const bool DUMP = false;

/**
 * Run the test with a binary search tree.
 */
void testBST();

/**
 * Run the test with an AVL tree.
 */
void testAVL();

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param N size of the tree
 */
void buildTree(BinarySearchTree& tree, int N);

/**
 * search operation for binary tree
 * @param tree tree itself
 * @param N tree size
 */
void search(BinarySearchTree& tree, int N);

/**
 * display stats
 * @param tree tree itself
 */

void display_stats(BinarySearchTree& tree);

/**
 * Main.
 */
int main( )
{
    testBST();
    testAVL();
}

void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree  bst;
    
    for (int N = 5000; N <= 50000; N += 5000)
    {
        cout << "--------------------------------------------------------------------------------------------" << endl;
    	cout << "N = " << N << endl;
    	cout << "--------------------------------------------------------------------------------------------" << endl;
		cout << "---------" << endl;
		cout << "INSERTION" << endl;
		cout << "---------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"<< setw(50) << "ELAPSED TIME" << endl;

		bst.reset();
		buildTree(bst, N);

		cout << "------" << endl;
		cout << "SEARCH" << endl;
		cout << "------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"<< setw(50) << "ELAPSED TIME" << endl;

		bst.reset();
		search(bst, N);
    }
    
}

void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree avl;

    for (int N = 5000; N <= 50000; N += 5000)
    {
        cout << "--------------------------------------------------------------------------------------------" << endl;
    	cout << "N = " << N << endl;
    	cout << "--------------------------------------------------------------------------------------------" << endl;
		cout << "---------" << endl;
		cout << "INSERTION" << endl;
		cout << "---------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"<< setw(50) << "ELAPSED TIME" <<  endl;

		avl.reset();
		buildTree(avl, N);

		cout << "------" << endl;
		cout << "SEARCH" << endl;
		cout << "------" << endl << endl;
		cout << "PROBE COUNTS" << setw(30) << "COMPARE COUNTS"<< setw(50) << "ELAPSED TIME" << endl;

		avl.reset();
		search(avl, N);
    }

}

void buildTree(BinarySearchTree& tree, int N)
{
    srand(time(NULL));

    for (int i = 1; i < N; i++)
    {
        int val = rand() % N;

        steady_clock::time_point start_time = steady_clock::now();

        tree.insert(val);

        steady_clock::time_point end_time = steady_clock::now();
        tree.increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
    }

    display_stats(tree);
}

void search(BinarySearchTree& tree, int N)
{
    srand(time(NULL));

    for (int i = 1; i < N; i++)
    {
        int val = rand() % N;

        steady_clock::time_point start_time = steady_clock::now();

        tree.contains(val);

        steady_clock::time_point end_time = steady_clock::now();
        tree.increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
    }

    display_stats(tree);
}

void display_stats(BinarySearchTree& tree)
{
    cout << tree.get_probe_count() << setw(30) << tree.get_comparison_count() << setw(50) << tree.get_elapsed_time() << "ms" << endl;
    cout << endl;
}