//
//  singletonClass.h
//  AnEraser
//
//  Created by LeeWonJoo on 2015. 4. 22..
//
//

#ifndef __AnEraser__SingletonClass__
#define __AnEraser__SingletonClass__

#include <cocos2d.h>

using namespace std;

template<typename T> class SingletonClass
{
public:
    static T* getInstance()
    {
        if (0 == mInstance)
        {
            if (0 == mInstance)
            {
                mInstance = new T();
            }
        }
        return mInstance;
    }
    
    virtual ~SingletonClass(){}
protected:
    SingletonClass(void){}
    
    SingletonClass(const SingletonClass&)
    {
    }
    
    SingletonClass& operator = (const SingletonClass&)
    {
        return *this;
    }
    
protected:
    static T* mInstance;
};

template<typename T> T* SingletonClass<T>::mInstance = 0;


#endif /* defined(__AnEraser__singletonClass__) */
