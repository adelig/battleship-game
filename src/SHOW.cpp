#include "SHOW.h"
#include <iostream>
#include "PLAYER.h"
using namespace std;

const char isHIT = 'H';
const char isWATER = 'W';

void SHOW(int thisPlayer, bool gameRunning)
{
	   cout << "\033[1;31mPLAYER " << thisPlayer << "'s GAME BOARD\033[0m\n";
	   cout << "\033[1;31m----------------------\033[0m\n";
	   cout << "   ";
	  
	    for (int w=0; w<elements; ++w) 
	   {
	      cout <<"\033[1;32m"<< w << "  \033[0m";
	      
	   }
	  cout << "\n"; 
	   
	  for (int h=0; h<rows; ++h){
		for (int w=0; w<elements; ++w){
		  
			if (w==0) cout <<"\033[1;32m"<< h << " \033[0m";
			
			if (w<10 && w==0) cout << " ";
			
			if (gameRunning == false) cout <<"\033[1;36m"<< player[thisPlayer].grid[w][h] << "  \033[0m";
			
			if (gameRunning == true && player[thisPlayer].grid[w][h] != isSHIP)
			{
			  
			  switch(player[thisPlayer].grid[w][h])
			  {
			      case 'S' :
				cout <<"\033[1;35m"<< player[thisPlayer].grid[w][h] << "  \033[0m";    
				break;
			      case 'H' :
				cout <<"\033[1;31m"<< player[thisPlayer].grid[w][h] << "  \033[0m";
				break;
			      case 'M' :
				cout <<"\033[1;32m"<< player[thisPlayer].grid[w][h] << "  \033[0m";
				break;
			      default : 
				cout <<"\033[1;36m"<< player[thisPlayer].grid[w][h] << "  \033[0m";
			    
			  }
			}
			  else if (gameRunning == true && player[thisPlayer].grid[w][h] == isSHIP)
			  {
			    cout << "\033[1;36m"<< isWATER << "  \033[0m";
			  }
			 
			 if (w == elements-1) cout << "\n";   // to change line when we reach the border
			
			}
			cout << endl;
			
	  }
		
		
}