#include <iostream>
#include"queue.cpp"

using namespace std;


// struct TreeNode{
// 	int value;
// 	TreeNode *left;
// 	TreeNode *right;
// };

class bst{
public:
	bst();
	~bst();

	void insert(int key);
	TreeNode *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
	void levelorderIterative();

private:
	void destroy_tree(TreeNode *leaf);
	void insert(int key, TreeNode *leaf);
	TreeNode *search(int key, TreeNode *leaf);
	void inorder_print(TreeNode *leaf);
	void postorder_print(TreeNode *leaf);
	void preorder_print(TreeNode *leaf);
  void levelorderIterative(TreeNode *root);

	TreeNode *root;
};


bst::bst(){
	root = NULL;
}

bst::~bst(){
	destroy_tree();
}

void bst::destroy_tree(TreeNode *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void bst::insert(int key, TreeNode *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new TreeNode;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new TreeNode;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void bst::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new TreeNode;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

TreeNode *bst::search(int key, TreeNode *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

TreeNode *bst::search(int key){
	return search(key, root);
}

void bst::destroy_tree(){
	destroy_tree(root);
}

void bst::inorder_print(){
	inorder_print(root);
	cout << "\n";
}
void bst::levelorderIterative()
{
	levelorderIterative(root);
	cout<< '\n';
}

void bst::inorder_print(TreeNode *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void bst::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void bst::postorder_print(TreeNode *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void bst::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void bst::preorder_print(TreeNode *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}


void bst::levelorderIterative(TreeNode *root)
{
	// return if tree is empty
	if (root == NULL)
	   return;

	// create an empty stack and push root TreeNode
	queue q1;
	q1.enqueue(root);

	// run till stack is not empty
	while (!q1.isEmpty())
	{
		// pop a TreeNode from the stack and print it
		TreeNode *curr = q1.dequeue();
		// stack.pop();

		cout << curr->value << " ";


		// push left child of popped TreeNode to the stack
		if (curr->left)
			q1.enqueue(curr->left);

			// push right child of popped TreeNode to the stack
			if (curr->right)
				q1.enqueue(curr->right);

		// important note - right child is pushed first so that left child
		// is processed first (FIFO order)
	}
}

int main(){

	//bst tree;
	bst *tree = new bst();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();
	tree->levelorderIterative();
	delete tree;

}
