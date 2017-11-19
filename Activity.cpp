//g++ Activity.cpp `root-config --libs --cflags` -o Activity


#include<iostream>
#include<fstream>
#include <iomanip>
//#include <TH1F.h>
//#include <TH2D.h>
#include <string>
#include <vector>
#include<math.h>
//#include "TGraph.h"
#include <cstdlib>


using namespace std;

using std::string;
using std::cin;
 

void checkArgsNumber(int argNumber)
{
  if( 3 != argNumber )
  {
      cout << "Please provide path to data file and its type" <<endl;
      cout << "Accepted file types are: charge , amplitude , riseTime , fallTime , timeDifference" <<endl;
      exit(1);
  }
}


void checkFilePath(string filePath)
{
  ifstream f(filePath.c_str());
  if( !f.good() )
  {
     cout << "Wrong path to file " << filePath <<endl;
     exit(3);
  }
}


int main(int argc, char **argv)
{
/*




	string filePath = argv[1];

	checkArgsNumber(argc);
  	checkFilePath(filePath);

    	


	//TApplication* theApp = new TApplication("App", &argc, argv);
	    
	TH2D *hist_Single = new TH2D("hist_Single","Activity",200,0,200,500,0,4000);
	//TH1F *hist_Single = new TH1F("hist_Single","Activity",200,0,200);

	double  my_Distance, my_CPS_average ;
  	vector<double> Distance;
	vector<double> CPS_average;                                // Empty Vector of Double







	ifstream input;

	//input.open("Source1.dat");
		

    //while(!input.eof())

	//    {
      	//		input>>my_Distance>>my_CPS_average ;
	//			Distance.push_back(my_Distance);
	//			CPS_average.push_back(my_CPS_average);

	//		}
	












	//TGraph *g = new TGraph(&Distance[0], &CPS_average[0]);								
  	//g->Draw("AL");
    



	



	//theApp->Run();*/
	      return 0;





}


///****************************************************************The End**************************************************///

