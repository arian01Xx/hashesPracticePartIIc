#include "solutionthree.hpp"
#include "solutiontwo.hpp"
#include "solutionone.hpp"

int main(){

	vector<string> operations={"SmallestInfiniteSEt", "addBack", "popSmallest", "popSmallest",
                           "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"};
    vector<vector<int>> values={{},{2},{},{},{},{1},{},{},{}};

    SmallestInfiniteSEt* obj=nullptr;
    vector<string> output;

    for(size_t i=0; i<operations.size(); i++){
    	if(operations[i] == "SmallestInfiniteSEt"){
    		obj=new SmallestInfiniteSEt();
    		output.push_back("null");
      	}else if(operations[i] == "addBack"){
      		obj->addBack(values[i][0]);
      		output.push_back("null");
      	}else if(operations[i] == "popSmallest"){
      		int res=obj->popSmallest();
      		output.push_back(to_string(res));
      	}
    }

    cout<<"THE ANSWER IS = [";

    for(size_t i=0; i<output.size(); ++i){
    	cout<<output[i];
    	if(i<output.size()-1){
    		cout<<",";
    	}
    }
    cout<<"]"<<endl;

    delete obj;  //liberar memoria

    Solution solution;
    //dos vectores un k
    vector<int> inputOne={1,3,3,2};
    vector<int> inputTwo={2,1,3,4};
    int k=3;
    long long outputOne=solution.maxScore(inputOne, inputTwo, k);
    cout<<"ANSWER TWO ="<<outputOne<<endl;

    SolutionTwo solution2;
    vector<int> inputThree={17,12,10,2,7,2,11,20,8};
    int kk=3;
    int candidates=4;
    long long output2=solution2.totalCost(inputThree,kk,candidates);
    cout<<"ANSWER THREE ="<<output2<<endl;

	return 0;
}
