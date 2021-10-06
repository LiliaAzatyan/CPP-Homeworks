#include <iostream>
#include <iterator>
using namespace  std;

template<class T>
class Vector
{
  template <class L>
  struct Iterator
  {
    friend bool operator==(Iterator a, Iterator b);
    friend bool operator!=(Iterator a, Iterator b);
    using iterator_category =std::random_access_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = L;
    using pointer = L*; 
    using reference = L&;
    Iterator(pointer p)
    {
      this->p = p;
    }
    reference operator*()
    {
      return *p;
    }
    Iterator& operator++()
    {
      p++;
      return *this;
    }
    pointer operator++(L)
    {
      pointer tmp = p;
      p++;
      return tmp;
    }
    Iterator& operator--()
    {
      p--;
      return *this;
    }
    pointer operator--(L)
    {
      pointer tmp = p;
      p--;
      return tmp;
    }
    int& operator[](unsigned int n){
       return p[n]; //*(p+n)
    }
/////// >, < , >=,  <=
    friend bool operator>(Iterator a, Iterator b){
      return (a.p > b.p);
    }
    friend bool operator<(Iterator a, Iterator b){
      return (a.p < b.p);
    }
    friend bool operator<=(Iterator a, Iterator b){
      return (a.p <= b.p);
    }
    friend bool operator>=(Iterator a, Iterator b){
      return (a.p >= b.p);
    }

    friend bool operator==(Iterator a, Iterator b)
    {
      return (a.p == b.p);
    }
    friend bool operator!=(Iterator a, Iterator b)
    {
      return (a.p != b.p);
    }
    private:
    pointer p;
  };

 // Iterator& operator[](int n){
   // return Iterator(arr_[n]);
  //}
public:
Iterator<T> begin()
  {
    return Iterator<T>(&arr_[0]);
  }
  
  Iterator<T> end()
  {
    return Iterator<T>(&arr_[size_]);
  }

  Iterator<T> rbegin()
  {
    return Iterator<T>(&arr_[size_ - 1]);
  }
  
  Iterator<T> rend()
  {
    return Iterator<T>(&arr_[-1]);
  }

  Iterator<const T> cbegin()
  {
    return Iterator<const T>(&arr_[size_ - 1]);
  }
  
  Iterator<const T> cend()
  {
    return Iterator<const T>(&arr_[-1]);
  }



  Vector() : size_(0), capacity_(0), arr_(new T[capacity_]) {}
    Vector(int capacity, T el=T()) : size_(capacity), capacity_(capacity) {
        arr_ = new T[capacity_];
        for(int i = 0; i<size_; ++i)
        {
            arr_[i] = el;
        }
    }
    ~Vector() {delete[] arr_;}
    int size() {return size_;}
    int capacity(){return capacity_;}
    Vector(const Vector<T>& other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = new T[capacity_];
        for(int i = 0; i<size_; ++i)
        {
            arr_[i] = other.arr_[i];
        }
    }
    Vector(Vector<T>&& other)
    {
        size_ = other.size_;
        capacity_= other.capacity_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
    }
    void push_back(const T& el)
    {
        if(size_<capacity_)
        {
            arr_[size_++] = el;
            return;
        }
        if(capacity_ == 0)
        {
            capacity_= 1;
        }
        else
        {
            capacity_ *= 2;
        }
        T* temp = new T[capacity_];
        for(int i = 0; i < size_; ++i)
        {
            temp[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = temp;
        arr_[size_++] = el;
    }
    void pop_back() 
    {
        if(size_ == 0)  
           return;
        size_--;
    }
    T& operator[](int i)
    {
        return arr_[i];  
    }

private:
    int size_;
    int capacity_;
    T* arr_;
};


int main()
{
    
    Vector<int> v(5);
    Vector<int> v1(5, 10);
    Vector<int> v2(v);
    v2.push_back(15);
    v2.push_back(20);
    std::cout<<v2.size()<<" "<<v2.capacity()<<"\n";
    //v2.pop_back();
    std::cout<<v2.size()<<" "<<v2.capacity()<<"\n";

    // cout << v2[5] << endl;
   if(v2[5] < v2[6]){
     cout << "true";
   }
 

  for (auto it = v2.begin(), end = v2.end(); it != end; ++it)
  { 
    const auto i = *it; 
    std::cout << i << "\n";
  }
  cout << "next" << endl;
  for (auto it = v2.rbegin(), start = v2.rend(); it != start; --it){ 
    const auto i = *it; 
    std::cout << i << "\n";
  }
}
