#include<bits/stdc++.h>
using namespace std;
const int MAX=15; 
class Modchage{
    public:
    void pshow()
    {
    	cout<<"                     "<<endl;
    	cout<<"                     "<<endl;
    	cout<<"             双人游戏五子棋游戏     "<<endl;
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
class Player{
	
	public: 
		int x,y,red,winround;//最近一次落子信息 
		char name[15];
	Player()
	{
		winround=0;
	}
	void win()
	{
		winround++;
	 } 
	void set(int xx,int yy)
	{
		x=xx,y=yy;
	}
	string red1()
	{
		if(red==0)
		{
			return  "黑";
		}
		else return "白"; 
	}
}; 
class peceinformaion{
	public:
	pieceinformaion(){
			memset(data,0,sizeof(data));
			nowturn = 0;
		}
		int data[MAX][MAX];
	    int nowx,nowy;
	    int nowturn;
	    Player nowplys[2];
	void set1(int x,int y)
	{
		nowx=x,nowy=y;
	}
	void getinfpiece(int g)
	{
		if(g==1)
		cout<<"●";
		else 
		cout<<"○";
	}
		void getinfpiece1(int g)
	{
		if(g==1)
		cout<<"● ";
		else 
		cout<<"○ ";
	}
	void proshow(){
			system("cls");
			cout<<"             双人游戏五子棋游戏     "<<endl;
			cout<<"               当前玩家："<<nowplys[nowturn].name<<endl;
			cout<<"               当前棋色："<<nowplys[nowturn].red1()<<endl;
			cout<<"            "<<endl;
			
	} 
	void show(){
			proshow();
			cout<<"     ";
			for(int i=0;i<MAX;i++)
			{cout<<i+1<<" ";
			 if(i<8)
			 cout<<" ";} 
			cout<<endl;
		for(int i=0;i<MAX;i++){
			if(i+1<10)
			cout<<i+1<<"   ";
		      else
		      cout<<i+1<<"  ";
			for(int j=0;j<MAX;j++){

				if(i==0&&j==0){
				if(!data[i][j])
				cout<<"┏—";
				else
				getinfpiece1(data[i][j]);
				}
			
				else if(j==0&&i==MAX-1){
				if(!data[i][j])
				cout<<"┗—";
				else
				getinfpiece1(data[i][j]);
				}
				
				else if(i==0&&j==MAX-1){
					if(!data[i][j])
						cout<<"┓ ";
				else
				getinfpiece(data[i][j]);
				}
				
				else if(i==MAX-1&&j==MAX-1){
				if(!data[i][j])
						cout<<"┛ ";
				else
				getinfpiece(data[i][j]);
				}
				
				else if(i==0){
				if(!data[i][j])
					 cout<<"┯—";
				else
				getinfpiece1(data[i][j]);
				}

				else if(j==0){
					if(!data[i][j])
						cout<<"┠—";
				else
				getinfpiece1(data[i][j]);
				} 
			
			
				else if(j==MAX-1){
					if(!data[i][j])
					    cout<<"┨ ";
				else
				getinfpiece(data[i][j]);
						if(i==4)
						{
							cout<<"               	Remark: 输入R键：悔棋";
						}
						if(i==5)
						{
							cout<<"               	        输入S键：保存";
						}
						if(i==6)
						{
							cout<<"               	        输入Q键：退出游戏";
						}
						if(i==7){
							cout<<"                        先手VS后手:"<<nowplys[0].winround<<":"<<nowplys[1].winround; 
						} 
				} 
			
				else if(i==MAX-1){
				if(!data[i][j])
			         cout<<"┷—";
				else
				getinfpiece1(data[i][j]);
				}
				
				else{
				if(!data[i][j])
					 cout<<"┼—";
				else
				getinfpiece1(data[i][j]);
				}
				
			}	
			cout<<endl;
		}
		cout<<"        "<<endl;
    	cout<<"请输入您要下的棋子坐标:"<<endl; 
	}

};
class Op:public peceinformaion{ //继承信息类 
	public:
		Op(const Op &a):peceinformaion(a){} 
		Op(){} 
		bool check() //判断是否结束  4个方向 
		{
			int flag=0;    //是否成功 
			int tx=nowx;
			int ty=nowy;   //当前坐标 
			int flag1=nowturn+1; //当前颜色、
			int p=0; 
		while(data[tx][ty]==flag1) // | 
			{
			        p++;
						if(p==5)
					{
						flag=1;
					}
					if(tx>0)
					{
						tx--;
						continue;
					}
					else
						break;
				
		    }
		    p--;
		    tx=nowx;
		 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(tx<14)
					{
						tx++;
						continue;
					}
					else
						break;
			
		    }		                     
			tx=nowx;
			ty=nowy;
			p=0;						 
				while(data[tx][ty]==flag1) // --
			{
			        p++;
						if(p==5)
					{
						flag=1;
						break;
					}
					if(ty>0)
					{
						ty--;
						continue;
					}
					else
						break;
				
		    }
		    p--;	
			ty=nowy;
				 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(ty<14)
					{
						ty++;
						continue;
					}
					else
						break;
			
		    }					       
		    tx=nowx;
			ty=nowy;
			p=0;						 
				while(data[tx][ty]==flag1) // 向右斜杠 
			{
			        p++;
						if(p==5)
					{
						flag=1;
						break;
					}
					if(ty>0&&tx>0)
					{
						ty--;
						tx--;
						continue;
					}
					else
						break;
				
		    }
		    p--;	
			ty=nowy;
			tx=nowx;
				 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(ty<14&&tx<14)
					{
						ty++;
						tx++;
						continue;
					}
					else
						break;
			
		    }		    
		    tx=nowx;
			ty=nowy;
			p=0;						 
				while(data[tx][ty]==flag1) // 向左斜杠 
			{
			        p++;
						if(p==5)
					{
						flag=1;
						break;
					}
					if(ty<14&&tx>0)
					{
						ty++;
						tx--;
						continue;
					}
					else
						break;		
		    }
		    p--;	
			ty=nowy;
			tx=nowx;
				 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(ty>0&&tx<14)
					{
						ty--;
						tx++;
						continue;
					}
					else
						break;
			
		    }	
		    if(flag)
		        return true; 
		        else
		        return false;
		}
		void retunpi() //悔棋 
		{	
		    nowturn^=1;
			data[nowplys[nowturn].x][nowplys[nowturn].y]=0;
			show();
		}
		void putpi(int x,int y)//下棋  1黑 2白 
		{
			data[x-1][y-1]=nowturn+1;
		    nowplys[nowturn].set(x-1,y-1);
		    set1(x-1,y-1); 
			show();	
		  if(check())
		{
		
		    nowplys[nowturn].win(); 	
			show();
			cout<<endl;
			cout<<nowplys[nowturn].name<<":获得游戏胜利"<<endl;
			cout<<"输入任意键开始新游戏"<<endl;
			int t=getchar();
			t=getchar();
		    memset(data,0,sizeof(data)); 
		    nowturn=0;
		    show();
		 }	
		else{
			 nowturn^=1; //切换 0代表玩家1 1代表玩家2 
			 show();
			}
		} 
}newstart,restart;
int main()

