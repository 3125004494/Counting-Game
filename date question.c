#include<stdio.h>

void check(int y,int m,int d);
int date[3][3]={0};
int i=0;
int main()
{
	int a,b,c;
	long long t;
	long long d[3];
	scanf("%d/%d/%d",&a,&b,&c);
	check(a,b,c);
	check(c,a,b);
	check(c,b,a);
	for(int j=0;j<i;j++){
		d[j]=date[j][0]*10000+date[j][1]*100+date[j][2];
	}
	for(int j=0;j<i;j++){
		for(int k=0;k<2-j;k++){
			if(d[k]>d[k+1]){
				t=d[k];
				d[k]=d[k+1];
				d[k+1]=t;
			}
		}
	}
	if(d[0]==d[1]&&d[1]==d[2]){
		i=1;
	}
	for(int j=0;j<i-1;j++){
		if(d[j]==d[j+1]){
			for(int k=j;k<i;k++){
				d[k]=d[k+1];
			}
			i--;
		}
	}
	for(int j=0;j<i;j++){
		a=d[j]/10000;
		b=d[j]%10000/100;
		c=d[j]%100;
		printf("%d-%02d-%02d\n",a,b,c);
	}
	return 0;
}

void check(int y,int m,int d)
{
	int monthdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(y>=60){
		y+=1900;
	}
	else{
		y+=2000;
	}
	if(y%400==0||(y%4==0&&y%100!=0)){
		monthdays[1]=29;
	}
	if(m>12){
		return;
	}
	else if(d>monthdays[m-1]){
		return;
	}
	else{
		date[i][0]=y;
		date[i][1]=m;
		date[i][2]=d;
		i++;
	}
}
