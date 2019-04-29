#include <iostream>
#include <climits> // for INT_MAX limits
#include <iomanip>
#include <vector>
#include "Fraction.h"
#include "Fraction_Util.h"
using namespace std;
extern void lines();
extern void fraction_strips_display();
int main()
{
        char any_key;
        fraction_strips_display();
        cout<<"\n\n";
        int i {}, j{};
        vector <Fraction*> frac_ptr{};
        for(int c {1};c<=2;c++){
            cout<<"Enter the numerator followed by the denominator for the fraction # ["<<c<<"]: \n" ;
            cin>>i>>j;
            try{
                //cout<<i<<", "<<j;
                frac_ptr.push_back(new Fraction{i, j});
                
                cout<<"The fraction you entered is: "<<*frac_ptr.at(c-1)<<" \n";
                cout<<"Decimal value of the fraction: "<<setprecision(2)<<(*frac_ptr.at(c-1)).get_value()<< "\n";
            }
            catch(InvalidArgumentException &e){
                std::cout<<e.what()<<std::endl;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(INT_MAX, '\n'); 
                    cout << "You can only enter numbers \n";
                }
                c--;
            }
        } 
       
        Fraction fraction1 = *frac_ptr.at(0);
        Fraction fraction2 = *frac_ptr.at(1);
        lines();
        cout<<"Now adding the two fractions\n("<<to_string(fraction1)<<") + ("<<to_string(fraction2)<<") = ("<<fraction1+ fraction2<<")\n";
        lines();
        cout<<"Now subtracting the two fractions\n("<<to_string(fraction1)<<") - ("<<to_string(fraction2)<<") = ("<<fraction1 - fraction2<<")\n";
        lines();
        cout<<"Now mulitplying  the two fractions\n("<<to_string(fraction1)<<") x ("<<to_string(fraction2)<<") = ("<<fraction1 * fraction2<<")\n";
        lines();
       
        cout<<"Now dividing fraction#1 by fraction#2\n("<<to_string(fraction1)<<") / ("<<to_string(fraction2)<<")";
        try{
            cout<<"= ("<<fraction1 / fraction2<<")\n";
        }
        catch(InvalidArgumentException &e){
            std::cout<<"\nDivision resulted in a fraction with a 0 valued denominator: \n"<<e.what()<<std::endl;
        }
        lines();
        cout<<"Now comparing fraction#1 to fraction#2\n("<<to_string(fraction1)<<") < ("<<to_string(fraction2)<<"): "<<((fraction1 < fraction2)?"True":"False")<<"\n";
        lines();
        cout<<"Now comparing fraction#1 to fraction#2\n("<<to_string(fraction1)<<") > ("<<to_string(fraction2)<<"): "<<((fraction1 > fraction2)?"True":"False")<<"\n";
        lines();
        cout<<"Now comparing fraction#1 to fraction#2\n("<<to_string(fraction1)<<") == ("<<to_string(fraction2)<<"): "<<((fraction1 == fraction2)?"True":"False")<<"\n";
        lines();
        cout<<"Now comparing fraction#1 to fraction#2\n("<<to_string(fraction1)<<") != ("<<to_string(fraction2)<<"): "<<((fraction1 != fraction2)?"True":"False")<<"\n";
        lines();
        cout<<"Now inverting fraction#1: "<<to_string(fraction1)<<" = ";
        try{
            cout<<fraction1.inverse()<<"\n";      
        }
        catch(InvalidArgumentException &e){
            std::cout<<"\nCould not create the inverse for this fraction: \n"<<e.what()<<std::endl;
        }
        lines();
        cout<<"Now inverting fraction#2: "<<to_string(fraction2)<<" = ";
        try{
             cout<<fraction2.inverse()<<"\n";      
        }
        catch(InvalidArgumentException &e){
            std::cout<<"\nCould not create the inverse for this fraction: \n"<<e.what()<<std::endl;
        }
        lines();
        cout<<"Now assigning fraction#2: "<<to_string(fraction2)<<" to fraction#1: "<<to_string(fraction1)<<"\n";
        fraction1 = fraction2;
        cout<<"The value of fraction#1: "<<fraction1<<"\n\n";
        for (const auto ptr: frac_ptr){
            delete ptr;
        }
        cout<<"Press any key to end: ";
        cin>>any_key;
	return 0;
}
void lines(){
    cout<<"\n=====================================\n";
}
void fraction_strips_display(){
    cout<<"Printing fraction strips...\n";
    cout<<"\n----------------------------------------\n";
    cout<<"[                  1/1                 ]\n----------------------------------------\n";
    cout<<"[       1/2        ][       1/2        ]\n----------------------------------------\n";
    cout<<"[    1/3    ][     1/3    ][    1/3    ]\n----------------------------------------\n";
    cout<<"[   1/4  ][   1/4  ][   1/4  ][   1/4  ]\n----------------------------------------\n";
    cout<<"[  1/5 ][  1/5 ][  1/5 ][  1/5 ][  1/5 ]\n----------------------------------------\n";
    cout<<"[1/6 ][ 1/6 ][ 1/6 ][ 1/6 ][ 1/6 ][ 1/6]\n----------------------------------------\n";
    cout<<"[1/8][1/8][1/8][1/8][1/8][1/8][1/8][1/8]\n----------------------------------------\n";
    
}