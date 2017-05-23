#ifndef NNET_H
#define NNET_H
typedef struct node{
	int* w;//weight multipliers
	int t;//trigger threshold
	int value;
	int triggered;
}node;
class Nnet{
public:
//setup functions
	Nnet(int inputCount, int dataRows, int dataColumns, int outputCount);
	~Nnet();
	void wireIn(int idx, int* sensor);
	void wireOut(int idx, int* effector);
//running functions
	void eval();
//training and status functions
	int currentSize = 0;//modify as you add and free and compare sizes on cloning.
	Nnet* clone();
	void modify(double percent);
private:
//running functions
	void readInputs();
	void evaluateAllRows();
	void evaluateRow(int idx);
	void writeOutputs();
//inputs
	int inputCount;

	int** inputs;
	node* inputNodes;
//intermediate nodes
	int dataRows;
	int dataColumns;
	node** data;
//outputs
	int outputCount;

	node* outputNodes;
	int** outputs;

/*	FIXME IMPLEMENT
	int* memory;//doesnt require anything extra. Is just wired to both the input and the output.//is zeroed in clones or saves.//zero periodically to ensure compat with clones???
*/
};
#endif
