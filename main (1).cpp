#include <iostream>
#include <string>
using namespace std;

struct Node {
    int price;
    string product;
    Node *left, *right;
};

Node* insert(Node* root, int price, string product) {
    if (root == NULL)
        return new Node{price, product, NULL, NULL};

    if (price < root->price)
        root->left = insert(root->left, price, product);
    else
        root->right = insert(root->right, price, product);

    return root;
}

void displayProducts(Node* root) {
    if (root == NULL) return;
    displayProducts(root->left);
    cout << root->product << " - Rs. " << root->price << endl;
    displayProducts(root->right);
}

void searchRange(Node* root, int low, int high) {
    if (root == NULL) return;

    if (root->price > low)
        searchRange(root->left, low, high);

    if (root->price >= low && root->price <= high)
        cout << root->product << " - Rs. " << root->price << endl;

    if (root->price < high)
        searchRange(root->right, low, high);
}

bool searchProduct(Node* root, int price) {
    if (root == NULL) return false;
    if (root->price == price) {
        cout << "Product found: " << root->product
             << " - Rs. " << root->price << endl;
        return true;
    }
    if (price < root->price)
        return searchProduct(root->left, price);
    return searchProduct(root->right, price);
}

Node* findMinimum(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteProduct(Node* root, int price) {
    if (root == NULL) return NULL;

    if (price < root->price)
        root->left = deleteProduct(root->left, price);
    else if (price > root->price)
        root->right = deleteProduct(root->right, price);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMinimum(root->right);
        root->price = temp->price;
        root->product = temp->product;
        root->right = deleteProduct(root->right, temp->price);
    }
    return root;
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = NULL;
    int choice, n, price, low, high;
    string product;

    do {
        cout << "\n===== ONLINE SHOPPING PRODUCT MENU =====\n";
        cout << "1. Add products\n";
        cout << "2. Display all products by price\n";
        cout << "3. Search product by price\n";
        cout << "4. Display products in price range\n";
        cout << "5. Delete product by price\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "How many products do you want to add? ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter product name (one word) and price: ";
                cin >> product >> price;
                root = insert(root, price, product);
            }
            break;

        case 2:
            if (root == NULL)
                cout << "No products available.\n";
            else {
                cout << "\nAll products (lowest to highest price):\n";
                displayProducts(root);
            }
            break;

        case 3:
            cout << "Enter price to search: ";
            cin >> price;
            if (!searchProduct(root, price))
                cout << "No product found at that price.\n";
            break;

        case 4:
            cout << "Enter minimum and maximum price: ";
            cin >> low >> high;
            if (low > high)
                cout << "Invalid price range.\n";
            else {
                cout << "\nProducts in price range:\n";
                searchRange(root, low, high);
            }
            break;

        case 5:
            cout << "Enter price of product to delete: ";
            cin >> price;
            if (!searchProduct(root, price))
                cout << "No product found to delete.\n";
            else {
                root = deleteProduct(root, price);
                cout << "Product deleted.\n";
            }
            break;

        case 6:
            cout << "Thank you for using the application.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    freeTree(root);
    return 0;
}
