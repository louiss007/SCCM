#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#define LEN 10

/**方法：把运算表达式中的单位统一换算成m,然后再进行加减法运算*/
/*将浮点数转化为char *型数据*/
/*char *ftoa(float res)
{
	int i=0;
	char *dist=new char[30];
	memset(dist,0,30);
	int in=int(res);
	float fl=res-(float)in;
	if(0!=in)
	{
		while(in>0)
		{
			dist[i++]=in%10+'0';
			in /=10;
		}
	}
	else
		dist[i++]=0+'0';
	int j=i-1;
	dist[i++]='.';
	float mid=0.0f;
	while(fl>0.0f)
	{
		mid=fl*10;
		dist[i++]=int(mid)+'0';
		mid -=float(int(mid));
		fl=mid;
	}
	dist[i]='\0';
	char *final_res=new char[30];
	memset(final_res,0,30);
	int k=0;
	for(;j>=0;j--)
	{
		final_res[k++]=dist[j];
	}
	while(dist[k]!='\0')
	{
		final_res[k]=dist[k];
		k++;
	}
	final_res[k]='\0';
	delete dist;
	//delete final_res;
	return final_res;
}*/

/*char* operate(char *p1,char *os, char *p2)
{
	char *res=NULL;
	char *buf1=p1;
	char *buf2=p2;
	char *res1[2];
	char *res2[2];
	char *deli1=NULL;
	char *deli2=NULL;
	int i=0,j=0;
	while((res1[i]=strtok_s(buf1," ",&deli1))!=NULL)
	{
		i++;
		buf1=NULL;
	}
	while((res2[j]=strtok_s(buf2," ",&deli2))!=NULL)
	{
		j++;
		buf2=NULL;
	}
	convert(res1[0],res1[1]);
	convert(res2[0],res2[1]);

	float res_mid=0.0f;
	if(!strcmp(os,"+"))
	{
		res_mid=atof(res1[0])+atof(res2[0]);
		res=strcat(ftoa(res_mid)," m");
		return res;
	}
	if(!strcmp(os,"-"))
	{
		res_mid=atof(res1[0])-atof(res2[0]);
		res=strcat(ftoa(res_mid)," m");
		return res;
	}
}*/

float convert(char *num,char *src)
{
	//char *dist=NULL;
	//float res=0;
	float res=0.0f;
	float ff=atof(num);
	if(!strcmp("mile",src)||!strcmp("miles",src))	//注：比较字符串不要用==，而要用strcmp()函数
	{
		res=(ff*1609.344);
		return res;
		//dist=strcat(ftoa(res)," m");
	}
	else if(!strcmp("yard",src)||!strcmp("yards",src))
	{
		res=ff*0.9144;
		return res;
		//dist=strcat(ftoa(res)," m");
	}
	else if(!strcmp("inch",src)||!strcmp("inches",src))
	{
		res=ff*0.00254;
		return res;
		//dist=strcat(ftoa(res)," m");
	}
	else if(!strcmp("foot",src)||!strcmp("feet",src))
	{
		res=ff*0.03048;
		return res;
		//dist=strcat(ftoa(res)," m");
	}
	else if(!strcmp("fath",src)||!strcmp("faths",src))
	{
		res=ff*1.8288;
		return res;
		//dist=strcat(ftoa(res)," m");
	}
	else
	{
		res=ff*201.17;
		return res;
		//dist=strcat(ftoa(res)," m");
	}
	//return dist;
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
				//printf("%f %s\n",sum,u);
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
				//printf("%f %s\n",sum,u);
				fout<<sum<<" "<<u<<endl;
			}
		}
	}

	fin.close();
	fout.close();
	return 0;
}

		
	
	