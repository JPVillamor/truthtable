/*
input a logical expression
based on number of variables
a truth table will be generated

method 1: expression tree with
logical operators as parent nodes.
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class Node {
private:
	char symbol;			//represents logical op or proposition
	bool truth_val;
	Node *left, *right;
public:
	Node(char c, bool b, Node *l, Node *r);
	char get_symbol() { return symbol; }
	bool get_val() { return truth_val; }
	Node *get_left() { return left; }
	Node *get_right() { return right; }
	void set_symbol(char c) { symbol = c; }
	void set_val(bool table_val) { truth_val = table_val; }
	void set_left(Node *l) { left = l; }
	void set_right(Node *r) { right = r; }

	bool operator*(Node);	//and
	bool operator+(Node); 	//or
	bool operator-(Node);	//not
	bool operator/(Node); 	//xor
	bool operator>(Node);	//implies
	bool operator&(Node);	//biconditional
};

bool Node::operator*(Node operand) {
	return truth_val && operand.truth_val;
}

bool Node::operator+(Node operand) {
	return truth_val || operand.truth_val;
}

bool Node::operator-(Node operand) {
	return !operand.truth_val;
}

bool Node::operator/(Node operand) {
	if (truth_val == true && operand.truth_val == false)
		return true;
	else if (truth_val == false && operand.truth_val == true)
		return true;
	else
		return false;
}

bool Node::operator>(Node operand) {
	if (truth_val == true && operand.truth_val == false)
		return false;
	else 
		return true;
}

bool Node::operator&(Node operand) {
	return truth_val == operand.truth_val;
}

class Tree {
private:
	Node *root;
public:
	Tree() { root = NULL; }
	//inserting method
	//calculation method 
};

class Truth_Table {
private:
	vector<char> propositions;
	int prop_size;
	int rows;				//2^(number of propositions)
	vector< vector<bool> > table;
public:
	void set_propositions(string expression);
	void set_prop_size(int n) { prop_size = n; }
	void set_rows(int n) { rows = n; }

	int get_prop_size() { return prop_size; }
	int get_rows() { return rows; }

	//create t/f table values
	void generate_table_vals(vector<char> propositions, int rows);	
	
	//calculate the outcomes of the expression using the etree
	void generate_final_col(Tree);
	
	void print();
};

void Truth_Table::set_propositions(string expression) {
	string logical_ops = "*+-/>&";
	string not_ops = "";

	for (int i = 0; i < expression.length(); i++) {
		if ( logical_ops.find(expression[i]) == -1 && 
		not_ops.find(expression[i]) == -1 )
			not_ops += expression[i];
	}

	for (int i = 0; i < not_ops.length(); i++) {
		propositions.push_back(not_ops[i]);
	}
}

int main() {
	Truth_Table t;

	t.set_prop_size(4);
	int r = pow(2, t.get_prop_size());
	t.set_rows(r);
	
	cout << t.get_rows() << endl;

	return 0;
}
