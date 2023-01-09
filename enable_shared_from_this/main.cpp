#include <iostream>
#include <memory>

class DangerousShared {
public:
  int a = 69;

  std::shared_ptr<DangerousShared> get_shared() {
    return std::shared_ptr<DangerousShared>(this);
  }
};

class SafeShared : public std::enable_shared_from_this<SafeShared>{
public:
  int a = 1337;

  std::shared_ptr<SafeShared> get_shared(){
    return shared_from_this();  
  }  
};

int main() {
  
  auto dangerous_example = std::make_shared<DangerousShared>();
  auto m = dangerous_example->get_shared();
  {
    auto p = dangerous_example->get_shared();
    std::cout << p->a << std::endl;
  }

  std::cout << m->a << std::endl; // ERROR: dead pointer
  //ERROR: double memory free
  

  /*
  auto safe_example = std::shared_ptr<SafeShared>(new SafeShared);
  auto m = safe_example->get_shared();
  {
    auto p = safe_example->get_shared();
    std::cout << p->a << std::endl;
  }

  std::cout << m->a << std::endl;
  */
}
