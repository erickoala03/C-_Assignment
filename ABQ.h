#include <iostream>
using namespace std;
template <typename T>
class ABQ{

private:
unsigned int capacity; 
unsigned int current = 0;
   float scale_factor = 2.0f;
T* que; 
public:
ABQ(int capacity = 1){
    this->capacity = capacity;
    this->que = new T [capacity];
}

int getMaxCapacity(){
    return capacity;
}

int getSize(){
    return current;
}

~ABQ(){
    delete[] que;
}


T* getData(){
    return que;
}

void enqueue(T data){
if(current == capacity){
           //the copy constrctor 
           // assignment operator
           // destrtor 

           T* new_stack = new T [static_cast<unsigned int> (capacity * scale_factor)];
           for(unsigned int i = 0; i < capacity; i++){
            new_stack[i] = que[i];
           }
           delete[] que;
           que = new_stack; 
           capacity *= scale_factor;
        }

         que[current] = data;
         current++; 
}
 void resize(){
    
      if(current < (capacity / scale_factor)){

        int new_size = capacity/scale_factor;
        T* new_stack = new T[new_size];
        for(unsigned int i = 0; i < current; i++){
            new_stack[i] = que[i];
        }

        delete[] que;
        que = new_stack;
        capacity = new_size; 
       
      }
    }

T dequeue(){
if (current == 0) {
			throw std::runtime_error("An error has occurred.");
		}

T temp = que[0];
for(unsigned int i = 0; i < current - 1; i++){
    que[i] = que[i+1];
}
current--; 
resize();
return temp; 

}


   T peek(){
        //arr->empty() ? return "is empty" : "is not empty"; 
        if(current == 0){
            throw runtime_error("Stack is empty!");
        }
       return que[0];
    }  
};
