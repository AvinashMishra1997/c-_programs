#include "iostream"
using namespace std;

class matrix_summer
{
private:
	int a[10][10],b[10][10],c[10][10],row_size,sum,column_size,row,col;
public:
	void take_input_for_matrix_1();
	void take_input_for_matrix_2();
	void matrix_sum();

};

void matrix_summer::take_input_for_matrix_1()
{
	cout<<"Enter matrix size (i.e no. of row , no. of column): ";
	cin>>row_size>>column_size;
	if(row_size==column_size)
	{
		for(row=0;row<row_size;row++)
		{
			for(col=0;col<column_size;col++)
			{
					cout<<"Enter values of 1st matrix (e.g: matrix[row_value][column_value]) : ";
					cin>>a[row][col];
				
			};
		};
	}
	else
	{
		cout<<"ERROR: ONLY MATRICES WITH SAME DIMENSIONS CAN BE ADDED";
	}
}

void matrix_summer::take_input_for_matrix_2()
{
	cout<<"Enter matrix size (i.e no. of row , no. of column): ";
	cin>>row_size>>column_size;
	if(row_size==column_size)
	{
		for(row=0;row<row_size;row++)
		{
			for(col=0;col<column_size;col++)
			{
					cout<<"Enter values of 2nd matrix (e.g: matrix[row_value][column_value]) : ";
					cin>>b[row][col];	
			};
		};
	}
		else
		{
			cout<<"ERROR: ONLY MATRICES WITH SAME DIMENSIONS CAN BE ADDED";
		}
}

void matrix_summer::matrix_sum()
{
	sum=c[row][col];
	cout<<"The required matrix is:\n";
	for(row=0;row<row_size;row++)
	{
		for(col=0;col<column_size;col++)
		{
			sum=a[row][col]+b[row][col];
			cout<<sum;
			cout<<"\t";
		
		};
		cout<<"\n";
	};
}

int main()
{
	matrix_summer m1;
	m1.take_input_for_matrix_1();
	m1.take_input_for_matrix_2();
	m1.matrix_sum();
	
}