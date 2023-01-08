#include <iostream>
#include <memory>

template<typename T>
class LogDelete{
public:
  void operator()(T *obj){
    std::cout << "Deleting some object!" << std::endl;
    delete obj;
  }
};

template<typename T, class _saveFunc>
class SaveObjectDelete{
public:
  void operator()(T *obj){
    _saveFunc func;
    func(obj);
    delete obj;
  }
  
};

template<typename T>
class CustomSaver{
  public:
    void operator()(T *obj){
      std::cout << "Saving obj: " << *obj << " to file" << std::endl;  
    }
  };

int main(){
  std::unique_ptr<int, LogDelete<int>> a{new int(4)};
  std::unique_ptr<int, SaveObjectDelete<int, CustomSaver<int>>> b{new int(5)};
}