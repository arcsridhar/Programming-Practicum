//
//  assign2_a_s1316.cpp
//
//  Archana Sridhar
//  a_s1316
//  Date : 02/18/2019
//  Assignment Number: 2
//  CS 5301.251 Spring 2019
//  Instructor: Dr.Jill Seaman
//
//  C++ program that will allow a user to query a digital library of music

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int SIZE = 100;
struct MusicData
{
    string id;
    string title;
    string artist;
    double size;
    int plays;
    int rating;
}data[SIZE];
void sortbyratings(MusicData [],int );
void sortbytitle(MusicData [],int );
void sortbyID(MusicData [],int );
int binarysearch(MusicData [],int ,string );
int linearsearch(MusicData [],int ,string ,string );

int main()
{
    string mid,mtitle,martist;
    double msize;
    int mplays,mrating;
    
    int choice;
    const int SORT_BY_TITLE=1,SORT_BY_RATING=2,LOOKUP_BY_ID=3,LOOKUP_ID=4,QUIT=5;
    
    ifstream inputFile;
    int count=0;
    
    inputFile.open("library.txt");
    
    while (inputFile >> mid)
    {
        inputFile >> ws;
        getline(inputFile, mtitle);
        getline(inputFile, martist);
        inputFile >> msize;
        inputFile >> mplays;
        inputFile >> mrating;
        
        data[count].id=mid;
        data[count].title=mtitle;
        data[count].artist=martist;
        data[count].size=msize;
        data[count].plays=mplays;
        data[count].rating=mrating;
        count++;
    }
    inputFile.close();
    do
    {
        cout << "\nMENU\n\n"
        << "1. Display Songs sorted by title\n"
        << "2. Display Songs sorted by rating\n"
        << "3. Lookup title and artist by ID\n"
        << "4. Lookup ID by title and artist\n"
        << "5. Quit the Program\n\n"
        << "Enter your choice: ";
        cin >> choice;
        
        while(choice < SORT_BY_TITLE || choice > QUIT)
        {
            cout << "Please enter a valid choice : ";
            cin >> choice;
        }
        switch(choice)
        {
            case SORT_BY_TITLE:
            {
                cout <<endl;
                sortbytitle(data,count);
                for(int i=0; i < count; i++)
                {
                    //cout << left << setw(5) << data[i].id;
                    cout << left << setw(30) << data[i].title;
                    cout << left << setw(25) << data[i].artist <<" ";
                    cout << right << setw(5) << data[i].size <<"MB ";
                    cout << right << setw(3) << data[i].plays <<" ";
                    cout << right <<setw(2) << data[i].rating <<" "<<endl;
                }
            }
                cout <<endl;
                break;
            case SORT_BY_RATING:
            {
                cout <<endl;
                sortbyratings(data,count);
                for(int i=0; i < count; i++)
                {
                    //cout << left << setw(5) << data[i].id;
                    cout << left << setw(30) << data[i].title;
                    cout << left << setw(25) << data[i].artist <<" ";
                    cout << right << setw(7) << data[i].size <<"MB ";
                    cout << right << setw(4) << data[i].plays <<" ";
                    cout << right << setw(2) << data[i].rating <<" "<<endl;
                }
            }
                cout <<endl;
                break;
            case LOOKUP_BY_ID:
            {
                string ID;
                cout <<"Enter the id of the song :";
                cin >> ID;
                int position=binarysearch(data,count,ID);
                if(position == -1)
                {
                    cout <<"No song found with that ID." <<endl;
                }
                else
                {
                    cout << data[position].title <<" by " << data[position].artist <<endl;
                }
            }
                break;
            case LOOKUP_ID:
            do
            {
                string artist,title;
                cout << "Enter the title : ";
                cin >> ws;
                getline(cin,title);
                cout << "Enter the artist : ";
                cin >> ws;
                getline(cin,artist);
                int target = linearsearch(data,count,title,artist);
                if (target == -1)
                {
                    cout <<"No data found";
                }
                else
                {
                    cout <<"The ID of "<< data[target].title <<" by ";
                    cout << data[target].artist <<" is "<< data[target].id << "." <<endl;
                }
            }while(inputFile >> mid);
                break;
            case QUIT:
                cout <<"Exiting the program..."<<endl;
                break;
        }
    }while(choice != QUIT);
    
    return 0;
}
void sortbytitle(MusicData a[],int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < size-1 ; i++)
        {
            if ((a[i].title > a[i+1].title))
            {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    }while(swapped);
}
void sortbyratings(MusicData a[],int size)
{
    bool swapped;
    sortbytitle(a,size);
    do
    {
        swapped = false;
        for (int i = 0; i < size-1 ; i++)
        {
            if (a[i].rating < a[i+1].rating)
            {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    }while(swapped);
}

void sortbyID(MusicData a[],int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < size-1 ; i++)
        {
            if ((a[i].id > a[i+1].id))
            {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    }while(swapped);
}
int binarysearch(MusicData a[], int size, string ID)
{
    
    int first = 0;
    int middle ;
    int last = size-1;
    int position = -1;
    bool found = false;
    
    sortbyID(a,size);
    while( !found && first <= last)
    {
        middle = (first+last)/2;
        if(a[middle].id == ID)
        {
            found = true;
            position = middle;
        }
        else if(a[middle].id > ID)
        {
            last = middle -1;
        }
        else
        {
            first = middle+1;
        }
        
    }
    return position;
}
int linearsearch(MusicData a[],int size,string m_title,string m_artist)
{
    int i=0;
    int position = -1;
    bool found=false;
    while(i < size && !found)
    {
        if(a[i].artist == m_artist && a[i].title == m_title)
        {
            position=i;
            found= true;
        }
        i++;
    }
    return position;
}
