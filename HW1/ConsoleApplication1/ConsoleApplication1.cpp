// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int score[3];//to store score1 score2 score3
	double avgscore;//the average score of three scores of one student
	int i, j;
	int n = 10;//the number of students is 10
	double average[3];//average of each score
	int min[3], max[3];//the minimum and maximum of each score
    string name;//the name of student

	ifstream File1("score.txt");//open the txt which contains only the name and three scores of each student

	for (i = 0; i < 3; i++)
	{
		average[i] = 0;//initialize the average of each score to be 0, add values and calculate the average
		min[i] = 5;//initialize the minimum score to be 5, and update the value during the compare
		max[i] = 0;//initialize the maximum score to be 0, and update the value during the compare
	}
    cout << "no      name    score1  score2  score3  average" << endl;//the first line of table
	for (i = 0; i < n; i++)
	{
        File1 >> name;//get the name of student
		for (j = 0; j < 3; j++)//get three scores of the current student, add and compare
		{
			File1 >> score[j];
			average[j] = average[j] + score[j];
			if ( score[j] < min[j] ) min[j] = score[j];
			if ( score[j] > max[j] ) max[j] = score[j];

		}
		avgscore = (score[0] + score[1] + score[2]) / 3.0;//the average score of the current student
		cout << setiosflags(ios::left);//the way to justify
		cout <<setw(8)<< 1 + i << setw(8) << name << setw(8)
			<< score[0] << setw(8) << score[1] << setw(8) << score[2] << setw(8) << avgscore << endl;
		//output aline of name, scores and average score
	}
	for (i = 0; i < 3; i++)
	{
		average[i] = average[i] / n;//calculate the average of each kind of scores
	}
	cout << setw(8) << " " << setw(8) << "average" << setw(8) << average[0] << setw(8) << average[1] 
		<< setw(8) << average[2] << endl;//output the average of each kind of scores
	cout << setw(8) << " " << setw(8) << "min" << setw(8) << min[0] << setw(8) << min[1] << setw(8) << min[2] << endl;
	cout << setw(8) << " " << setw(8) << "max" << setw(8) << max[0] << setw(8) << max[1] << setw(8) << max[2] << endl;

	string str;
	cin >> str;// to make sure the exe not closed automatically

    return 0;
}

