//
//  main.cpp
//  smart_pointers
//
//  Created by Yujian Zhao on 12/29/24.
//

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;

class Entity{
public:
    Entity(){
        cout << "Created Entity!" << endl;
    }
    ~Entity(){
        cout << "Destroyed Entity!" << endl;
    }
};

int main(int argc, const char * argv[]) {
    {
        cout << "scope 1:" << endl;
        // preferred way
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        // works but not a great way
        // std::unique_ptr<Entity> entity2(new Entity());
    }
    {
        cout << "scope 2:" << endl;
        std::shared_ptr<Entity> entity = std::make_shared<Entity>();
        {
            std::shared_ptr<Entity> entity2 = entity;
        }
        std::cout << "entity2 has been destroyed!" << std::endl;
    }
    cout << "Program ends!" << endl;
}
