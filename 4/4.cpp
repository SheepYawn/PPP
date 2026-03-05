module _4;

int area(int length, int width)
{
	return length * width;
}

int framed_area(int x, int y)
{
	return area(x - 2, y - 2);
}

void test(int x, int y, int z)
{
	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1) / (area3);
	cout << "ratio == " << ratio;
}

//运行时错误
void e4_5()
{
	test(-1, 2, 3);	//area3会等于0
}

int area4_5(int length, int width)
{
	if (length <= 0 || width <= 0)
		return -1;
	return length * width;
}

//返回错误信息
void e4_5_t(int x, int y, int z)
{

}