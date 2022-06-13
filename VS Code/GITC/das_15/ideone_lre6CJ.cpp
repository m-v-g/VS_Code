#include <iostream>
#include <cstdlib>

struct Tree {
	int   val;
	Tree* left;
	Tree* right;
};

Tree* InsertNode(Tree* node, int val);
void  PrintNode(std::ostream& _out, const Tree* node);
void  ClearNode(Tree* node);


//удаление
Tree* DeleteNode(Tree* node, int val){
	if(node == NULL)
		return node;

	if(val == node->val){

		Tree* tmp;
		if(node->right == NULL)
			tmp = node->left;
		else {

			Tree* ptr = node->right;
			if(ptr->left == NULL){
				ptr->left = node->left;
				tmp = ptr;
			} else {

				Tree* pmin = ptr->left;
				while(pmin->left != NULL){
					ptr  = pmin;
					pmin = ptr->left;
				}
				ptr->left   = pmin->right;
				pmin->left  = node->left;
				pmin->right = node->right;
				tmp = pmin;
			}
		}

		delete node;
		return tmp;
	} else if(val < node->val)
		node->left  = DeleteNode(node->left, val);
	else
		node->right = DeleteNode(node->right, val);
	return node;
}


int main(void){
	Tree* tree = NULL;
	for(int i = 0; i < 20; ++i)
		tree = InsertNode(tree, std::rand() % 10);
	
	PrintNode(std::cout, tree);
	std::cout << std::endl;

	tree = DeleteNode(tree, 5);
	tree = DeleteNode(tree, 2);
	tree = DeleteNode(tree, 9);
	
	PrintNode(std::cout, tree);
	ClearNode(tree);
	return 0;
}


//вставка
Tree* InsertNode(Tree* node, int val){
	if(node == NULL){
		node = new (std::nothrow) Tree();
		if(node != NULL){
			node->val  = val;
			node->left = node->right = NULL;
		}
		return node;
	}

	if(val < node->val)
		node->left  = InsertNode(node->left, val);
	else
		node->right = InsertNode(node->right, val);
	return node;
}

//печать
void PrintNode(std::ostream& _out, const Tree* node){
	if(node != NULL){
		if(node->left != NULL)
			PrintNode(_out, node->left);

		_out << node->val << ' ';

		if(node->right != NULL)
			PrintNode(_out, node->right);
	}
}

//удаление всего
void ClearNode(Tree* node){
	if(node != NULL){
		if(node->left != NULL)
			ClearNode(node->left);
		if(node->right != NULL)
			ClearNode(node->right);
		delete node;
	}
}