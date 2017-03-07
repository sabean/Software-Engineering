#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string value;
    getline(cin,value);
    ofstream myfile;
    myfile.open("example.txt");
    	
    if (myfile.is_open()){
  	myfile << value;
    	myfile.close();
     }
     else cout << "Unable to open file";
    return a.exec();
}
