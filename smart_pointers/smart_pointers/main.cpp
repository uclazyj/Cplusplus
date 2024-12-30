//
//  main.cpp
//  smart_pointers
//
//  Created by Yujian Zhao on 12/29/24.
//

#include <iostream>
#include <string>
#include <memory>

class Entity{
public:
    Entity(){
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity(){
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    {
        std::cout << "scope 1:" << std::endl;
        // preferred way
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        // works but not a great way
        std::unique_ptr<Entity> entity2(new Entity());
    }
    {
        std::cout << "scope 2:" << std::endl;
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        {
            std::shared_ptr<Entity> entity2 = entity;
        }
        std::cout << "entity2 has been destroyed!" << std::endl;
    }
}
