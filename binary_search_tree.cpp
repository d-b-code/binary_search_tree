//pc1 Douglass A Belley SDEV WEEK 14

#include <iostream>
#include <vector>

using namespace std;
//class definitions
class DoubleBinTree {
private:
	class TreeNode {
		friend class DoubleBinTree;
		double value;
		TreeNode* right;
		TreeNode* left;
		TreeNode(double value1, TreeNode* left1 = NULL, TreeNode* right1 = NULL)
		{
			value = value1;
			left = left1;
			right = right1;
		}

	};
	//private functions
	TreeNode* root;
	void insert(TreeNode *&, double x);
	bool search(double, TreeNode *);
	void putInOrder(vector<double>& v, TreeNode* tree);
public: 
	//constructor and public interface
	DoubleBinTree()
	{		root = NULL;	}

	void insert(double x) {
		insert(root, x);}
	bool search(double x) { 
		return search(x, root);}
	void inOrder(vector <double> & v)  {
		{putInOrder(v, root);}
}
};
//function definitions and logic
void DoubleBinTree:: insert(TreeNode*& tree, double x) {
	if (!tree) {
		tree = new TreeNode(x);
		return;
	}
	if (tree->value == x) {
		return;
	}
	if (x < tree->value) {
		insert(tree->left, x);
	}
	else {
		insert(tree->right, x);
	};
};

bool DoubleBinTree::search(double x, TreeNode* t) {
	while (t) {
		if (t->value == x) 
			return true;
		
		else if (x < t->value) 
			return search(x, t->left);
		
		else 
			return search(x, t->right);
		
		
	}
	return false;
};

void DoubleBinTree::putInOrder(vector <double> & v, TreeNode * tree)
	{
		if (tree)
		{
			putInOrder(v, tree->left);
			v.push_back(tree->value);
			putInOrder(v, tree->right);
		}
	};
//driver program
int main() {

	DoubleBinTree tree;
	vector<double> values;


	tree.insert(2.3);
	tree.insert(4.5);
	tree.insert(1.9);
	tree.insert(9.7);
	tree.insert(8.8);
	tree.inOrder(values);

	if (tree.search(8.8)) {
		cout << "8.8 was found in the tree\n";
	}
	else {
		cout << "8.8 was not found in the tree\n";
	}	
	if (tree.search(5.8)) {
		cout << "5.7 was found in the tree\n";
	}
	else {
		cout << "5.7 was not found in the tree\n";
	}
	cout << "Values of the tree in order: ";
	for (int i = 0; i < values.size(); i++)
	{
		cout << values[i] << "  ";
	}
	cout << endl;



	return 0;
}