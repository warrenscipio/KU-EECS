#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

Executive::Executive(){

}

Executive::Executive ( char file[] ) {
	string word;
	int count = 0;
	
	
	ifstream inp(file);

	
	while (inp >> word ){
		if(word=="done"){
			done();
			
		}

		else if(word=="show"){
			show();
			
		}
		
		else {
			addWord(word);	
		}
	
	}

	while(!vips.isEmpty() || !people.isEmpty())
		done();
	
	
	inp.close();


}

void Executive::show(){
	string vip;
	string name;
	try{
		if(!vips.isEmpty())
			vip = vips.peek();
		
		 if(!people.isEmpty())
			name = people.peekFront();


		if(!vips.isEmpty())
			printShow(vip,name);
		else if(!people.isEmpty())
			printShow(name,"PokemonIsAwesome");
		else
			cout << "nothing to show...continuing." << endl;

	} catch(exception e){
		cout << e.what() << endl;
	}

}

void Executive::done(){
	string name;
	string name2;

	try{
		if(!vips.isEmpty()){
			name = vips.peek();
			vips.pop();
		
			
				if(!vips.isEmpty()){
					name2 = vips.peek();
					printDone(name,name2, 2);
				}else if(people.isEmpty()){
					printDone(name,"PokemonIsAwesome", 3);
			
				}else{
			
				name2 = people.peekFront();
				printDone(name,name2, 2);
			}
		

		
		}else if(!people.isEmpty()){
			name = people.peekFront();
			people.dequeue();
		
			if(!people.isEmpty()){
				name2 = people.peekFront();
				printDone(name,name2,1);
		
			}else
				printDone(name,"PokemonIsAwesome", 3);
		
	
		}else{
			cout << "The stack and queue are both empty.. so the program is done" << endl;
			exit(0);
		}
	} catch(exception e){	
		cout << e.what() << endl;
	}

}

void Executive::addWord(string w){
	string c;
	c = w.substr(0,3);
	if(c=="VIP"){	
		addToStack(w);
	}else{
		addToQueue(w);
	}

}


void Executive::addToStack(string w){
	try{	
		if(vips.isEmpty()){
			vips.push(w);
		}else{
		string top = vips.peek();
			if(w>top)
				vips.push(w);

		}
	}catch(exception e){
		cout << e.what() << endl;
	}

}

void Executive::addToQueue(string w){
	try{
		people.enqueue(w);

	} catch( exception e){
		cout << e.what() << endl;
	}

}

void Executive::printDone(string name, string name2, int moment){

	switch(moment){

		case 1 : cout << name << " is done; "<< name2 << " is starting." << endl;
		break;
		
		case 2 : cout << name << " is done; " << name2 << " is resuming." << endl;
		break;

		default: cout << name << " is done; no one is waiting, Lydia rests." << endl;
		break;
		
	}

}

void Executive::printShow(string name, string name2){

	if(name2=="PokemonIsAwesome"){
		cout << "*** " << name << " is currently being served; ***" << endl;
	}else{	

		cout << "*** " << name << " is currently being served; " << name2 << " is waiting in the queue ***" << endl;
	}
}

	

	
	


	

