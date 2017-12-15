#include <mutex>

#ifndef MCV
#define MCV

using namespace std;

template <typename T> 
class mcv{
	mutex change_value;
	T variable;
public:
	mcv(){};
	T get(T value = 0){
		change_value.lock();
		return variable;
		change_value.unlock();
	}
	T set(T value){
		change_value.lock();
		variable = value;
		change_value.unlock();
		return 0;
	}
	mcv <T> operator + (mcv sum){
		return variable + sum;
	}
	T exchange(mcv <T> name,T (*method)(), T value){
		 
	}
};

#endif
