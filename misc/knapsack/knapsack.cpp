#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Another helper
int minWeight(const vector<int>& weights){
  int min = weights[0];
  for(unsigned int i=1; i < weights.size(); i++){
    if(weights[i] < min) min = weights[i];
  }
  return min;
}

void helper(int remain, vector<int>& weights, vector<int>& ks, int min){
  if(remain < min){
    cout << "Knapsack full. Remain= " << remain << " : ";
    for(int i=0; i< ks.size(); i++){
      cout << ks[i] << " ";
    }
    cout << endl;
  }
  else{
    for(int i=0; i< weights.size(); i++){
      if(weights[i] <= remain){ //does object fit
        ks.push_back(weights[i]); //add item
        helper(remain - weights[i], weights, ks, min); //recurse
        ks.pop_back(); //remove item
      }
    }
  }
}


// client interface
void genOptions(int limit, vector<int >& weights)
{
  vector<int> knapsack;
  int min = minWeight(weights);
  helper(limit, weights, knapsack, min);


}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./knapsack weight_limit [item_weights]" << endl;
  }
  int limit;
  limit = atoi(argv[1]);
  vector<int> weights;
  for(int i=2; i < argc; i++){
    weights.push_back(atoi(argv[i]));
  }
  genOptions(limit, weights);
  return 0;
}
  
