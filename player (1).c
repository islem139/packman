// add the needed C libraries below
#include <stdbool.h> // bool, true, false
#include <stdlib.h> // rand
#include <stdio.h>
// look at the file below for the definition of the direction type
// pacman.h must not be modified!
#include "pacman.h"

// ascii characters used for drawing levels
extern const char PACMAN; // ascii used for pacman
extern const char WALL; // ascii used for the walls
extern const char PATH; // ascii used for the explored paths
extern const char DOOR; // ascii used for the ghosts' door
extern const char VIRGIN_PATH; // ascii used for the unexplored paths
extern const char ENERGY; // ascii used for the energizers
extern const char GHOST1; // ascii used for the ghost 1
extern const char GHOST2; // ascii used for the ghost 2
extern const char GHOST3; // ascii used for the ghost 3
extern const char GHOST4; // ascii used for the ghost 4

// reward (in points) when eating dots/energizers 
extern const int VIRGIN_PATH_SCORE; // reward for eating a dot
extern const int ENERGY_SCORE; // reward for eating an energizer

// put the student names below (mandatory)
const char * binome="Brinis_Dieng";


// put the prototypes of your additional functions/procedures below

/*typedef struct {
	int x;
	int y;
	
	} energies;
typedef struct {
	int x;
	int y;
	
	} fantomes;*/

typedef struct {
	direction d;
	int c;
	
	} cout;


// change the pacman function below to build your own player
int ** initialisation_graphe ( char ** map, int xsize, int ysize);
int ** graphes (char * * map ,int xsize, int ysize);
int factoriel(int j);

cout minDijk(cout i, cout j, cout k, cout l);

cout  dijkstra ( int y, int x ,int * * graph, direction, int cpt);
// your new pacman function can use as many additional functions/procedures as needed; put the code of these functions/procedures *AFTER* the pacman function
direction pacman(
		 char * * map, // the map as a dynamic array of strings, ie of arrays of chars
		 int xsize, // number of columns of the map
		 int ysize, // number of lines of the map
		 int x, // x-position of pacman in the map 
		 int y, // y-position of pacman in the map
		 direction lastdirection, // last move made by pacman (see pacman.h for the direction type; lastdirection value is -1 at the beginning of the game
		 bool energy, // is pacman in energy mode? 
		 int remainingenergymoderounds // number of remaining rounds in energy mode, if energy mode is true
		 ) {
  //direction d; // the direction to return
  //bool north=false; // indicate whether pacman can go north; no by default
  //bool east=false; // indicate whether pacman can go east; no by default
  //bool south=false; // indicate whether pacman can go south; no by default
  //bool west=false; // indicate whether pacman can go west; no by default
  //bool ok=false; // turn true when a valid direction is randomly chosen

int ** graphh = malloc(ysize * sizeof(   int *  ));
 int l;
 for(l=0;l<ysize;l++){
	graphh[l] = malloc(sizeof(int) * xsize);


} 

/*resultat.d = EAST;
resultat.c = 6;*/


  // can pacman go north?
 ///if(y==0 || (y>0 && map[y-1][x]!=WALL && map[y-1][x]!=DOOR && (map[y-2][x]!= GHOST1 || map[y-2][x]!= GHOST2 || map[y-2][x]!= GHOST3 || map[y-2][x]!= GHOST4) )) north=true;
  // can pacman go east?
  //if(x==xsize-1 || (x<xsize-1 && map[y][x+1]!=WALL && map[y][x+1]!=DOOR && (map[y][x+2]!=GHOST1 || map[y][x+2]!=GHOST2 ||map[y][x+2]!=GHOST3 ||map[y][x+2]!=GHOST4) )) east=true;
  // can pacman go south?
 // if(y==ysize-1 || (y<ysize-1 && map[y+1][x]!=WALL && map[y+1][x]!=DOOR && (map[y+2][x]!=GHOST1 || map[y+2][x]!=GHOST2 ||map[y+2][x]!=GHOST3 ||map[y+2][x]!=GHOST4 ) )) south=true;
  // can pacman go west?
  //if(x==0 || (x>0 && map[y][x-1]!=WALL && map[y][x-1]!=DOOR && (map[y][x-2]!=GHOST1 || map[y][x-2]!=GHOST2 ||map[y][x-2]!=GHOST3 ||map[y][x-2]!=GHOST4 ))) west=true;

printf("ok\n");
graphh = initialisation_graphe (map,  xsize,  ysize );

int i;
int j;
for (i = 0 ; i < ysize ; i++)
        { 

            for (j = 0 ; j < xsize ; j++)

	    { 
		if (j!=xsize-1){
			printf("%d |",graphh[i][j]); }
		else{	
			printf("%d\n |",graphh[i][j]);
	}
}
}



printf("ok1 \n");


 //graphh = graphes (map ,xsize, ysize);
printf("fct graph\n");  


cout resultat = dijkstra ( y,  x ,graphh,lastdirection,0);

printf("apres Dijk\n");

lastdirection = resultat.d;


  return resultat.d ;
}

