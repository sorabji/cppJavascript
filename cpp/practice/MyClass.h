#ifndef MYCLASS_H
#define MYCLASS_H

class TheOtherClass{
};

template<class T> class MyClass{
 private:

  T attr;

 public:

  T getAttr(){
    return attr;
  }

  T setAttr(T attr){
    this->attr = attr;
  }
};
#endif
