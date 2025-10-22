#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  //below says to make helper functinos prviate?
  //void heapify(size_t);

private:
  /// Add whatever helper functions and data members you need below
  PComparator comparator_;
  std::vector<T> store_;
  int x_;
  void heapify(size_t);



};

// Add implementation of member functions here

template <typename T,typename PComparator> Heap<T,PComparator>::Heap(int x,PComparator comperator){
  comparator_=comperator;
  x_=x;
}
template <typename T,typename PComparator> Heap<T,PComparator>::~Heap(){
  //nothing needed?
}
template <typename T, typename PComparator> void Heap<T,PComparator>::push(const T& item){
  store_.push_back(item);
  //size_t par=(store_.size()-1)/x_;
  size_t itemLocation=store_.size()-1;
  size_t par=(itemLocation-1)/x_;
  while (itemLocation>0&& comparator_(store_[itemLocation],store_[par])){
    //swap
    T tempy1=store_[itemLocation];
    T tempy2=store_[par];
    store_[itemLocation]=tempy2;
    store_[par]=tempy1;

    itemLocation=par;
    par=(itemLocation-1)/x_;
  }
}
template <typename T,typename PComparator> bool Heap<T,PComparator>::empty() const{
  return (store_.empty());
}
template <typename T,typename PComparator> size_t Heap<T,PComparator>::size() const{
  return (store_.size());
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    //got this from another file that asks same thing
    throw(std::underflow_error("heap is empty"));


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return store_[0];



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("heap is empty"));


  }
  //1 thing in store only
  if(store_.size()==1){
    store_.pop_back();
    return;
  }

  //heapify(0);

  //swap and then delete the last (root after swap)
  T tempyFirst =store_[0];
  T tempyLast = store_[store_.size()-1];
  store_[0]=tempyLast;
  store_[store_.size()-1]=tempyFirst;
  store_.pop_back();
  heapify(0);
}
template <typename T,typename PComparator> void Heap<T,PComparator>::heapify(size_t val){
  if((x_*val+1)>=store_.size()){//or do i do val>=0
    return;
  }
  size_t low=x_*val+1; // doing +1 since assumign root at 0
  //doing +2 to add an extra 1 since assuming root at 0 instead of 1
  size_t end=x_*val+x_;
  if((end)>=store_.size()){
    end=store_.size()-1;
  }
  //if((end)>=store_.size()){
    //end=store_.size()-1;
    for(size_t i=low+1;i<=end;i++){
      if(comparator_(store_[i],store_[low])){
        //
        low=i;
      }
    }
  //}
  if(comparator_(store_[low],store_[val])){
    T tempyFirst=store_[val];
    T tempyLast=store_[low];
    store_[val]=tempyLast;
    store_[low]=tempyFirst;
    heapify(low);

  }
} 

#endif

