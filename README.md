# Online Shopping Application Using Binary Search Tree (BST)

## 1. Project Overview
This is a menu-driven C++ mini-project that demonstrates how a Binary Search Tree (BST) can be used to organize products according to their prices. Each product is stored in a tree node, and the product price is used as the key for arranging the nodes.

The main purpose of the project is to display products whose prices fall within a range entered by the user. It also includes basic product-management operations so that the working of a BST can be understood through a simple console application.

## 2. Aim
To develop an online-shopping-style product application using a Binary Search Tree, where product prices are used as keys and all products within a specified price range can be displayed.

## 3. Objectives
- Understand the structure and basic operations of a Binary Search Tree.
- Store product names and prices in individual tree nodes.
- Insert products according to their prices.
- Display products in ascending order of price.
- Search for a product using its price.
- Find and display products within a user-defined minimum and maximum price range.
- Delete a product using its price.
- Practise pointers, structures, recursion, and dynamic memory management in C++.

## 4. Data Structure Used: Binary Search Tree
A Binary Search Tree is a hierarchical data structure in which each node can have a left child and a right child. In this project, every node stores:

- `price` — the product price and the BST key.
- `product` — the product name.
- `left` — a pointer to the left child node.
- `right` — a pointer to the right child node.

For insertion, a price smaller than the current node's price is placed in the left subtree. An equal or greater price is placed in the right subtree. This arrangement helps the program search for prices and display products in sorted order.

## 5. Main Features
1. **Add products:** Enter product names and prices to insert them into the BST.
2. **Display all products:** Use inorder traversal to list products in ascending order of price.
3. **Search by price:** Check whether a product with the entered price exists.
4. **Search within a price range:** Enter a minimum and maximum price to display matching products, including products exactly at either limit.
5. **Delete a product:** Remove a product using its price while maintaining the BST structure.
6. **Exit:** Leave the menu-driven program. The tree's allocated memory is released before the program finishes.

## 6. Software Requirements
- **Programming language:** C++
- **Compiler:** Any compiler that supports C++11 or later, such as GCC/G++
- **Editor or IDE:** Visual Studio Code, Code::Blocks, Dev-C++, or an online C++ compiler such as OnlineGDB
- **Operating system:** Windows, Linux, or another environment with a compatible C++ compiler

## 7. How to Compile and Run
Save the source file as `main.cpp` and open a terminal in the folder containing it.

Compile the program using:

```bash
g++ main.cpp -o shopping
```

On Linux or macOS, run it with:

```bash
./shopping
```

On Windows, run the generated executable, usually `shopping.exe`. If you are using an online compiler, paste the contents of `main.cpp` into its editor and select **Run**.

## 8. Example Use
First add a few products with different prices. Then choose the option to search within a price range and enter the required minimum and maximum values. For example, if the stored products include Mouse — Rs. 500, Charger — Rs. 700, Keyboard — Rs. 1200, and Headphones — Rs. 1800, searching from Rs. 600 to Rs. 1500 should show Charger and Keyboard.

The file `sample-output.txt` contains a sample console run to help understand the menu and expected interaction. The actual output depends on the products and choices entered by the user.

## 9. Files in This Repository
- `main.cpp` — complete C++ source code for the application.
- `sample-output.txt` — example console output.
- `STEP-BY-STEP-EXPLANATION.md` — a beginner-friendly explanation of the program's main parts.
- `VIVA-QUESTIONS.md` — questions and answers for project preparation and viva practice.
- `README.md` — project overview, features, requirements, and instructions for compiling and running the program.

## 10. Learning Outcomes
After completing this project, a student should be able to explain how nodes are linked in a BST, how insertion and searching use price comparisons, how inorder traversal displays values in sorted order, and how a range search selects products between two limits. The project also provides practice with C++ structures, pointers, recursion, functions, and dynamic memory allocation.

## 11. Scope and Limitations
This project is a console-based educational demonstration of product management using a BST. It is not a complete commercial shopping website and does not include user accounts, a shopping cart, online payments, inventory databases, or delivery services. Product names are entered as single words to keep input handling simple. If multiple products have the same price, searching or deleting by price may select one matching node.

## 12. Conclusion
The project demonstrates a practical use of a Binary Search Tree by organizing products using price as the key. It provides a simple way to insert, display, search, filter by price range, and delete products while reinforcing important C++ and data-structure concepts.
