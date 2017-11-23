//g++ Activity.cpp `root-config --libs --cflags` -o Activity


#include <iostream>
#include <fstream>
#include <iomanip>
#include <TH1F.h>
#include <TH2D.h>
#include <string>
#include <vector>
#include <math.h>
#include "TGraphErrors.h"
#include <cstdlib>
#include <TCanvas.h>
#include <TAttMarker.h>
#include "TF1.h"
using namespace std;

using std::string;
using std::cin;
 

void checkArgsNumber(int argNumber)
{
  if( 2!= argNumber )
  {
      cout << "Please provide path to data file" <<endl;
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


        checkArgsNumber(argc);

        string filePath = argv[1];

        checkFilePath(filePath);	


	    
	//TH2D *hist_Single = new TH2D("hist_Single","Activity",200,0,200,500,0,4000);
	//TH1F *hist_Single = new TH1F("hist_Single","Activity",200,0,200);

	double  my_Distance, my_CPS_average ;
  	vector<double> Distance;
	vector<double> CPS_average;                                // Empty Vector of Double

	vector<double> eDistance;
	vector<double> eCPS_average;                                // Empty Vector of Double






	ifstream input;

	input.open(filePath.c_str());
		

    while(!input.eof())

	    {
	      			input>>my_Distance>>my_CPS_average ;
				Distance.push_back(my_Distance);
				CPS_average.push_back(my_CPS_average);
				eDistance.push_back(0.1);
				eCPS_average.push_back(sqrt(my_CPS_average));
			}
	


	if(Distance.size()==0 || CPS_average.size()==0){

	cout<<"Check the Data file"<<endl;

	exit(5);


	}


	//TGraph *g = new TGraph(Distance.size(), &Distance[0], &CPS_average[0]);								
  	TCanvas *c= new TCanvas();
 	TGraphErrors *g = new TGraphErrors(Distance.size(),&Distance[0],&CPS_average[0],&eDistance[0],&eCPS_average[0]);
	TF1 *f1 = new TF1("f1","(([0]/(pow((x),2)))+[1])",0.0,150.0);
	//TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);    TF1 *f1 = new TF1("f1","(([0]/(pow((x+[1]),2)))+[2])",0.0,150.0);  	TF1 *f1 = new TF1("f1","(([0]/(pow((x),2)))+[1])",0.0,150.0);

	g->Draw("ACP");
    	g->SetLineColor(kRed);
	g->SetLineWidth(1.5);
	g->SetLineStyle(1.0);
	g->SetMarkerStyle(kFullTriangleUp);

	g->SetTitle(filePath.c_str());
	
	g->GetXaxis()->SetTitle("Distance [cm]");
	g->GetXaxis()->SetTitleOffset(1.0);
	g->GetYaxis()->SetTitle("Counts per Second [cps]");
	g->GetYaxis()->SetTitleOffset(1.3);
   	g->Fit(f1);

	double chi = f1->GetChisquare();    

 	c->SetLogy();
	c->SaveAs("Al.png");
	cout<<"ChiSquare is"<<"	"<<chi<<endl;
	
	delete g;   

	input.close();
	
	 return 0;





	}


///****************************************************************The End**************************************************///

