#include <iostream>
#include <vector>
#include <map>
#include <fstream>

int main()
{
	std::ifstream ulazna_datoteka;
	std::map<std::string,unsigned>mapa_frekvencija_rijeci;//unsigned je rnemoze -3
	std::ofstream izlazna_datoteka;

	//setup
	ulazna_datoteka.open("C:\\Users\\petar\\Desktop\\king_james_bible.txt", std::ifstream::in);// 2 je mode
	if (!ulazna_datoteka.is_open())
	{
		std::cout << "Greska kod otvaranja datoteke" << std::endl;
		return 0;
	}



	//parse file 


	for(;! ulazna_datoteka.eof();)//nemoramo imati setup ni korak ali uvjet moramo imat 
	{
		//citamo rijeci iz ulazne datoteke
		std::string rijec;
		ulazna_datoteka >> rijec;//ima operatore kao cin
		//std::cout << "Ucitana rijeci iz datoteke:" << rijec << std::endl ;

		//sad trebamo u mapi dodat 
		//moramo napravit uvjet ako postoji ta rijec u mapi 
		//i rijec prije nego prode dole u nas statment trebali bi je dekapitalizirat

		//TODO:decapitalize all letters in var rijec


		if (mapa_frekvencija_rijeci.find(rijec) != mapa_frekvencija_rijeci.end())
		{
			mapa_frekvencija_rijeci[rijec]++;//Npr nasli smo rijec the i onda na to mjesto zelimo dat counter 1
		}
		else
		{
			mapa_frekvencija_rijeci[rijec] = 1;//Ako nepostoji pojavila se prvi put i stavimo je na jedan 
		}


	}

	//print map
	if (false)
	{
		std::cout << "Sadrzaj mape:" << std::endl;
		for (auto it = mapa_frekvencija_rijeci.cbegin(); it != mapa_frekvencija_rijeci.cend(); it++)
		{
			//Prema iteratorima se odnosimo kao prema pointerima i trebamo ih dereferencirat
			std::cout << it->first << ":" << it->second << std::endl;//key-value


		}
	}
	std::multimap<unsigned, std::string> mapa_frekvencija_rijeci_po_frekvenciji;

	//obrni mapu
	for (auto it = mapa_frekvencija_rijeci.begin(); it != mapa_frekvencija_rijeci.end(); it++)
	{//za svaki enty u mapi frekvencija po frekvenciji 
	
		// samo ih zamjenim

		mapa_frekvencija_rijeci_po_frekvenciji.insert({ it->second,it->first });

	}

	//print map po frekvencijama
	{
		const auto& mapa = mapa_frekvencija_rijeci_po_frekvenciji;//Umjesto da radimo vise forova samo mjenjamo mapa

		std::cout << "Sadrzaj mape:" << std::endl;
		for (auto it = mapa.cbegin(); it != mapa.cend(); it++)
		{
			//Prema iteratorima se odnosimo kao prema pointerima i trebamo ih dereferencirat
			std::cout << it->first << ":" << it->second << std::endl;//key-value

		}
	}
	

	return 0;
}