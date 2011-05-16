#include "circuitParser.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(){
  Circuit *c = parseCircuit("testCircuits/huge.tfc");
  cout << "QCost: " << c->QCost() << endl;
  cout << "Line Names: " ;
  for(int i = 0; i < c->numLines(); i++){
    cout << c->getLine(i)->lineName << " ";
  }
  cout << endl << "Inputs: ";
  for(int i = 0; i < c->numLines(); i++){
    cout << c->getLine(i)->getInputLabel() <<  " ";
  }
  cout << endl << "Outputs: ";
  for(int i = 0; i < c->numLines(); i++){
    cout << c->getLine(i)->getOutputLabel() << " ";
  }
  cout << endl;
  for(int i = 0; i < c->numGates(); i++){
    cout << "Gate Name: "<< c->getGate(i)->name << " ";
    cout << " Controls: ";
    for(int j = 0; j < c->getGate(i)->controls.size(); j++){
      cout << " " <<c->getGate(i)->controls.at(j).wire;
    }
    cout << " Targets: ";
    for(int j = 0; j < c->getGate(i)->targets.size(); j++){
      cout << " " << c->getGate(i)->targets.at(j);
		cout << endl;
    }
	}	
	vector<int> pLines = c->getParallel();
	cout << endl << "Number of pLines: "<< pLines.size();
	cout << endl << "Paralellism lines:";
  for(int j = 0; j < pLines.size(); j++){
    cout << " " << pLines.at(j);
  }
	cout << endl;
	//makepicture (c);
  return 0;
}
