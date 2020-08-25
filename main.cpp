//p4:ADT Bag Array Implementation
//Rowan Briggs
//May 11 - May 13, 2018
/* Description:
=== WRITE and TEST the Functions below:

    void most_expensive ( ) (shows the most expensive item)
    void show_reverse ( ) (shows everything in the bag in reverse order of showItems() )
    void get_frequency (Item item) (show how many times an Item (the name) appears in the bag)
    bool delete_item (Item item) (delete 1 item (based on the name), shift array elements to the left, return true if successful
    int get_index_of (Item item) (returns the index of an item (based on the name) )
    double sum_of_all ( ) (returns the sum of all Items)
 */
#include <iostream>
using namespace std;

class Item{
    private:
        string name;
        double cost;

    public:
        Item(){
            name = "";
            cost = 0.0;
        }

        Item(string newName, double newCost){
            name = newName;
            cost = newCost;
        }

        void show(){
            cout << "- " << name << " $" << cost << endl;
        }

        string get_name(){
            return name;
        }

        double get_cost() {
            return cost;
        }

        void set_item(string newName, double newCost){
            name = newName;
            cost = newCost;
        }

        void setItem(Item item){
            name = item.get_name();
            cost = item.get_cost();
        }
};

class Bag{
    private:
        Item *items;
        int number_items;
        int max;

    public:
        Bag(int Max){
            items = new Item[Max]; // an array of items
            number_items = 0; //this is the index of current item
            max = Max; //size of the bag/array
        }

        void insert_item(string name, double cost){
            items[number_items].set_item(name,cost);
            number_items++;
        }

        void insertItem(Item item){
            //items[number_items].set_item(item.get_name(),item.get_cost() );
            items[number_items].setItem(item);
            number_items++;
        }

        int size() {
            return max;
        }

        void showItems(){
            for (int i = 0; i < number_items; i++){
                items[i].show();
            }
        }

        void most_expensive(){
            double expensive;
            string name;
            for (int i = 0; i <number_items - 1; i++){
                if (i == 0){
                    //sets the initial cost equal to the first item's cost
                    expensive = items[i].get_cost();
                    name = items[i].get_name();
                }
                if (expensive < items[i].get_cost()){
                    //compares the prices of each item to the first item, if it is larger, it is swapped
                    expensive = items[i].get_cost();
                    name = items[i].get_name();
                }
            }

            cout << "The most expensive item is " << name << " for " << expensive << "\n";
        }

        void delete_first(){
            //shift all the elements one to the left
            for(int i = 0; i <  max-1; i++){
                items[i] = items[i+1];
            }
            number_items--;
        }

        bool delete_item(Item item){
            //gets the name of the item we are looking for
            string name = item.get_name();
            int initial = number_items;
            for (int i = 0; i < number_items-1; i++){
                //checks each element of the array to see if it is the item we are looking for
                if(items[i].get_name() == name){
                    for(int j = i; j < number_items-1; j++){
                        items[j]=items[j+1];
                    }
                    number_items--;
                }
            }
            if(initial > number_items){
                //returns true if the array is smaller after the above loop
                return true;
            }
            else {
                return false;
            }
        }

        bool contains (string name_to_find){
            for (int i = 0; i < number_items; i++){
                if (name_to_find == items[i].get_name()){
                    return true;
                }
                return false;
            }
        }

        void sort_by_cost_ascending(){
            for (int i = 0; i < number_items-1; i++){
                for (int j = 0; j < number_items-1; j++){
                    if (items[j].get_cost() > items[j+1].get_cost()){
                        swap(j,j+1);
                    }
                }
            }
        }

        int get_index_of(Item item){
            int location = 0;
            for (int i = 0; i < number_items; i++){
                if (items[i].get_name()==item.get_name()){
                    //if the name is the name we are looking for, we then get that index
                    location = i;
                }
            }
            cout << "The index of " << item.get_name() << " is " << location;
        }

