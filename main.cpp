#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

void addBook()
{
    string BookName,author;
    ofstream library;
    library.open("library.txt", ios::app);
    cout<<"Add the Book Name : ";
    getline(cin,BookName);
    cout<<"Add the Author name : ";
    cin>>author;

    library<<BookName<<','<<author<<','<<1<<endl;
    library.close();
}

void showBooks()
{
    string BookName,author,avail;
    ifstream library;
    library.open("library.txt");
    while(getline(library,BookName,',') && getline(library,author,',') && getline(library,avail))
    {
        cout<<left<<"Book name : "<<setw(20)<<BookName<<"Author : "<<setw(12)<<author;
        if (avail == "1")
        {
            cout<<"Availability : Yes"<<endl;
        }
        else
        {
            cout<<"Availability : No"<<endl;
        }
    }
}
void deletebook()
{
    string bookname,author,avail,target;
    bool found = false;

    cout<<"Enter the book name : ";
    //cin.ignore();
    getline(cin,target);

    ofstream tempo;
    tempo.open("temp.txt");
    ifstream library("library.txt");
    if(tempo.is_open() && library.is_open()){
    while(getline(library,bookname,',') && getline(library,author,',') && getline(library,avail))
    {
        if (bookname == target)
        {
            found = true;
        }
        else
        {
            tempo<<bookname<<','<<author<<','<<1<<endl;
        }}}
            library.close();
            tempo.close();

        if (found){
            cout<<"deleted successfully!\n";

            remove("library.txt");
            rename("temp.txt","library.txt");}

        else
        {
            cout<<"not found\n";
            remove("temp.txt");
        }



}
int main()
{
    //addBook();
    deletebook();
    //return 0;
}
