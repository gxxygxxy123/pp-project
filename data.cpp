#include <iostream>
#include <cstdio>
#include <fstream>
#include <random>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Usage: ./a [Filename] [Number]\n");
		exit(1);
	}
	ofstream f;
	f.open(argv[1]);
	if(!f){
		cout << "Cannot open file\n";
	}
	else{
		random_device rd;
		default_random_engine gen = default_random_engine(rd());
		uniform_real_distribution<> dis(0,5000);
		int n = atoi(argv[2]);
		f << n << "\n";

		for(int i = 1;i <= n;i++){
			float a,b;
			a = dis(gen);
			b = dis(gen);
			f << fixed;
			f << to_string(i) << "| "<< setprecision(2)<< a << " "<< b<< "\n";
		}
		f.close();
	}
	return 0;
}
