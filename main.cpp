/*
 * main.cpp
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */
#include<iostream>
#include"MovieApplication.h"

int main(){
	int choice=0;
	MovieApplication movieApp_obj;

	do{
		std::cout<<"\n\n\t######## MENU ########\n"
				<<"1. Show Movies\n"
				<<"2. Search Movie\n"
				<<"3. Add Movie\n"
				<<"4. Remove Movie\n"
				<<"5. Exit\n "
				<<"\n\tEnter Your Choice : ";
		std::cin>>choice;

		switch(choice){
		case 1:
			movieApp_obj.showMovies();
			break;
		case 2:
			movieApp_obj.searchMovie();
			break;
		case 3:
			movieApp_obj.updateMovieList(ADD_MOVIE);
			break;
		case 4:
			movieApp_obj.updateMovieList(REMOVE_MOVIE);
			break;
		case 5:
			break;
		default:
			std::cout<<"\nWARNING : Wrong Input !!!\n";
			break;
		}
	}while(choice!=5);



	return 0;
}