{	

  test.pshow(); 
  test.selectshow();
  int time;
  cin>>time;
  if(time==1){
  	system("cls");
  	newstart.nowturn=0;
  	cout<<"请输入玩家1(默认先手)的名字:";
  	cin>>newstart.nowplys[0].name;
  	newstart.nowplys[0].red=0;
  	cout<<endl;
  	cout<<"请输入玩家2(默认后手)的名字:";
  	cin>>newstart.nowplys[1].name;
  	getchar();
  	newstart.nowplys[1].red=1;
  	cout<<"    "; 
  	newstart.show();
  }
  else if(time==2)
  {
        std::ifstream fin("Savepiece", std::ios_base::in | std::ios_base::app | std::ios_base::binary); 
        fin.read((char*)&newstart, sizeof(Op));
        newstart.show();	
 
  }
  else
     return 0;
  	while(1)   //开始下棋 
  	{
  		string ch;
  		int x=0,y=0;
  		cin>>ch;
  		if(ch=="R")
  		{   
  		    newstart.retunpi();
  			continue;
		  }
		  else if(ch=="Q")
		  {
		  	return 0;
		  }
		  else if(ch=="S")
		  {
		    std::ofstream fout("Savepiece", std::ios_base::out | std::ios_base::binary);
		    fout.write((char*)&newstart, sizeof(Op));
			int ppp=getchar();
			cout<<"保存完毕，按任意键继续"<<endl; 
			ppp=getchar();
			fout.close();
			restart=newstart;
			restart.show(); 
			continue;
	      }
		  else
		  {
		  	
		  	if(ch.length()==2)
		  	{
		  		x=ch[1]-'0'+(ch[0]-'0')*10;
			  }
			  else
			     x=ch[0]-'0';
		  	  cin>>y;
		if(0<x&&x<=15&&y>0&&y<=15&&newstart.data[x-1][y-1]==0){
			   newstart.putpi(x,y);
		  }
		  else{
		  	cout<<"请重新输入"<<endl;
		  	int ppp=getchar();
			continue; 
		  }
  	
	  }
}
	return 0;
}
