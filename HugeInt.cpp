#include<iostream>
#include"HugeInt.h"
#include<string>
#include<vector>
#include<sstream>
using namespace std; 
HugeInt::HugeInt(){}
HugeInt::HugeInt(int value){
	string str;
	stringstream ss;
	ss<<value;
	ss>>str;

	for(int i=0;i<str.length();++i){
    
	int temp;
	stringstream ss;

	ss<<str.substr(i,1);
	ss>>temp;

	int_vector.push_back(temp);
	}
}


HugeInt::HugeInt(string str){
for(int i=0;i<str.length();++i){
	int temp;
	stringstream ss;

	ss<<str.substr(i,1);
	ss>>temp;

	int_vector.push_back(temp);
	}
   
}




istream &operator>>(istream &in,HugeInt &hi){
	string str;
	in>>str;

for(int i=0;i<str.length();++i){
	int temp;
	stringstream ss;

	ss<<str.substr(i,1);
	ss>>temp;
	hi.int_vector.push_back(temp);
	}

}




ostream &operator<<(ostream &out,const HugeInt &hi){ 
  
	for(int i=0;i<hi.int_vector.size();++i){
	out<<hi.int_vector[i];
	}
	return out;
}  




  
HugeInt& HugeInt::operator=(const HugeInt &hi){

	int_vector=hi.int_vector;
	return *this;

}


const HugeInt HugeInt::operator+(const HugeInt &hi){

	vector<int> reverse_vector;
	int carryout=0;

	for(int i=int_vector.size()-1,j=hi.int_vector.size()-1;i>=0&&j>=0;--i,--j){

		if(carryout+int_vector[i]+hi.int_vector[j]<=9){
		reverse_vector.push_back(carryout+int_vector[i]+hi.int_vector[j]);
		carryout=0;}

		if(carryout+int_vector[i]+hi.int_vector[j]>=10){
		reverse_vector.push_back(carryout+int_vector[i]+hi.int_vector[j]-10);
		carryout=1;}

}
   

	if(int_vector.size()>hi.int_vector.size()){
		if(carryout==1){
			reverse_vector.push_back(1+int_vector[int_vector.size()-hi.int_vector.size()-1]);
			for(int i=int_vector.size()-hi.int_vector.size()-2;i>=0;--i){reverse_vector.push_back(int_vector[i]);}                                                         
		}
		if(carryout==0){
			for(int i=int_vector.size()-hi.int_vector.size()-1;i>=0;--i){reverse_vector.push_back(int_vector[i]);}                                                         
		}
	}


	if(hi,int_vector.size()>int_vector.size()){
		if(carryout==1){
			reverse_vector.push_back(1+hi.int_vector[hi.int_vector.size()-int_vector.size()-1]);
			for(int i=hi.int_vector.size()-int_vector.size()-2;i>=0;--i){reverse_vector.push_back(hi.int_vector[i]);}                                                         
		}
		if(carryout==0){
			for(int i=hi.int_vector.size()-int_vector.size()-1;i>=0;--i){reverse_vector.push_back(hi.int_vector[i]);}                                                         
		}
	}

	if(hi.int_vector.size()==int_vector.size()){
		if(carryout==1){reverse_vector.push_back(1);}
	}

   
	HugeInt real_int;

	for(int i=reverse_vector.size()-1;i>=0;--i){
	real_int.int_vector.push_back(reverse_vector[i]);
	}


	return real_int;
}


    

const HugeInt HugeInt::operator-(const HugeInt &hi){
   
	vector<int> reverse_vector;
   
	int carryout=0;
	for(int i=int_vector.size()-1,j=hi.int_vector.size()-1;i>=0&&j>=0;--i,--j){

		if(carryout+int_vector[i]-hi.int_vector[j]>=0){
		reverse_vector.push_back(carryout+int_vector[i]-hi.int_vector[j]);
		carryout=0;}
  
		if(carryout+int_vector[i]-hi.int_vector[j]<0){
		reverse_vector.push_back(10+carryout+int_vector[i]-hi.int_vector[j]);
		carryout=-1;}

	}
   

   
	if(int_vector.size()>hi.int_vector.size()){
	if(carryout==0){
		for(int i=int_vector.size()-hi.int_vector.size()-1;i>=0;--i){reverse_vector.push_back(int_vector[i]);}                                                         
		}
	if(carryout==-1){
		reverse_vector.push_back(-1+int_vector[int_vector.size()-hi.int_vector.size()-1]);
		for(int i=int_vector.size()-hi.int_vector.size()-2;i>=0;--i){reverse_vector.push_back(int_vector[i]);}                                                         
	}
	}


	HugeInt real_int;
	for(int i=reverse_vector.size()-1;i>=0;--i){
	real_int.int_vector.push_back(reverse_vector[i]);
	}
   
	return real_int;
    
}



 
