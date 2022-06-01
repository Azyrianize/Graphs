#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int pod_graf(int liczba_wierzcholkow_int, int wierzcholek_max_stopien, int **macierz_sasiedztwa, int *liczba_krawedzi, int *tablica_spojnosc, int *pod_graph, bool *visited)
{
	int *tablica =  new int [liczba_wierzcholkow_int];
	int max_stopien_liczba;
	int last;
	int possible_row;	
	int row;
	int cord1;
	int cord2;
	bool no_finish;
	int counter = 0;
	int verticies_num = 0;
	
	tablica_spojnosc[wierzcholek_max_stopien] = true;
	
	row = wierzcholek_max_stopien;
	
	do
	{
		counter = 0;
		last = verticies_num;
		
		for(int i = 0; i < liczba_wierzcholkow_int; i++)
		{					
			if(macierz_sasiedztwa[row][i] == 1)
			{	
				no_finish = true;
				if(i != row)
				{
					tablica_spojnosc[i] = i;
					tablica[verticies_num] = i;	
					possible_row = i;
				}
				

				
				counter++;
				verticies_num++;			
			}
		}
				
		if(last < verticies_num)
		{

			visited[last] = true;
			row = tablica[last+1];	
		}	
		else if(last == verticies_num)
		{
			no_finish = false;
		}
		
						
	} while(no_finish == true);

	for(int i = 0; i < liczba_wierzcholkow_int; i++)
	{				
		cout << tablica[i] << endl;
	}




	delete [] tablica;
	
	return 0;
}


int graf_pelny(int _counter_graf_pelny, int _liczba_wierzcholkow_int)
{
	bool graf_pelny = false;
	
	if(_liczba_wierzcholkow_int - 1 == _counter_graf_pelny)
	{
		graf_pelny = true;
	}
	else
	{
		graf_pelny = false;	
	}
	
	return graf_pelny;
}

int cykl_parzysty(int _counter_ramion)
{
	bool cykl = false;
	
	if(_counter_ramion == 2)
	{
		cykl = true;	
	}
	else
	{
		cykl = false;	
	}
							
	return cykl;
}

