#include <iostream>               // also write this

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

int main(int argc, char** argv)   // main part
{
	G4RunManager *runManager = new G4RunManager();       // outer shell, anything we want to write should be in this, formation like: TH1F *h1 = new TH1F();
	runManager->Initialize();    // later when we add more functions, we need to initialize them. But here since no functions added, it will give error messages
	
	G4UIExecutive *ui = new G4UIExecutive(argc,argv);
	G4VisManager *visManager = new G4VisExecutive();     // since we want to have user interface and visualize it, we should write these two
	visManager->Initialize();
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
	ui->SessionStart();     // to get the ui and vis work, we need these 5 lines
	
	return 0;
}

// we are going to use this template many many times, and it principly runs for all files we run, we can add anything into it to add functions.
