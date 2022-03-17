/*
author:Carson
begin-time:2020-10-4
finish-time:2020-10-10   
*/
#include<bits/stdc++.h>
#include<windows.h>
#include <conio.h>
using namespace std;
const int MAXT=20; 
char*  color[]={"白色","黑色"}; 
int 	dir[8][2]={-1,-1,-1,0,-1,1, 0,-1 , 0,1, 1,-1, 1,0 ,1,1};
class Modchage{
    public:
    void pshow()
    {
    	cout<<"                     "<<endl;
    	cout<<"                     "<<endl;
    	cout<<"             	 翻转棋游戏     "<<endl;
    	cout<<"                1.开始新游戏"<<endl;
    	cout<<"                2.读取棋谱"<<endl; 
    	cout<<"                3.离开游戏"<<endl;
	}
	void selectshow()
	{
		cout<<"                         "<<endl; 
		cout<<"请输入对应的模式(1/2/3) :";
	}
}test;

class peceinformaion{
	public:
	pieceinformaion(){
			memset(data,0,sizeof(data));
		}
		int data[MAXT][MAXT];
		int culdata[MAXT][MAXT]; //估值表 
		int expect[MAXT][MAXT];   // 某位置转换棋子数目 
		int MAX;
		int gx,gy; 
	    int startturn ;//0 为后手 ，1 为先手 
	void reset()
	{
		memset(data,0,sizeof(data));
		data[MAX/2-1][MAX/2-1]=1;
		data[MAX/2-1][MAX/2]=2;
		data[MAX/2][MAX/2-1]=2;
		data[MAX/2][MAX/2]=1;
		for(int i=2;i<MAX-4;i++)
			{
			for(int j=2;j<MAX-4;j++)
				culdata[i][j]=1;
				culdata[0][i]=10;
				culdata[i][0]=10;
				culdata[MAX-1][i]=10;
				culdata[i][MAX-1]=10;
				culdata[1][i]=5;
				culdata[i][1]=5;
				culdata[MAX-2][i]=5;
				culdata[i][MAX-2]=5;
				}
		culdata[0][0]=culdata[0][MAX-1]=culdata[MAX-1][MAX-1]=culdata[MAX-1][0]=90;
		culdata[0][1]=culdata[0][MAX-2]=culdata[1][0]=culdata[1][MAX-1]=-60;
		culdata[MAX-2][0]=culdata[MAX-1][1]=culdata[MAX-1][MAX-2]=culdata[MAX-2][MAX-1]=-60;
	}
	void set2(int x,int y)
	{
			gx=x;
			gy=y;
	}
	int coloshow(char* s1,char* s2) //s1 ：对话框名字，s2:内容  1为确定，0为取消 
	{
	    if(MessageBox(NULL,s1,s2,MB_OKCANCEL)==1)
	    {
	    	return 1;
		}
		else  return 0;
	}
	void getinfpiece(int g)
	{
		if(g==1)
		cout<<"●";
		else if(g==2)
		cout<<"○";
	}
	void getinfpiece1(int ii,int jj,int g)
	{
		if(g==1)
		{cout<<"●";
			if(gx==ii&&gy==jj+1)
			{
				cout<<"";
			}
			else if(gx==ii&&gy==jj)
				cout<<"";
			else
			cout<<" ";
		}
		else if(g==2){
		cout<<"○";
			if(gx==ii&&gy==jj+1)
			{
				cout<<"";
			}	
			else if(gx==ii&&gy==jj)
				cout<<"";
			else
			cout<<" ";
		}
	}
	
