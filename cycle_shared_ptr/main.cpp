#include <iostream>
#include <memory>

class ExampleClass{
public:
  int a = 5;
  ~ExampleClass(){
    std::cout << "Deleted ExampleClass" << std::endl;
  }
};

class CycleExample{
public:
  std::shared_ptr<CycleExample> another;  
  ~CycleExample(){
    std::cout << "Deleted CycleExample" << std::endl;
  }
};


class CycleExample2{
public:
  std::weak_ptr<CycleExample2> another;  
  ~CycleExample2(){
    std::cout << "Deleted CycleExample2" << std::endl;
  }
};

int main(){
  std::shared_ptr<ExampleClass> fptr;
  {
    std::shared_ptr<ExampleClass> ptr = std::make_shared<ExampleClass>();
    std::cout << ptr->a << std::endl;
    {
      std::shared_ptr<ExampleClass> another_ptr = ptr;
      std::cout << "Use count: "<< another_ptr.use_count() << std::endl;;
    }
    //Uncomment to demonstrate shared_ptr feature
    //fptr = ptr;
  }
  auto f = std::make_shared<CycleExample>();
  auto s = std::make_shared<CycleExample>();
  f->another = s;
  s->another = f;
  //No destructor will call because of cycle pointing
  //Comment one to see destructors will call
  //Use weak_ptr to fix problem

  auto f2 = std::make_shared<CycleExample2>();
  auto s2 = std::make_shared<CycleExample2>();
  f->another = s;
  s->another = f;
    std::cout << "Other code here" << std::endl;
  return 0;
}
