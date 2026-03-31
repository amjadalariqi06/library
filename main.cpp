#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

void addBook()
{
    cin.ignore();
    string BookName,author;
    ofstream library;
    library.open("library.txt", ios::app);
    cout<<"Add the Book Name : ";
    getline(cin,BookName);
    cout<<"Add the Author name : ";
    cin>>author;

    cout<<"added successfully!\n\n";

    library<<BookName<<','<<author<<','<<1<<endl;
    library.close();
}

void showBooks()
{
    cin.ignore();
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
    cin.ignore();
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
            cout<<"deleted successfully!\n\n";

            remove("library.txt");
            rename("temp.txt","library.txt");}

        else
        {
            cout<<"not found\n";
            remove("temp.txt");
        }



}

void searchbook()
{
    cin.ignore();
    string BookName,author,avail,target;
    getline(cin,target);
    ifstream library;
    library.open("library.txt");
    while(getline(library,BookName,',') && getline(library,author,',') && getline(library,avail))
    {
        if (BookName == target)
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
}

int main()
{
    int choice;
    cout<<"welcome to our library! \n";

	do{
		cout<<"Choose 1 for add a new book\n";
		cout<<"Choose 2 for show the list\n";
		cout<<"Choose 3 for search for books\n";
		cout<<"Choose 4 for delete a book\n";
		cout<<"Choose 5 for exit\n";
		cin>>choice;

		switch(choice){
		case 1:
			addBook();
			break;
		case 2:
			showBooks();
			break;
		case 3:
			searchbook();
			break;
		case 4:
			deletebook();
		default:
			break;

	}
	}while(choice != 5);
}
