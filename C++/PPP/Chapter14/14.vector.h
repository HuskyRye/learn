class vector {
	/*
	不变式：
	若 0 <= n < sz，elem[n] 为编号为 n 的元素
	sz <= space
	若 sz < space，则在 elem[sz-1] 之后能容纳 (space-sz) 个 double 的空间
	*/
	int sz;
	double* elem;
	int space;
public:
	vector() : sz { 0 }, elem { nullptr }, space { 0 } {}
	explicit vector(int s) : sz { s }, elem { new double[s] }, space { s }
	{
		for (int i = 0; i < sz; ++i)
			elem[i] = 0;
	}

	vector(const vector&);
	vector& operator=(const vector&);

	vector(vector&&);
	vector& operator=(vector&&);
	~vector() { delete[] elem; }

	double& operator[](int n) { return elem[n]; }
	const double& operator[](int n) const { return elem[n]; }

	int size() const { return sz; }
	int capacity() const { return space; }

	void resize(int newsize);
	void push_back(double d);
	void reserve(int newalloc);
};