#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#define LEN 10


float convert(char *num,char *src)
{
	float res=0.0f;
	float ff=atof(num);
	if(!strcmp("mile",src)||!strcmp("miles",src))	//ע���Ƚ��ַ�����Ҫ��==����Ҫ��strcmp()����
	{
		res=(ff*1609.344);
		return res;
	}
	else if(!strcmp("yard",src)||!strcmp("yards",src))
	{
		res=ff*0.9144;
		return res;
	}
	else if(!strcmp("inch",src)||!strcmp("inches",src))
	{
		res=ff*0.00254;
		return res;
	}
	else if(!strcmp("foot",src)||!strcmp("feet",src))
	{
		res=ff*0.03048;
		return res;
	}
	else if(!strcmp("fath",src)||!strcmp("faths",src))
	{
		res=ff*1.8288;
		return res;
	}
	else
	{
		res=ff*201.17;
		return res;
	}

}

int main()
{
	char *my_email="1986zf007@163.com";
	char *u="m";
	char *file_name="input.txt";
	ifstream fin;
	fin.open(file_name);
	if(!fin.is_open())
	{
		printf("can not open %s\n",file_name);
		fin.close();
		exit(1);
	}
	ofstream fout("output.txt");
	fout.setf(ios::fixed,ios::floatfield);
	fout.precision(2);
	fout<<my_email<<endl<<endl;
	string line;
	int count=0;
	while(getline(fin,line,'\n'))
	{
		if(count<7)
		{
			count++;
			continue;
		}
		
		if(NULL!=line.c_str())
		{
			char *line_str=new char[80];
			memset(line_str,0,80);
			strcpy(line_str,(char *)line.c_str());
			int i=0;
			char *p[LEN]={NULL};
			char *buf=NULL;
			buf=line_str;
			char *inner_ptr=NULL;
			while((p[i]=strtok_s(buf," ",&inner_ptr))!=NULL)
			{
				i++;
				buf=NULL;
			}
			if(i<=0)
				break;
			
			if(i<=2)
			{
				float sum=0.0f;
				sum=convert(p[0],p[1]);
				fout<<sum<<" "<<u<<endl;
			}
			else 
			{
				float sum=convert(p[0],p[1]);
				
				for(int j=2;p[j]!=NULL;)
				{
					if(!strcmp(p[j],"+")&&isdigit(p[j+1][0]))
					{
						sum+=convert(p[j+1],p[j+2]);
						j++;
					}
					else if(!strcmp(p[j],"-")&&isdigit(p[j+1][0]))
					{
						sum-=convert(p[j+1],p[j+2]);
						j++;
					}
					else
						j++;
				}
				fout<<sum<<" "<<u<<endl;
			}
		}
	}

	fin.close();
	fout.close();
	return 0;
}

		
	
	
