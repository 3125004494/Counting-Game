#include<stdio.h>

int operate(int j,char operation);
char reverse(char operation);

int main()
{
    int n[10]=0, m[10]=0,k[10]=0;
    //n表示总人数，m表示标号为m的玩家，k表示m玩家拍掌的次数（拍掌触发条件：报到的数包含数字7或7的倍数）
    int player[101]=0;//player数组表示玩家的报数情况，player[j]表示玩家j报的数值
    int num=1,count=0;//num表示当前报数的数值，count表示m玩家拍掌的次数
    int j=1;//j表示当前报数的玩家编号
    char operation='+';
    printf("请输入不超过10组数据，每组数据包含n、m、k三个整数，输入0 0 0结束：\n");
    printf("输入约束：2<=n<=100,1<=m<=n,1<=k<=100\n");
    for(int i =0;i<10;i++)
    {
        //2<=n<=100,1<=m<=n,1<=k<=100
        scanf("%d%d%d",&n[i],&m[i],&k[i]);
        if(n[i]==0&&m[i]==0&&k[i]==0)
        {
            break;
        } 
        //输入数据不合法，请重新输入
        if(n[i]<2||n[i]>100||m[i]<1||m[i]>n[i]||k[i]<1||k[i]>100)
        {
            printf("输入数据不合法，请重新输入：\n");
            n[i]=0;m[i]=0;k[i]=0;
            i--;
            continue;
        }  
    }
    for(int i=0;i<10||(n[i]!=0||m[i]!=0||k[i]!=0);i++)
    {
        num=1;//num表示当前报数的数值
        count=0;//count表示m玩家拍掌的次数
        j=1;//j表示当前报数的玩家编号
        operation='-';
        //operation表示当前报数的方向，'+'表示顺着编号报数，'-'表示逆着编号报数
       while(count!=k[i]){

            if(j==n[i]||j==1)
            {
                operation=reverse(operation);
            }

            player[j]=num;
            printf("玩家%d报数%d\n",j,num);

            if(j==m[i])
            {
                if(num%7==0)
                {
                    count++;
                }
                else
                {
                  for(int x=num;x>0;x/=10)
                  {
                      if(x%10==7)
                      {
                          count++;
                          break;
                      }
                  }
                }
            }

            j=operate(j,operation);
            num++;
       }
    }
    return 0;
}

int operate(int j,char operation)
{
    if(operation=='+')
    {
        return j+1;
    }
    else if(operation=='-')
    {
        return j-1;
    }
}

char reverse(char operation)
{
    if(operation=='+')
    {
        return '-';
    }
    else if(operation=='-')
    {
        return '+';
    }
}