#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include<fcntl.h>
#include <io.h>

class SaleItem{
private:
int id;
double price;
std::string description;
int quantity;

public:
SaleItem(): id(0),price(0.0), description(""), quantity(1){}
~SaleItem()=default;


bool create(std::string new_desc){
id=rand()%100+1;
description=new_desc;
return true;
}

int getID(){return id;}
std::string getDescription() {return description;}
double getPrice(){return price;}
int getQuantity(){ return quantity;}

void setPrice(double new_price){price=new_price;}
void setQuantity(double new_quantity){quantity=new_quantity;}


void purchase(int new_quantity){
quantity-=new_quantity;}

};

int main(){


std::list<SaleItem> inventory;
std::list<SaleItem>::iterator it;
std::string version="2.0.0.1";
char input_option;
double tax_rate=0.0;

srand(time(NULL));

inventory.clear();
while(1){
system("cls");
std::cout<<"Cupcake POS: "<<version<<std::endl;
std::cout<<std::endl<<std::endl;

std::cout<<"id | price | description | quantity"<<std::endl<<std::endl<<std::endl;
for(it=inventory.begin();it!=inventory.end();it++){
std::cout<<"- "<<it->getID()<<"|"<<it->getPrice()<<"|"<<it->getDescription()<<"|"<<it->getQuantity()<<std::endl;
}

if(inventory.empty()){
std::cout<<"Add your First Cup Cake";
}

std::cout<<std::endl<<std::endl;
std::cout<<"Tax Rate: "<<tax_rate<<"%"<<std::endl;
std::cout<<"======================================"<<std::endl;

std::cout<<"[a]dd new cup-cake"<<std::endl;
std::cout<<"[c]omplete a cupcake purchase"<<std::endl;
std::cout<<"[n]ew tax rate"<<std::endl;
std::cout<<"[u]pdate cupcake qunatity"<<std::endl;
std::cout<<"[q]uit"<<std::endl;

std::cout<<std::endl;

std::cout<<"Input choices: "<<std::endl;
std::cin>>input_option;

if(input_option=='a' || input_option=='A'){
std::string new_description;
double new_price;
int new_quantity;

std::cout<<"Enter cup-cake type:"<<std::endl;
std::cin.clear();
std::cin.ignore();
std::getline(std::cin, new_description);

std::cout<<"set new cupcake price:";
std::cin>>new_price;

std::cout<<"Enter quantity:";
std::cin>>new_quantity;

SaleItem item;
item.create(new_description);
item.setPrice(new_price);
item.setQuantity(new_quantity);
inventory.push_back(item);

}

else if(input_option=='q' || input_option=='Q'){
std::cout<<"Have a Nice Day !!! ";
break;
}

else if(input_option=='c'|| input_option=='C'){
int checkout_id, checkout_qunatity;
double total_amount, total_tax;

std::cout<<"Enter id of cupcake you want to purchase: ";
std::cin>>checkout_id;

for(it=inventory.begin();it!=inventory.end();it++){
if(checkout_id==it->getID()){
std::cout<<"Enter quantity";
std::cin>>checkout_qunatity;

if(checkout_qunatity>it->getQuantity()){
std::cout<<"Sorry, not in stock right now"<<std::endl;
system("pause");
}
else{
it->purchase(checkout_qunatity);

total_amount=checkout_qunatity*it->getPrice();
total_tax=total_amount*(tax_rate*0.01);
std::cout<<"Total Amount: "<<total_amount<<std::endl;
std::cout<<"Amount after tax"<<total_tax<<std::endl;
std::cout<<"Total Sale"<<total_amount+total_tax<<std::endl;
system("pause");

}
break;
}}}

else if(input_option=='n' || input_option=='N'){
std::cout<<"Enter new tax rate: ";
std::cin>>tax_rate;
}

else if(input_option=='u'|| input_option=='U')
{int stock_id;
int stock_qunatity;
std::cout<<"Enter cupcake ID: ";
std::cin>>stock_id;

for(it=inventory.begin();it!=inventory.end();it++){
if(stock_id==it->getID()){
std::cout<<"Enter new Quantity: ";
std::cin>>stock_qunatity;

it->setQuantity(stock_qunatity);
break;
}
}

}


}

return 0;

}