        void get_frequency(Item item){
            int count=0;
            for(int i = 0; i < number_items; i++){
                //if the item name is the name we are looking for, then we count it
                if ((items[i].get_name() == item.get_name())) {
                    count++;
                }
            }
            cout << "The item " << item.get_name() << " appears " << count << " times.\n";
        }

        void swap(int index1, int index2){
            Item temp = items[index1];
            items[index1] = items[index2];
            items[index2] = temp;
        }

        void show_reverse(){
            //flips array around in reverse
            for (int i = 0; i < number_items/2; i++){
                Item temp = items[i];
                items[i] = items[number_items-1-i];
                items[number_items-1-i] = temp;
            }
            //returns the array in reverse order
            cout << "\nIn reverse order, your items are: \n";
            for (int i = 0; i < number_items; i++){
                items[i].show();
            }
            //puts array back in order for future use
            for (int i = 0; i < number_items/2; i++){
                Item temp = items[i];
                items[i] = items[number_items-1-i];
                items[number_items-1-i] = temp;
            }
        }

        double sum_of_all(){
            double cost = 0;
            for (int i = 0; i < number_items; i++){
                //constantly increases the cost as it goes through the bag
                cost = cost + items[i].get_cost();
            }
            cout << "\nThe total cost of your items is: " << cost;
        }
};

int main() {
    Bag aBag(5);
    cout << "Testing Item: ";
    Item anItem("Fuji Apple", 4.99);
    anItem.show();
    //shows the item

    aBag.insertItem(anItem);
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //adds the item to the bag

    Item secondItem("Banana", 1.99);
    aBag.insertItem(secondItem);
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //should return 2 items

    aBag.delete_first(); //erases the first item
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //shouuld be only one item

    aBag.insert_item("Granny Smith Apples", 3.99);
    Item anotherItem("Candy", 1.49);
    aBag.insertItem(anotherItem);
    Item thirdItem("Grapes", 2.99);
    aBag.insertItem(thirdItem);
    aBag.insert_item("Raisin", 2.99);
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //should show 5 items

    aBag.delete_item(anotherItem);
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //should show 4 items

    aBag.most_expensive();
    aBag.show_reverse();
    aBag.delete_first();
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //shows 3 items

    aBag.insertItem(thirdItem);
    cout << "In your bag, you have: \n";
    aBag.showItems();
    //shows 4 items, 2 grapes

    aBag.get_frequency(thirdItem);
    //returns how many times grapes is in the bag

    Item fourthItem("Oranges", 1.99);
    aBag.insertItem(fourthItem);
    cout << "In your bag, you have: \n";
    aBag.showItems();
    aBag.get_index_of(fourthItem);
    //shows the index of orange (4)

    aBag.sum_of_all();
    //should show cost (close to $15)
}
/* Output:
Testing Item: - Fuji Apple $4.99
In your bag, you have:
- Fuji Apple $4.99
In your bag, you have:
- Fuji Apple $4.99
- Banana $1.99
In your bag, you have:
- Banana $1.99
In your bag, you have:
- Banana $1.99
- Granny Smith Apples $3.99
- Candy $1.49
- Grapes $2.99
- Raisin $2.99
In your bag, you have:
- Banana $1.99
- Granny Smith Apples $3.99
- Grapes $2.99
- Raisin $2.99
The most expensive item is Granny Smith Apples for 3.99

In reverse order, your items are:
- Raisin $2.99
- Grapes $2.99
- Granny Smith Apples $3.99
- Banana $1.99
In your bag, you have:
- Granny Smith Apples $3.99
- Grapes $2.99
- Raisin $2.99
In your bag, you have:
- Granny Smith Apples $3.99
- Grapes $2.99
- Raisin $2.99
- Grapes $2.99
The item Grapes appears 2 times.
In your bag, you have:
- Granny Smith Apples $3.99
- Grapes $2.99
- Raisin $2.99
- Grapes $2.99
- Oranges $1.99
The index of Oranges is 4
The total cost of your items is: 14.95
Process finished with exit code 0
 */