	void show(){
	    	cout<<"             您当前的棋色为："<<color[startturn]<<endl; 
	    	cout<<endl;
			cout<<"     "<<endl;
			cout<<"     ";
			for(int i=0;i<MAX;i++)
			{cout<<i+1<<" ";
			 if(i<8)
			 cout<<" ";} 
			cout<<endl;
		for(int i=0;i<MAX;i++){
			
			if(i+1<10)
			cout<<i+1<<"  ";
		      else
		      cout<<i+1<<" ";
		      	if(gx==i&&gy==0)
					{
						cout<<"[";
					}
				else
				cout<<" ";
		      
			for(int j=0;j<MAX;j++){

				if(i==gx&&j==gy&&j!=0)
				{
					if(!data[i][j-1])
					cout<<" ";
					cout<<"[";
				}
				if(i==gx&&j==gy+1)
				{
					if(!data[i][j-1])
					cout<<" ";
					cout<<"]";
				}
				if(i==0&&j==0){
						if(!data[i][j]){
					 cout<<"┏";
					 if(i==gx&&j==gy-1)
					 cout<<"";
					 else if(i==gx&&j==gy)
					 cout<<"";
					 else
					 cout<<"—";}
				else
				getinfpiece1(i,j,data[i][j]);
				}
			
				else if(j==0&&i==MAX-1){
						if(!data[i][j]){
					 cout<<"┗";
					 if(i==gx&&j==gy-1)
					 cout<<"";
					 else if(i==gx&&j==gy)
					 cout<<"";
					 else
					 cout<<"—";}
				else
				getinfpiece1(i,j,data[i][j]);
				}
				
				else if(i==0&&j==MAX-1){
					if(!data[i][j]){
						cout<<"┓ ";	
						if(gx==i&&gy==MAX-1)
					{
						cout<<"]";
					}
					}
				else
				getinfpiece(data[i][j]);
				}
				
				else if(i==MAX-1&&j==MAX-1){
	             	if(!data[i][j]){
						cout<<"┛ ";	
						if(gx==i&&gy==MAX-1)
					{
						cout<<"]";
					}}
				else
				getinfpiece(data[i][j]);
				}
				
				else if(i==0){
				if(!data[i][j]){
					 cout<<"┯";
					 if(i==gx&&j==gy-1)
					 cout<<"";
					 else if(i==gx&&j==gy)
					 cout<<"";
					 else
					 cout<<"—";}
				else
				getinfpiece1(i,j,data[i][j]);
				}

				else if(j==0){
					if(!data[i][j]){
					 cout<<"┠";
					 if(i==gx&&j==gy-1)
					 cout<<"";
					 else if(i==gx&&j==gy)
					 cout<<"";
					 else
					 cout<<"—";}
				else
				getinfpiece1(i,j,data[i][j]);
				} 
			
			
				else if(j==MAX-1){
						if(!data[i][j]){
						cout<<"┨ ";	
						if(gx==i&&gy==MAX-1)
					{
						cout<<"]";
					}
					}	
				else
				getinfpiece(data[i][j]);
				} 
				else if(i==MAX-1){	
				if(!data[i][j]){
					 cout<<"┷";
					 if(i==gx&&j==gy-1)
					 cout<<"";
					 else if(i==gx&&j==gy)
					 cout<<"";
					 else
					 cout<<"—";}
				else
				getinfpiece1(i,j,data[i][j]);
				}
				
				else{
				if(!data[i][j]){
					 cout<<"┼";
					 if(i==gx&&j==gy-1)
					 cout<<"";
					 else if(i==gx&&j==gy)
					 cout<<"";
					 else
					 cout<<"—";}
				else
				getinfpiece1(i,j,data[i][j]);
				}
				
			}
						if(i==2)
						{
							cout<<"               	        按下S键：保存";
							
						
						}
						if(i==1)
						{
							cout<<"               	    按下Space键：下棋"; 
						}
						if(i==3)
						{
							cout<<"               	        按下Q键：退出游戏";
						}
							
			cout<<endl;
			
		}
	}

}; 

class Op:public peceinformaion{ //继承信息类 
	public:
		Op(const Op &a):peceinformaion(a){} 
		Op(){} 
		int obound(int tx,int ty) // 判断是否越界 越界返回1 
		{
			if(tx<0||tx>=MAX||ty<0||ty>=MAX)
					return 1;
				else return 0;
		 } 
		int chage(int data1[MAXT][MAXT],int p,int og,int tx,int ty)  //翻转 og=1 翻转， 为 0 计数 
		{
			int num=0; 
			int rp=0;
			int flag=0;
			if(p==1)
				rp=2;
			else if(p==2)
				rp=1;
				
			for(int i=0;i<8;i++) 
			{
				int ggx=tx+dir[i][0]; 
				int ggy=ty+dir[i][1];
				flag=0;
				if(obound(ggx,ggy))
					continue;
				while(data1[ggx][ggy]==rp)
				{
					flag=1;
					ggx=ggx+dir[i][0];
					ggy=ggy+dir[i][1];
					if(obound(ggx,ggy)) //到边界 
					{
						flag=0;
						break;
					}
				}
				if((!flag)||data1[ggx][ggy]!=p)	continue;
				else
				{
						int gggx=tx;
						int gggy=ty;
						while((gggx!=ggx)||(gggy!=ggy))
						{
							if(data1[gggx][gggy]!=p)
							num++;
							if(og==1)
							data1[gggx][gggy]=p; 
							gggx=gggx+dir[i][0];
							gggy=gggy+dir[i][1];
						}
				}
			}
			return num;
		}
		void putpi(int p)//下棋  1黑 2白 
		{
			if(data[gx][gy])
				return;
			data[gx][gy]=p;
		    chage(data,p,1,gx,gy); 
		    system("cls");
			show();
		}
		
