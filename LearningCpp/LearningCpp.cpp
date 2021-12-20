#include <iostream>
#include <string>
#include <memory>

// There is virtually no difference between structs and classes, other than default visibility
// A good way to design an API is by its usage, then fill in the blanks
// 
// Static outside a class means the linkage of the symbol defined to be static
// is going to be internal. This applies both for variables and functions.
//
// Static in local scope means the variable has the lifetime of the program,
// but its scope is local.
// 
// std::string has a constructor that takes a const char*
// 
// String literals are stored in read-only memory.
// 
// Prefer allocating on the stack to allocating on the heap
// 
// The new operator both allocates memory and calls the constructor
// 
// The compiler is allowed to perform one implicit conversion on your code
// 
// Unique ptr has lower overhead than shared_ptr
// 
// Can deal with multiple return values with output parameters, or returning
// a struct/array/vector, or return a tuple. Preferred way is to return
// a struct. Actually, with C++17, preferred way is to use tuples and
// structured bindings.
// 
// std::vector is stored on the heap, std::array is stored on the stack
// 
// Avoid multidimensional arrays because of memory fragmentation.
// Convert them into single-dimensional arrays.
// 
// Unions are useful when you want to give two different names to the same
// variable. A union provides different ways for addressing the same memory.
// 
// static_cast, dynamic_cast, reinterpret_cast, const_cast.
// dynamic_cast has a runtime performance cost.
// If dynamic_cast fails, it returns nullptr.
// 
// C++17 has std::optional, std::variant, std::any.
// 
// std::move converts an object into a temporary, returns rvalue reference
// 
// extern means it will look for this variable in an external translation unit
extern int s_Variable;

class Entity {
private:
    int x, y;
    mutable int var;

public:
    static int a;

public:
    // Member initialiser list should be in order the variables are declared
    Entity() : x(0), y(0), var(0) {
    }

    Entity(int x, int y) {
        this->x = x;
        this->y = y;
        this->var = 0;
    }

    Entity(int x) : y(0), var(0) {
        this->x = x;
    }

    // Explicit disables implicit conversion
    explicit Entity(double val) : x(0), y(0), var(0) {

    }

    virtual ~Entity() {

    }

    virtual std::string getName() {
        return "Entity";
    }

    int getX() const {
        this->var = 2;
        return this->x;
    }

    int getX() {
        return this->x;
    }

    void print() {

    }
};

int Entity::a;

void printEntity(const Entity& e) {
    // Const reference can only call const methods
    e.getX();
}

class Player : public Entity {
public:
    std::string getName() override {
        return "Player";
    }
};

class Log {
public:
    Log() = delete;
};

template<typename T>
void print(T value) {
    std::cout << value << std::endl;
}

template<typename T, int N>
class Array {
private:
    T m_array[N];
public:
    int getSize() const { return N; }
};

// std::string&& name is an r-value reference, only accepts r-values
void printName(std::string&& name) {
    std::cout << name << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

    void* ptr = nullptr;

    Entity e;
    Entity e1 = { 5, 8 };
    Entity e2 = Entity(1, 2);
    Entity e3 = 2;

    Entity::a = 1;

    int a[5];
    int count = sizeof(a) / sizeof(int);

    const char* name = "John";

    // The first const means you cannot change the contents of "a".
    // The second const means you cannot reassign the pointer to point to something else.
    const int* const b = new int;
    delete b;

    std::unique_ptr<Entity> entity(new Entity()); // Not preferred
    std::unique_ptr<Entity> entity1 = std::make_unique<Entity>(); // Preferred
    entity->print();
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    std::weak_ptr<Entity> weakEntity = sharedEntity;

    auto c = 5;

    struct Vector2 {
        float x, y;
    };

    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 q, r;
        };
    };

    Entity* player = new Player();
    Player* p = dynamic_cast<Player*>(player);
    if (p) {
        // Cast succeeded
    }

    const int& example = 10;

}