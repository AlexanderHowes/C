#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
   fstream newfile;
   newfile.open("out.txt",ios::in);
   if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
         cout << tp << "\n";
      }
      newfile.close();
   }
}