		void respond(int t){
			if(t==72)
			{
				if(gx>0)
				gx--;
				else
				gx=MAX-1;
				system("cls");
				show();
			}else if(t==75)
			{
				if(gy>0)
				gy--;
				else
				gy=MAX-1;
				system("cls");
				show();
			}
			else if(t==77)
			{
				int flag1=gy;
				if(gy<MAX-1)
				gy++;
				else
				gy=0;
				system("cls");
				show();
			}
			else if(t==80)
			{
				int flag1=gx;
				if(gx<MAX-1)
				gx++;
				else 
				gx=0;
				system("cls");
				show();
			}
		} 
		
		
		
//2020-10-6
void copymap(int one[MAXT][MAXT], int last[MAXT][MAXT])						//拷贝地图
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			one[i][j] = last[i][j];
}

void Reex(int p) // 1 hei 2 bai
		{
			for(int i=0;i < MAX; i++)
				for(int j=0; j<MAX;j++){
					if(data[i][j])	
						expect[i][j]=0;
					else
						expect[i][j]=chage(data,p,0,i,j);
				} 
		 } 
		 
int difai(int x,int y,int mapnow[MAXT][MAXT],int expectnow[MAXT][MAXT],int depin,int depinmax,int p)						//极大极小搜索
{
	int pp;
	if(p==1)
	{
		pp=2;
	 } 
	 else pp=1;
	if (depin >= depinmax)return 0;											//递归出口

	int maxx = -10005;														//最大权值
	pair<int,int> NOW;
	int expectnow2[MAXT][MAXT] , mapnow2[MAXT][MAXT],mapnext[MAXT][MAXT],expectlast[MAXT][MAXT];					//定义临时数组

	copymap(mapnow2, mapnow);												//复制当前棋盘

	mapnow2[x][y] = p;									//模拟在当前棋盘上下棋
	int ME = culdata[x][y] + expectnow[x][y];							//当前棋子权
	NOW=make_pair(x,y);
	chage(mapnow2,p,1,NOW.first,NOW.second);											//改变棋盘AI结束

	int MAXEXPECT = 0, LINEEXPECT = 0, COUNT = 0;
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
		{
			expectnow2[i][j] = chage(mapnow2,pp,0,i,j);				//预判对方是否可以走棋
			if (expectnow2[i][j])
			{
				++MAXEXPECT;
				if ((i == 0 && j == 0) || (i == 0 && j == MAX - 1) || (i == MAX - 1 && j == MAX - 1) || (i == MAX - 1 && j == 0))return -1800;	//如果对方有占角的可能
				if ((i < 2 && j < 2) || (i < 2 && MAX - j - 1 < 2) || (MAX - 1 - i < 2 && j < 2) || (MAX - 1 - i < 2 && MAX - 1 - j < 2))++LINEEXPECT;
			}
		}
	if (LINEEXPECT * 10 > MAXEXPECT * 7)return 1400;						//如果对方走到坏点状态较多 剪枝

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (expectnow2[i][j])											//如果对方可以走棋
			{
				int YOU = culdata[i][j] + expectnow2[i][j];			//当前权值
				copymap(mapnext, mapnow2);									//拷贝地图
				mapnext[i][j] = pp;						//模拟对方走棋
				NOW=make_pair(x,y);								
				chage(mapnext,p,1,NOW.first,NOW.second);	//改变棋盘
				for (int k = 0; k < MAX; k++)
					for (int l = 0; l < MAX; l++)
						expectlast[k][l] =  chage(mapnext,p,0,k,l);	//寻找AI可行点

				for (int k = 0; k < MAX; k++)
					for (int l = 0; l < MAX;l++)
						if (expectlast[k][l])
						{
							int nowm = ME - YOU + difai(k, l, mapnext, expectlast, depin + 1, depinmax,p);
							maxx = maxx < nowm ? nowm : maxx;
						}
			}
	return maxx;
}
 
 
pair<int,int> Maxprice(int p)									//人机对战困难AI
{
	pair<int,int> d2(0,0); 
	int maxx = -10005;
	int flagp=0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			if (expect[i][j]) //expect 翻转的数目  
			{
				if ((i == 0 && j == 0) || (i == 0 && j == MAX - 1) || (i == MAX - 1 && j == MAX - 1) || (i == MAX - 1 && j == 0))
				{
					d2.first=i,d2.second=j;
					return d2;										//如果在角，返回角坐标
				}
				int k = difai(i,j,data,expect,0,2,p);					//递归搜索 搜索1层  //mapp的棋盘 
				if (k >= maxx)
				{
					flagp=1;
					maxx = k;
					d2.first=i,d2.second=j;
				}
			}
		}
	if(flagp==0)
	{
	   for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			int g=culdata[i][j];
			if(!data[i][j]&&g>maxx)
			{
				maxx = g;
				d2.first=i,d2.second=j;
					}
	     }
     }
	return d2;
}

