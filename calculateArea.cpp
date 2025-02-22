#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int choice;
    int Area,radious,length,width;
    cout<<"1-Area of circle: "<<endl;
    cout<<"2-Area of rectangle: "<<endl;
    cout<<"3-Area of square: "<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
    cout<<"Enter the radious of circle: ";
    cin>>radious;
    Area=3.14*radious*radious;
    cout<<"Hence Area of circle is: "<<Area<<endl;
        break;
    case 2:
    cout<<"Enter the length of rectangle: ";
    cin>>length;
    cout<<"Enter the width of rectangle: ";
    cin>>width;
    Area=length*width;
    cout<<"Hence Area of rectangle is: "<<Area<<endl;
        break;
    case 3:
    cout<<"Enter the length side of square: ";
    cin>>length;
    Area=pow(length,2);
    cout<<"Hence Area of square is: "<<Area<<endl;
        break;
    
    default:
    cout<<"\nInvalid choice...."<<endl;
        break;
    }
    return 0;
}