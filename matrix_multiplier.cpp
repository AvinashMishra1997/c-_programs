#include <iostream>
using namespace std;

class matrix
{
	int a[10][10],b[10][10],d[10][10],r1,c1,r2,c2,r,c,rc1,rc2,cc1,cc2,k;

public:
	void input();
	void display();
	void multiply();

};

void matrix::input()
{
	cout<<"enter maximum no. of rows and column for matrix 1: ";
	cin>>rc1>>cc1;
	for (r1=0;r1<rc1;r1++)
	{
		for (c1=0;c1<cc1;c1++)
		{
			cout<<"enter elements of matrix 1: ";
			cin>>a[r1][c1];

		}
	}

	cout<<"enter maximum no. of rows and column of matrix 2: ";
	cin>>rc2>>cc2;
	for (r2=0;r2<rc2;r2++)
	{
		for (c2=0;c2<cc2;c2++)
		{
			cout<<"enter elements of matrix 2: ";
			cin>>b[r2][c2];
			
		}
	}
}


void matrix::multiply()
{
	for (r=0;r<rc1;r++)
	{
		for (c=0;c<cc2;c++)
		{
			d[r][c]=0;
			for (k=0;k<cc2;k++)
			{
				d[r][c]=d[r][c]+a[r][k]*b[k][c];
			}
		}
	}
}

void matrix::display()
{
	for (r1=0;r1<rc1;r1++)
	{
		for (c1=0;c1<cc1;c1++)
		{
			cout<<a[r1][c1]<<"\t";

		}
		cout<<"\n";
	}

	cout<<"\n\n\n";

	for (r2=0;r2<rc2;r2++)
	{
		for (c2=0;c2<cc2;c2++)
		{
			cout<<b[r2][c2]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"\n\n\n";

	for (r=0;r<rc1;r++)
	{
		for (c=0;c<cc2;c++)
		{
			cout<<d[r][c]<<"\t";
		}
		cout<<"\n";
	}
}


int main()
{
	matrix m;
	m.input();
	m.multiply();
	m.display();
	return 0;
}









