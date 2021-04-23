template <class T>
class myArr
{
public:
	myArr(int capacity)
	{
		this->A_capacity = capacity;
		this->A_size = 0;
		this->pointArr = new T[this->A_capacity];
	}
	myArr(const myArr<T>& arr)				//拷贝构造函数，防止深浅拷贝问题
	{
		this->A_capacity = arr.A_capacity;
		this->A_size = arr.A_size;
		this->pointArr = new T[arr.A_capacity];
		for (int i = 0; i < this->A_size; i++)
		{
			this->pointArr[i] = arr.pointArr[i];
		}
	}
	myArr& operator=(const myArr<T>& arr)		//重载=防止深浅拷贝问题
	{
		if (arr.pointArr != NULL)
		{
			delete[] this->pointArr;
			this->A_capacity = 0;
			this->A_size = 0;
		}
		this->A_capacity = arr.A_capacity;
		this->A_size = arr.A_size;
		this->pointArr = new T[this->capacity];
		for (int i = 0; i < this->A_size; i++)
		{
			this->pointArr[i] = arr->pointArr[i];
		}
	}
	void push_back(const T& arr)
	{
		if (this->A_capacity == this->A_size)
		{
			return;
		}
		this->pointArr[this->A_size] = arr;
		this->A_size++;
	}
	void pop_back()
	{
		if (this->A_size == 0)
		{
			return;
		}
		this->A_size--;
	}
	int size()
	{
		return this->A_size;
	}
	int capacity()
	{
		return this->A_capacity;
	}
	T operator[](int pos)
	{
		return this->pointArr[pos];
	}
	~myArr()
	{
		if (this->pointArr != NULL)
		{
			delete[] this->pointArr;
			this->pointArr = NULL;
			this->A_capacity = 0;
			this->A_size = 0;
		}
	}
private:
	T* pointArr;
	int A_capacity;
	int A_size;
};