void autoput(int p)// 1黑 2白 
		{  
			Reex(p); 
			pair<int,int> dd;
			dd=Maxprice(p);
		    gx=dd.first,gy=dd.second; 
			data[gx][gy]=p;
			chage(data,p,1,gx,gy);  
			Sleep(400);
		    system("cls");
			show();	
		}
		int check1(){				//判断游戏结束 
			
				for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				{
					if(!data[i][j])
						return false;	
				}
		}
		return true;
		}
		
		
		
		int check()   //判断胜负 
		{
			int flagr=0,flagw=0;
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				{
					if(data[i][j]==1)
						flagr++;
					else
						flagw++;	
				}
			}
			if(flagr==flagw)
			{
				return coloshow("You lose! Once game？","Game over");
			}
			else if(flagr>flagw)
			{
				if(startturn){
					//nin ying le
					return coloshow("You win! Once game？","Game over");
				}
				else {
					return coloshow("You lose! Once game？","Game over");
				}// ni shu le
			}
			else
			{
					if(startturn){
						return coloshow("You lose! Once game？","Game over");
					//nin shu le
				}
				else {
						return coloshow("You win! Once game？","Game over");
				}// ni ying le
			}
		 } 
		 
}newstart,restart;
int main()
{	

  B:system("cls"); 
  test.pshow(); 
   test.selectshow();
   int time;	
  cin>>time;
  if(time==1){
  A:system("cls");
  cout<<"请选择棋盘的规格：默认为N*N(N>=6)"<<endl;
  	cout<<"N为：";
  	cin>>newstart.MAX;
	newstart.reset();
  	system("cls");   
	newstart.startturn=newstart.coloshow("您为先手","选择下子优先权");
	newstart.set2(0,0);
    if(!newstart.startturn)//后手 
	{
		newstart.autoput(1);
		system("cls");   	
	}
    newstart.show();
  }
  
  else if(time==2)
  {
  		system("cls"); 
        std::ifstream fin("Savepiece", std::ios_base::in | std::ios_base::app | std::ios_base::binary); 
        fin.read((char*)&newstart, sizeof(Op));
        newstart.show();	
 
  }
  else
     	return 0;
    
	int ch=0;
	while(1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            if(ch==81)
             goto B; 
            if(ch==32)
			{
				int flag=0;
				if(newstart.startturn==1)
				   flag=1;
				else flag=2;
			newstart.putpi(flag);//玩家下
			
		  if(newstart.startturn==1)//电脑下
				   flag=2;
				else flag=1;
						
			newstart.autoput(flag);	
		
		if(newstart.check1())
       	{	
       	if(newstart.check())
       	{
       		goto A;
		   }
		   else
		   		 goto B; 
		   }			 
			}
			
			if(ch==83)
			{
			std::ofstream fout("Savepiece", std::ios_base::out | std::ios_base::binary);
		    fout.write((char*)&newstart, sizeof(Op));
			int ppp=getchar();
	    	int flagt=-1;
			if(MessageBox(NULL,"保存成功，是否继续游戏？","通知",MB_OKCANCEL)==1){
				flagt=1;
			}
			else flagt=0;
			fout.close();
			if(flagt){
			restart=newstart;
			system("cls"); 
			restart.show(); 
			continue;}
			else
				 goto B; 
			 } 
            if(isascii(ch))
			 newstart.respond(ch); 
            }
     
	}
	return 0;
} 
