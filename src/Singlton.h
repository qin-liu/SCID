#ifndef _SINGLTON_H_
#define _SINGLTON_H_

template<class TYPE>
class Singleton
{
protected:
	Singleton(void);
public:
	inline static Singleton<TYPE> *&instance_i ();
	static TYPE *instance ();
	static void cleanup ();
protected:
	TYPE instance_;
};

template<class TYPE>
Singleton<TYPE>::Singleton()
{
}

template<class TYPE>
inline Singleton<TYPE>*& Singleton<TYPE>::instance_i()
{
	static Singleton<TYPE>* singleton_ = 0;
	return singleton_;
}

template<class TYPE>
inline TYPE* Singleton<TYPE>::instance()
{
	Singleton<TYPE>*& singleton = Singleton<TYPE>::instance_i();
	if(singleton == NULL)
	{
		singleton = new Singleton<TYPE>();
	}
	return &singleton->instance_;
}

template<class TYPE>
inline void Singleton<TYPE>::cleanup()
{
	Singleton<TYPE>*& singleton = Singleton<TYPE>::instance_i();
	if(singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

#endif