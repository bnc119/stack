#include <stdio.h>
#include <vector>

using namespace std;

template <class T>
class Stack {
  public:

    void push(T data){
      m_vec.push_back(data);
    };

    T pop(){
      if (m_vec.size() > 0 ){
        T retval = m_vec.back();
        m_vec.pop_back();
        return retval;
      }
      else throw "Stack is empty"; 
    };

    int size(){ 
      return m_vec.size();
    };

    void clear(){
      m_vec.clear();
    }
  
  private:
    vector<T> m_vec;
};


// the main test driver for the class
int main(){
  printf("pushing 100 items onto stack...\n");
  int i = 0;
  Stack<int>* stack = new Stack<int>;
  
  while (i < 100 ) {
    stack->push(i);
    i++;
  }
  
  printf("stack has size %d", stack->size());
  i = 0;
  // pop off 101 items, to induce the exception
  try{
    while (i < 101 ) {
      int item = stack->pop();
      printf("popped off %d, (stack size now = %d)\n",item,stack->size());
    } 
  }
  catch (char const* e){
   printf("%s\n\n", e);
  }
  
  return 0;

}
