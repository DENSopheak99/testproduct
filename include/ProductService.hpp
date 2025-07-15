#pragma one
#include "Product.hpp"
#include <vector>
class ProductService{
    private:
    std::vector<Product> products;

    public:
    void addProduct(const Product& product);
    void getAllProduct() const;
    void getProductById(int id) const;

    bool existById(int id);
    void updateProductById(int id, const std::string &name, double price, int qty);
    void deleteProductById(int id);
    
};