/*********************************************************************************************************************************/

//foction parcourir explore la carte et recherche la position de l'energie la plus proche
/*void posEnergy (char * * map ,int xsize, int ysize, int *p1, int *p2,int x,int y, energies* energy)
{
	int i, j; 
	energies last;
	for (i = 0 ; i < ysize ; i++)
        {
            for (j = 0 ; j < xsize ; j++)
	    {
		last = *energy; 
		if (map[i][j]== ENERGY )
		{
			*p1= i;
			*p2= j;
														
		        energy->x = *p1;
			energy->y = *p2;
			energy->distance= abs (x - (*p1)) + abs(y -(*p2));
			if(last.distance < energy->distance)
			{
				energy->distance = last.distance;
				energy->x = last.x;
				energy->y = last.y;
			}*/







/*********************************************************************************************************************************

foction parcourir explore la carte et recherche la position de l'energie la plus proche

void posfantome (char * * map ,int xsize, int ysize, int *p1, int *p2,int x,int y, fantomes* fantome)
{
	int i, j; 
	fantomes last;
	for (i = 0 ; i < ysize ; i++)
        {
            for (j = 0 ; j < xsize ; j++)
	    {
		last = *fantome; 
		if (map[i][j]==GHOST1 || map[i][j]==GHOST2 || map[i][j]==GHOST3 || map[i][j]==GHOST4 )
		{
			*p1= i;
			*p2= j;
														
		        fantome->x = *p1;
			fantome->y = *p2;
			fantome->distance= abs (x - (*p1)) + abs(y -(*p2));
			if(last.distance < fantome->distance)
			{
				fantome->distance = last.distance;
				fantome->x = last.x;
				fantome->y = last.y;
			}*/

int * * initialisation_graphe (char ** map, int xsize, int ysize )
{
	
	printf("init start");
     int m; int n;
	int ** graphe = malloc(ysize * sizeof( int *));
 int l;
 for(l=0;l<ysize;l++){
	graphe[l] = malloc(sizeof(int) * xsize);


} 

	for (m = 0 ; m < ysize ; m++)
      	  {
       	     for (n = 0 ; n< xsize ; n++)
	 	   { 

			graphe [m][n]= -1 ; 
		}
	
	}

int cpt = 0;

	 int i; int j;

	for (i = 0 ; i < ysize ; i++)
        {

            for (j = 0 ; j < xsize ; j++)
	    { 


		
		if  (map[i][j]== 'O') 
		{
			graphe[i][j]=0;
			} 
		else if ( map[i][j]== '$')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			
		
		
		else if ( map[i][j]== '%')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			



		else if ( map[i][j]== '#')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			



		else if ( map[i][j]== '&')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			
		else if ( map[i][j]== '*')
			{graphe[i][j]=1000;
				cpt++;}
			

		else if ( map[i][j]== '.')
			{graphe[i][j]=1;}
			

		else if ( map[i][j]== ' ')
			{graphe[i][j]=2;}
		
		
		}
	}

//printf("%d\n",xsize*ysize);

//printf("Comppteur : %d\n",cpt);


//printf("map %c\n",map[ysize-1][xsize-1]);


printf("cpt : %d \n",cpt);











 return graphe;

printf("fin init \n");
}



