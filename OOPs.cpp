#include <bits/stdc++.h>
using namespace std;
/* Oops: Class (public/private) */
/* Every program must have a constructor, If we don't create one the compiler adds a default constructor to the class we create like 
class xyz{
    int data;
    public:
  xyz(int a){
    data=a;
  }
  When an object is created in main like xyz obj1(55)-->The above constructor is called, but when xyz obj2; with no parameter is created it will result in an error as the compiler does not create a default constructor when we define one ourselves so to fix this write an extra empty constructor within the class.
};
There are two types of constructors parameterized and non-parameterized 

The simple operators need to as well be defined within the class itself, this comes under operator overloading 
*/
class student{
    //public:
    string name;
    public:
    int age;
    bool gender;

    student(){
        cout<<"Default constructor"<<endl;
    }

    student(string s, int a, bool g){
        name=s;
        age=a;
        gender=g;
        cout<<"Parameterized constructor"<<endl;
    }

    student (student &a){
        name=a.name;
        age=a.age;
        gender=a.gender;
        cout<<"Default Copy constructor"<<endl;
    }

    void setname(string s){
        name=s;
    }//This is not a constructor. It is an ordinary function 

    ~student(){
       cout<<"Destructor called"<<endl;
 }//The destructor is called as many a times as the no. of constructors called before retuen 0.

 bool operator == (student &a){//There is a differnce in the output based on the '&'
    if(name==a.name && age==a.age && gender== a.gender){
       return true;
    }
    else return false;
 }

    void printinfo(){
        cout<<"Name= ";
        cout<<name<<endl;
        cout<<"Age= ";
        cout<<age<<endl;
        cout<<"Gender= ";
        cout<<gender<<endl;

    }

};
int main(){
    /*student a;
    a.name='Nikki';
    a.age=20;
    a.gender=0;*/
  student a[5];
    for(int i=0;i<5;i++){
        string s;
    cout<<"Name= ";
    //cin>>a[i].name;
    cin>>s;
    cout<<"Age= ";
    cin>>a[i].age;
    cout<<"Gender= ";
    cin>>a[i].gender;
}
for(int i=0;i<5;i++){
    a[i].printinfo();
}
student a("Urvi",10,0);
student b;
student c=a;
if(c==a){
    cout<<"same"<<endl;
}
else{
    cout<<"Not same"<<endl;
}

   return 0;
} 