int main()
{		
	int liczba_n = 1;
	
	int counter_wierzcholkow = 0;	
	int counter_lini = 0;
	int counter_ramion = 0;
	int counter_graf_pelny = 0;
	
	int counter_ramion_whole = 0;
	int counter_graf_pelny_whole = 0;
	
	int dlugosc_lini;
	int liczba_wierzcholkow_int;
	
	int pointer1;
	int pointer2;
	
	int max_stopien;
	int wierzcholek_max_stopien;
	
	int temp;
	
	string liczba_wierzcholkow_string;
	string znak;
	string liniaMacierz;
	
	bool liczba_wierzcholkow_bool = false;

	string linia = "5 0100110100010100010110010";

	//string linia = "44 0100000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000111100000000000000000000000000000000000000010100000000000000000000000000000000000000000110110000000000000000000000000000000000000001010100000000000000000000000000000000000000110110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100010000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000100010000000000000000000000000000000000000000000000100001000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000001000010000000000000000000000000000000000000000000000101000000000000000000000000000000000000000010100000000000000000000000000000000000000000010100000000000000000000000000000000000000001010000000000000000000000000000000000000000000000111111000000000000000000000000000000000000010111110000000000000000000000000000000000000110111100000000000000000000000000000000000001110111000000000000000000000000000000000000011110110000000000000000000000000000000000000111110100000000000000000000000000000000000001111110";





	while(true)
	{
		int **macierz_sasiedztwa;
		int *liczba_krawedzi;
		int *tablica_spojnosc;
		bool *visited;
		int *pod_graph;
		
		bool graf_niespojny = false;		
				
		dlugosc_lini = linia.length();
		liczba_wierzcholkow_bool = false;
		liczba_wierzcholkow_string = "";
		pointer1 = 0;
		pointer2 = 0;
		counter_wierzcholkow = 0;
		max_stopien = 0;
		wierzcholek_max_stopien = 0;
		//cout << linia;
		bool test = false;
														
		for(int i = 0; i < dlugosc_lini; i++)
		{
				znak = linia[counter_wierzcholkow];
				//cout << znak;
				
				if(znak == " ")
				{
					liczba_wierzcholkow_int = atoi(liczba_wierzcholkow_string.c_str());
					macierz_sasiedztwa = new int *[liczba_wierzcholkow_int];
					liczba_krawedzi = new int [liczba_wierzcholkow_int];
					tablica_spojnosc = new int [liczba_wierzcholkow_int];
					visited = new bool [liczba_wierzcholkow_int];
			
					for(int j = 0; j < liczba_wierzcholkow_int; j++)
					{
						macierz_sasiedztwa[j] = new int [liczba_wierzcholkow_int];	
						//tablica_spojnosc[j] = new bool [liczba_wierzcholkow_int];	
					}
					
					liczba_wierzcholkow_bool = true;
				}
			
				if(liczba_wierzcholkow_bool == false)
				{
					liczba_wierzcholkow_string = liczba_wierzcholkow_string + znak;
				}
			
				if(liczba_wierzcholkow_bool == true && znak != " ")
				{
					macierz_sasiedztwa[pointer1][pointer2] = atoi(znak.c_str());
					//liniaMacierz = liniaMacierz + znak;
					
					if(znak == "1")
					{
						counter_ramion++;
						counter_graf_pelny++;	
					}

					pointer2++;
					
					if(pointer2 >= liczba_wierzcholkow_int)
					{
						liczba_krawedzi[pointer1] = counter_ramion;
						
						//if(counter_ramion > 0)
						//{						
							//tablica_spojnosc[pointer1] = new int [counter_ramion];
						//}
						
						if(counter_ramion == 0)
						{
							graf_niespojny = true;
						}
													
						for(int j = 0; j < liczba_krawedzi[pointer1]; j++)
						{
							tablica_spojnosc[pointer1] = 0;
						}
						
						temp = 0;
						
						for(int k = 0; k < liczba_wierzcholkow_int; k++)
						{
							if(macierz_sasiedztwa[pointer1][k] == 1)
							{
								//tablica_spojnosc[pointer1][temp] = k;
								//temp++;
								
							}		
						}
						
						if(liczba_krawedzi[pointer1] > max_stopien)
						{
							max_stopien = liczba_krawedzi[pointer1];
							wierzcholek_max_stopien = pointer1;
						}
						
						
						
						
						
						pointer1++;
						pointer2 = 0;
						
						if(cykl_parzysty(counter_ramion) == true)
						{
							counter_ramion_whole++;	
						}
						
						if(graf_pelny(counter_graf_pelny, liczba_wierzcholkow_int) == true)
						{
							counter_graf_pelny_whole++;
						}
						
						counter_ramion = 0;
						counter_graf_pelny = 0;
					}
				}
	
				counter_wierzcholkow++;
		}								
			
			
				
		if(graf_niespojny == false)
		{
			if(counter_graf_pelny_whole == liczba_wierzcholkow_int || (liczba_wierzcholkow_int % 2 == 1 && counter_ramion_whole == liczba_wierzcholkow_int))
			{
				cout << "True" << endl;
				counter_ramion_whole = 0;
				counter_graf_pelny_whole = 0;			
			}
			else
			{
				cout << "False" << endl;
				counter_ramion_whole = 0;
				counter_graf_pelny_whole = 0;
			}
		}
		else if(graf_niespojny == true)
		{
			
			pod_graf(liczba_wierzcholkow_int, wierzcholek_max_stopien, macierz_sasiedztwa, liczba_krawedzi, tablica_spojnosc, pod_graph, visited);
	
		}
		
		
		
		for(int i = 0; i < liczba_wierzcholkow_int; i++)
		{
			for(int j = 0; j < liczba_wierzcholkow_int; j++)
			{
				cout << macierz_sasiedztwa[i][j];
			}
			//cykl(macierz_sasiedztwa);
			cout << endl;
		}	
		

		
		for(int i = 0; i < liczba_wierzcholkow_int; i++)
		{
			//cout << i << "wierzcholek :  ";
			for(int j = 0; j < liczba_krawedzi[i]; j++)
			{
				//tablica_spojnosc[i][j] = false;
				//cout << tablica_spojnosc[i][j] << " ";
			}
			//cykl(macierz_sasiedztwa);
			//cout << endl;
		}
				
							
		if(counter_lini > 0 && counter_lini <= liczba_n)
		{
			for(int i = 0; i < liczba_wierzcholkow_int; i++)
			{
				delete [] macierz_sasiedztwa[i]; 
			}
			
			delete [] macierz_sasiedztwa;
			delete [] liczba_krawedzi;
			delete [] tablica_spojnosc;
		}
		
		//cout << endl;
		counter_lini++;	
		break;							
	}	
		
	
	return 0;
}
