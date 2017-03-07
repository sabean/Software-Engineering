#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "output.txt";

    QFile file(filename);

    if(!file.open(QFile::WriteOnly |QIODevice::Append | QFile::Text)){
        qDebug() << "Couldn't open the file for writing";
        return 0;
    }

    QTextStream s(stdin);
    QString input = s.readLine();
    QTextStream stream(&file);
    stream << input << endl;

    file.flush();
    file.close();

    return a.exec();
}
