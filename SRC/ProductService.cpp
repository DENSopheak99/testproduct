#include "ProductService.hpp"
#include <iomanip>
#include <iostream>


void ProductService::addProduct(const Product& product) {
    products.push_back(product);
}

void ProductService::getAllProduct() const {
    std::cout << std::left
               << std::setw(6) << "ID"
               << std::setw(25) << "Name"
               << std::setw(15) << "Price"
               << std::setw(10) << "Qty" << std::endl;
    for (const auto& p : products){
        std::cout << std::left
                   << std::setw(6) << p.getID()
                   << std::setw(25) << p.getName()
                   << std::setw(15) << p.getPrice()
                   << std::setw(10) << p.getQty() << std::endl;
    }
}
void ProductService::getProductById(int id) const{
    std::cout << "====| Product detail |====" << std::endl;
    for (auto it = products.begin(); it != products.end(); it++){
        if(it->getID() == id){
            std::cout << "Product id:" << it->getID() << std::endl;
            std::cout << "Product name:" << it->getName() << std::endl;
            std::cout << "Product price:" << it->getPrice() << std::endl;
            std::cout << "Product qty:" << it->getQty() << std::endl;
            }
    }
}
void ProductService::deleteProductById(int id) {
    for (auto it = products.begin(); it != products.end(); it++){
        if (it->getID() == id){
            products.erase(it);
            break;
        }
    }   
}
void ProductService::updateProductById(int id, const std::string& name, double price, int qty)
{
    for (auto it = products.begin(); it != products.end(); it++){
        if (it ->getID() == id){
            it->setName(name);
            it->setPrice(price);
            it->setQty(qty);
        }
    }
}
bool ProductService::existById(int id){
    for (auto it = products.begin(); it != products.end(); it++){
        if(it->getID() == id){
            return true;
            break;
        }
    }
    return false;
}