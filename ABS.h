#include <iostream>
using namespace std;

template <typename T> 
class ABS{

    private:
    T *arr;
    unsigned int hold = 0;
    unsigned int max;
   float scale_factor = 2.0f;

    public:
    ABS(unsigned int max = 1){
        this->arr = new T [max];
        this->max = max;
    }
    unsigned int getSize(){
        return hold;
    }
    unsigned int getMaxCapacity(){
        return max;
    }
    
    void resize(){
    
      if(hold < (max / scale_factor)){

        int new_size = max/scale_factor;
        T* new_stack = new T[new_size];
        for(unsigned int i = 0; i < hold; i++){
            new_stack[i] = arr[i];
        }

        delete[] arr;
        arr = new_stack;
        max = new_size; 
       
      }
    }

    void push(T data){
      
       
        if(hold == max){
           //the copy constrctor 
           // assignment operator
           // destrtor 

           T* new_stack = new T [static_cast<unsigned int> (max * scale_factor)];
           for(unsigned int i = 0; i < max; i++){
            new_stack[i] = arr[i];
           }
           delete[] arr;
           arr = new_stack; 
           max *= scale_factor;
        }

         arr[hold] = data;
         hold++; 
    }

    T pop(){

        if(hold == 0){
            throw runtime_error("Stack is empty!");
        }

        T pop_item = arr[hold - 1];
        arr[hold - 1 ] = 0;
        hold--;
        resize();
        return pop_item;
    }
      
            

    T peek(){
        //arr->empty() ? return "is empty" : "is not empty"; 
        if(hold == 0){
            throw runtime_error("Stack is empty!");
        }
       return arr[hold - 1];
    }
    
    T* getData(){
        return arr;
    } 

    ~ABS(){
        delete []arr;
    }
};