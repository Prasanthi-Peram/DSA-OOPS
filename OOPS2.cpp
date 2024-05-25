#include <bits/stdc++.h>
using namespace std;
/*Operator Overloading: We tell the compiler how to do the basic operations we know on objects rather than just numbers.
There are two types of operator overloading: Unary and binary--based on number of operands
Unary:
return type classname::operator operator bring overloaded(parameter list){
    //body
}

demo demo::operator + (demo){
    
}
Binary
return type classname::operator operator symbol(parameter)
multiply multiply::operator *(multiply c){
    multiply temp;
    temp.first=first*c.first;
    temp.second=second*c.second;
    return temp;//here temp is sending the result to obj3
}
 */
//Lets consider a sample code to give negation of integers
/*class demo{
    int x,y,z;
    public:
    void getdata(int a,int b,int c){
        x=a;
        y=b;
        z=c;
    }
    //declaration of two different functions within the class
    void display();
    void operator -();

};
//defination = return type classname :: function name(parameter list)
//This syntax is used if you wish to define stuff outside of the class else the the body can simly be written under the declaration.
void demo::display(){
    cout<<"X= "<<x<<"\nY="<<y<<"\nZ="<<z<<endl;
}
void demo :: operator -(){
    x=-x;
    y=-y;
    z=-z;
}
int main(){
    demo obj1;
    obj1.getdata(10,20,30);
    obj1.display();
    -obj1;
    obj1.display();
    return 0;
}*/

class multiply{
    int first, second;
    public:
    void getdata(int a,int b){
        first=a;
        second=b;
    }
    void display(){
        cout<<"First= "<<first<<"\nsecond= "<<second<<endl;
    }
    multiply operator*(multiply c){
        multiply temp;
    temp.first=first*c.first;
    temp.second=second*c.second;
    return temp;//here temp is sending the result to obj3
    }
};
int main(){
    multiply obj1,obj2,obj3;
    obj1.getdata(15,20);
    obj2.getdata(3,45);
    obj3=obj1*obj2;
    obj3.display();
    return 0;

}
/*In cpp within a class we have data members and functions, a constructor initializes the members of a class. It is called when an object is created, they are declared under the public section and do not have a return type, 
outside class syntax:
classname:: classname(..){

}
inside class syntax:
classname(..){

}
Default constructor, Parameterized constructor
Copy constructor syntaxes(3):
Under the class:
demo(demo &dummy//The object from where we are copying stuff){
 data=dummy.data;
}
demo obj1(50);
demo obj2;
obj2=obj1;

demo obj1(50);
demo obj2=obj1;

demo obj1(50);
demo obj2(obj1);

Destructor is used to destruct the objects created by the constructor..when the program ends the objects are destroyed but if objects contain pointers then memory needs to be freed, this is done with the help of a destructor.

It is not parameterized,
~classname(){

}
Shallow copy vs Deep copy



Inheritance.(Private attributes are never inherited. it is only the public and protected attributes that are inherited has it's own attributes as well)
-Single inheritance
-Multiple inheritance
-Multi-Level inheritance
-Hybrid inheritance
-Hierachial inheritance

Data members and member functions
*/