#include <iostream>
#include <string>
#include <list>

class TodoItem{

    private:
        int id;
        std::string description;
        bool completed;

    public:
        TodoItem() : id(0), description(""), completed(false) {}
        ~TodoItem() = default;


};

int main(){
    
    std::string version = "v0.0.2";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    todoItems.clear();

    while(1){
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++){
            std::cout << it->getId() << " | " << it->getDescription() << " | " 
              << it->isCompleted() << std::endl;
        }

    }

}