#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, std::max_element
using namespace std;

// 1. Function Template: Apply Discount
template<typename T>
T applyDiscount(T price, T discountPercentage) {
    return price - (price * discountPercentage / 100);
}

// 2. Class Template: Shopping Cart
template<typename T>
class ShoppingCart {
    vector<T> items;
public:
    void addItem(const T& item) {
        items.push_back(item);
    }
    void displayItems() {
        cout << "Items in the cart:" << endl;
        for (const auto& item : items) {
            cout << "- ";
            item.display();
        }
    }
    vector<T>& getItems() { return items; } // For accessing items in the cart
};

// 3. Multiple Template Arguments: Item with ID and Price
template<typename Key, typename Value>
class Item {
    Key id;
    Value price;
public:
    Item(Key id, Value price) : id(id), price(price) {}
    void display() const {
        cout << "ID: " << id << ", Price: " << price << endl;
    }
    Value getPrice() const { return price; }
};

// 4. Template Specialization: Fragile Items
template<>
class Item<int, float> {
    int id;
    float price;
    bool fragile;
public:
    Item(int id, float price, bool fragile) : id(id), price(price), fragile(fragile) {}
    Item(int id, float price) : id(id), price(price), fragile(false) {}
    void display() const {
        cout << "ID: " << id << ", Price: " << price;
        cout << (fragile ? " (Fragile Item)" : "") << endl;
    }
    float getPrice() const { return price; }
};

// 5. Default Template Arguments: StandardCart for Prices
template<typename T = float>
class StandardCart {
    vector<T> prices;
public:
    void addPrice(const T& price) {
        prices.push_back(price);
    }
    void displayPrices() {
        cout << "Prices in the cart:" << endl;
        for (const auto& price : prices) {
            cout << price << endl;
        }
    }
};

int main() {
    // 1. Function Template Example
    cout << "Discounted price: " << applyDiscount(100.0, 15.0) << endl;

    // 2. Class Template Example
    ShoppingCart<Item<int, float>> cart;
    cart.addItem(Item<int, float>(101, 499.99)); // Add a regular item
    cart.addItem(Item<int, float>(202, 799.99, true)); // Add a fragile item
    cart.displayItems();

    // 3. Sort Items by Price
    auto& items = cart.getItems();
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.getPrice() < b.getPrice();
    });

    cout << "\nItems sorted by price:" << endl;
    cart.displayItems();

    // 4. Find Most Expensive Item
    auto mostExpensive = max_element(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return a.getPrice() < b.getPrice();
    });
    cout << "\nMost expensive item:" << endl;
    mostExpensive->display();

    // 5. Default Template Arguments Example
    StandardCart<> priceCart;
    priceCart.addPrice(100.0);
    priceCart.addPrice(250.5);
    priceCart.addPrice(499.99);
    priceCart.displayPrices();

    return 0;
}
