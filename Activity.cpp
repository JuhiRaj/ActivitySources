//g++ Activity.cpp `root-config --libs --cflags` -o Activity


#include<iostream>
#include<fstream>
#include <iomanip>
#include <TH1F.h>
#include <TH2D.h>
#include <TApplication.h>
#include <string>
#include <vector>
#include<math.h>
#include "TGraph.h"


using namespace std;

using std::string;
using std::cin;
 



int main(int argc, char **argv)
{


//*************************************************Initialization**********************************************************//


    	TApplication* theApp = new TApplication("App", &argc, argv);
	    
	TH2D *hist_Single = new TH2D("hist_Single","Activity",200,0,200,500,0,4000);
	//TH1F *hist_Single = new TH1F("hist_Single","Activity",200,0,200);

	double  my_Distance, my_CPS_average ;
  	std::vector<double> Distance;
	std::vector<double> CPS_average;                                // Empty Vector of Double

//***********************************************Read Input File***********************************************************//

	ifstream input;

	input.open("Source1.dat");
		

    while(!input.eof())

	    {
      			input>>my_Distance>>my_CPS_average ;
				Distance.push_back(my_Distance);
				CPS_average.push_back(my_CPS_average);

			}
	
///**********************************************Calculate Activity**********************************************************///









///***********************************************Plot the Required Graphs****************************************************///

	TGraph *g = new TGraph(dim, &Distance[0], &CPS_average[0]);								
  	g->Draw("AL");
    



	



	theApp->Run();
	      return 0;





}

///****************************************************************The End**************************************************///

