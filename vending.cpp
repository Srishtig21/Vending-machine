#include "model.h"
#include<bits/stdc++.h>
using namespace std;

vector<Product> products={
    Product(1,"Lays",20,5),
    Product(2,"Kurkure",20,5),
    Product(3,"Nestle coffee",60,5),
    Product(4,"Rice Craker",10,5),
    Product(5,"5Star - 3D",30,5),
    Product(6,"Kitkat",30,5),
    Product(7,"Gatorade",70,5),
    Product(8,"Litchi juice",20,5),
    Product(9,"Pringles",90,5)
};

string showallproducts() {
    string s;
    for (auto i : products) {
        s += i.displayname();
    }
    return s;
}
Product* chooseproduct() {
    cout<< " Available Products : \n"<<showallproducts();
    cout<<" Select the number of the Product :";
    int choice;
    cin>>choice;
    if(choice>products.size()){
        cout<<"Product not found!";
        return NULL;
    }
    return &products[choice-1];
}

bool Checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total=cart.getTotal();
    cout<<"Please pay a total of Rs. "<<total;
    int cash;
    cin>>cash;
    if(cash>=total){
        cout<<"Change -- Rs. "<<cash-total<<"\n";
        cout<<"Thankyou for shopping :) \n";
        return true;
    }else{
        cout<<"Insuficient Cash";
        return false;
    }
}
int main(){
    int action;
    Cart cart;
    while(true){
        cout<<"(1) Add Item\n"<<"(2) View Cart\n"<<"(3) Checkout\n";
        cin>>action;

        if(action==1){
            Product* p = chooseproduct();
            if (p != NULL) {
                cart.addproduct(*p);
            }
        }
        
        if(action==2){
            string s=cart.viewcart();
            cout<<s;
        }

        if(action==3){
            if(Checkout(cart)){
                break;
            }
        }
    }
}
