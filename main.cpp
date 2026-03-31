#include <iostream>
#include <fstream>
#include <string>

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

int main()
{
    addBook();
    return 0;
}
