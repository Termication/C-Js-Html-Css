#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem{

    private:
        int id;
        std::string description;
        bool completed;

    public:
        TodoItem() : id(0), description(""), completed(false) {}
        ~TodoItem() = default;

        bool create(std::string new_description){
            //generate a random integer between 1 and 100
            id = rand() % 100 + 1;
            description = new_description;
            return true;

        }

        int getId(){return id; }
        std::string getDescription(){return description; }
        bool isCompleted(){return completed; }

};

int main(){
    
    std::string version = "v0.0.2";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    TodoItem test;
    test.create("this is a test");
    todoItems.push_back(test);

    while(1){
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++){
            std::cout << it->getId() << " | " << it->getDescription() << " | " 
              << it->isCompleted() << std::endl;
        }
        break;

    }

}