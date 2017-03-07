#include <QCoreApplication>
#include <iostream>
#include <QString> // using Qt string
#include <QFile> // using Qt library called file
#include <QIODevice>
#include <QTextStream>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "output.txt"; // the output file is the output.txt

    QFile file(filename); // the QFile takes in the filename as agrument to use file.
// We are using file in write mode only, here testing if the file is properly opened or not
    if(!file.open(QFile::WriteOnly |QIODevice::Append | QFile::Text)){
        qDebug() << "Couldn't open the file for writing";
        return 0;
    }
// Reading from the console
    QTextStream s(stdin);
    QString input = s.readLine();
    
// Writing into the file from the string read from console and stored in input    
    QTextStream stream(&file);
    stream << input << endl;
    
// Properly close the file
    file.flush();
    file.close();

    return a.exec();
}