int * * graphes (char * * map ,int xsize, int ysize)
{ 
	

	
 int ** graphe = malloc(ysize * sizeof(  int *));
 int l;
 for(l=0;l<ysize;l++){
	graphe[l] = malloc(sizeof(int) * xsize);


} 


	int m;
	int n;
	for (m = 0 ; m < ysize ; m++)
      	  {
       	     for (n = 0 ; n < xsize ; n++)
	 	   { 

			graphe [m][n]= -1 ; 
		}
	
	}





/*






	int cpt = 0;

	 int i; int j;

	for (i = 0 ; i < ysize ; i++)
        {

            for (j = 0 ; j < xsize ; j++)
	    { 
		cpt++;//printf("in boucle");

		
		if  (map[i][j]== 'O') 
		{
			graphe[i][j]=0;
			} 
		else if ( map[i][j]== '$')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			
		
		
		else if ( map[i][j]== '%')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			



		else if ( map[i][j]== '#')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			



		else if ( map[i][j]== '&')
			{graphe[i][j]=100;
				if (map[i-1][j] != '*')
				{graphe[i-1][j]=50;}
				else if (map[i+1][j] != '*' )	
					{graphe[i+1][j]=50;}
	
				else if ( map[i][j-1] != '*')	
					{graphe[i][j-1]=50;}
	
				else if ( map[i][j+1] != '*')
					{graphe[i][j+1]=50;}	

				else if (map[i+1][j+1] != '*')	
					{graphe[i+1][j+1]=25;}	

				else if (map[i-1][j-1] != '*')	
					{graphe[i-1][j-1]=25;}	


				 else if (map[i-1][j+1] != '*') 	
					{graphe[i-1][j+1]=25;}	

				else if ( map[i+1][j-1] != '*')	
					{graphe[i+1][j-1]=25;}	
			
			
			}
			
		else if ( map[i][j]== '*')
			{graphe[i][j]=1000;}
			

		else if ( map[i][j]== '.')
			{graphe[i][j]=1;}
			

		else if ( map[i][j]== ' ')
			{graphe[i][j]=2;}
		
		
		}
	}

printf("%d\n",xsize*ysize);

printf("Comppteur : %d\n",cpt);


printf("map %c\n",map[ysize-1][xsize-1]);


for (i = 0 ; i < ysize ; i++)
        { 

            for (j = 0 ; j < xsize ; j++)

	    { 
		if (j!=xsize-1){
			printf("%d |",graphe[i][j]); }
		else{	
			printf("%d\n |",graphe[i][j]);
	}
}
}


printf("avant\n");


printf("associa\n");*/
return graphe;

printf("apres");
}



		// il faut tester sur les murs et les chemins parcourus et non parcourus, il reste à coder l'algo de dichtra 
cout   dijkstra ( int y, int x ,int * * graph,direction d, int cpt)

{ 
// cas de base : comme une initialisation d'une récurrence .	
cout  * res = malloc(sizeof(cout));

int cptlocal = cpt++;
printf("malloc Dijk fct\n");	
		


	/*if(graph[y][x] == graph[y][x+1] && graph[x][y]==1000){
	 
	
	}
	else*/ 
while(cpt<260)
	{
			printf("cas général\n");
			printf("%d\n",cptlocal++);


		//resultat->d = NORTH;
		//resultat->c = 1;
		cout cN ;
		cout  cS ;
		cout cE;
		cout  cW;
		
//calcul du cout le plus faible pour choisir le chemin le plus 

		//cN = dijkstra( y-1, x , graph ,NORTH,cptlocal++);
		cN.c += graph[y-1][x];
		cN.d = NORTH ; 
		
		//cS = dijkstra( y+1, x , graph , SOUTH,cptlocal++);
		cS.c += graph[y+1][x]; 
		cS.d = SOUTH ; 
		//cE = dijkstra( y, x+1 , graph , EAST,cptlocal++);
		cE.c += graph[y][x+1]; 
		cE.d = EAST ;
		//cW = dijkstra( y, x-1 , graph , WEST,cptlocal++);
		cW.c += graph[y][x-1]; 
		cW.d = WEST ;
			
		
		*res = minDijk(cN,cS,cE,cW);
		
		return *res;
	}

return * res ;

}


cout minDijk(cout i, cout j, cout k, cout l){

	cout minC;
	int min;
	min = i.c;
	if(j.c<min){
		min = j.c;
		minC=j;}

	if(k.c<min){
		min = k.c;
		minC=k;}

	if(l.c<min){
		min = l.c;
		minC=l;}


	return minC;



}



/**************************************************************************************/

